#version 330 core

out vec4 FragColor;

struct Light {
    int lightType;
    //vec4 lightVector; //W==0.0 => directional light, w=1.0 => light's position
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float distance; //-1.0 => 0 attenuation, !=0.0 => dist to no light (aprox)

    mat4 lightSpaceMatrix;
    int castshadow;
    int shadowIndex;
};

in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec4 FragPosLightSpace;
} fs_in;

uniform vec4 color;
uniform vec3 viewPos;
uniform int shininess = 32; //pow of 2

#define MAX_LIGHTS 8
#define MAX_SHADOWS 4
uniform Light lights[MAX_LIGHTS];
uniform sampler2D shadowMaps[MAX_SHADOWS];
uniform int numLights;

float gamma = 0.5;
int PCFSize = 1;
int nbSample = (1 + 2 * PCFSize) * (1 + 2 * PCFSize);

float ShadowCalculation(vec4 fragPosLightSpace, sampler2D shadowMap, vec3 normal, vec3 lightDir) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    if (projCoords.z > 1.0)
        return 0.0;
    float currentDepth = projCoords.z;
    float bias = max(0.005 * (1.0 - dot(normal, lightDir)), 0.005);
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for (int x = -PCFSize; x <= PCFSize; ++x) {
        for (int y = -PCFSize; y <= PCFSize; ++y) {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= nbSample;

    vec2 distanceFromEdge;
    distanceFromEdge.x = min(projCoords.x, 1.0 - projCoords.x);
    distanceFromEdge.y = min(projCoords.y, 1.0 - projCoords.y);
    float distToEdge = min(distanceFromEdge.x, distanceFromEdge.y) * 10.0;
    float fadeout = clamp(distToEdge, 0.0, 1.0);
    shadow *= fadeout;
    return shadow;
}

vec3 computeLight(Light l, vec3 norm, vec3 FragPos, vec4 color, vec3 lightDir, vec3 viewPos, vec3 viewDir, float shadow) {
    vec3 result = vec3(0.0, 0.0, 0.0);
    vec3 reflectDir = reflect(-lightDir, norm);

    result += max(dot(norm, lightDir), 0.0) * l.diffuse;
    result += pow(max(dot(viewDir, reflectDir), 0.0), shininess) * l.specular;
    result *= 1.0 - shadow;
    result += l.ambient;

    if (l.distance != -1.0) {
        float d = length(l.position - FragPos);
        float attenuation = 1.0 / (1.0 + (5.0 / l.distance) * d + (75.0 / (l.distance * l.distance)) * (d * d));
        result *= attenuation;
    }

    return result * color.rgb;
}

void main() {
    vec3 result = vec3(0.0);
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    if (dot(viewDir, fs_in.Normal) < 0.0)
        discard;

    for (int i = 0; i < numLights; ++i) {
        float shadow = 0.0;
        vec3 lightDir = vec3(0.0, 0.0, 0.0);

        if (lights[i].lightType == 1) {
            lightDir = normalize(lights[i].position - fs_in.FragPos);
        }
        else if (lights[i].lightType == 0) {
            lightDir = normalize(lights[i].direction);
        }

        if ((lights[i].castshadow != 0) && (lights[i].shadowIndex >= 0)) {
            vec4 fragPosLightSpace = lights[i].lightSpaceMatrix * vec4(fs_in.FragPos, 1.0);
            shadow = ShadowCalculation(fragPosLightSpace, shadowMaps[lights[i].shadowIndex], fs_in.Normal, lightDir);
        }

        result += computeLight(lights[i], fs_in.Normal, fs_in.FragPos, color, lightDir, viewPos, viewDir, shadow);
    }
    FragColor = vec4(result*gamma, color.a);
}