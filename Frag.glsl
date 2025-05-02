#version 330 core

out vec4 FragColor;

struct Light {
    vec4 lightVector; //W==0.0 => directional light, w=1.0 => light's position

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float distance; //-1.0 => 0 attenuation, !=0.0 => dist to no light (aprox)
};

in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec4 FragPosLightSpace;
} fs_in;

uniform vec4 color;
uniform vec3 viewPos;
uniform Light light;
uniform int shininess = 32; //pow of 2

uniform sampler2D shadowMap;

float ShadowCalculation(vec4 fragPosLightSpace, vec3 lightDir, vec3 normal) {
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    float currentDepth = projCoords.z;
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for (int x = -1; x <= 1; ++x){
        for (int y = -1; y <= 1; ++y){
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;
    return shadow;
}

vec4 computeLight(Light l, vec3 norm, vec3 FragPos, vec4 color, vec3 viewPos, vec4 FragPosLightSpace) {
    vec3 result = vec3(0.0,0.0,0.0);
    vec3 lightDir = vec3(0.0, 0.0, 0.0);

    if (l.lightVector.w == 1.0) {
        lightDir = normalize(l.lightVector.xyz - FragPos);
    }
    else if (l.lightVector.w == 0.0) {
        lightDir = normalize(l.lightVector.xyz);
    }

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    result += max(dot(norm, lightDir), 0.0) * l.diffuse;
    result += pow(max(dot(viewDir, reflectDir), 0.0), shininess) * l.specular;
    result *= 1.0 - ShadowCalculation(fs_in.FragPosLightSpace, lightDir, norm);
    result += l.ambient;

    if (l.distance != -1.0) {
        float d = length(l.lightVector.xyz - FragPos);
        float attenuation = 1.0 / (1.0 + (5.0 / l.distance) * d + (75.0 / (l.distance * l.distance)) * (d * d));
        result *= attenuation;
    }

    return vec4(result, 1.0) * color;
}

void main() {
    FragColor = computeLight(light, fs_in.Normal, fs_in.FragPos, color, viewPos, fs_in.FragPosLightSpace);
}
