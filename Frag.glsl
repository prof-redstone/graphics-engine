#version 330 core

out vec4 FragColor;

struct Light {
    vec4 lightVector; //W==0.0 => directional light, w=1.0 => light's position

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float distance; //-1.0 => 0 attenuation, !=0.0 => dist to no light (aprox)
};

in vec3 FragPos;
in vec3 Normal;

uniform vec4 color;
uniform vec3 viewPos;
uniform Light light;

uniform int shininess = 32; //pow of 2

vec4 computeLight(Light l, vec3 norm, vec3 FragPos, vec4 color, vec3 viewPos) {
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

    result += l.ambient;
    result += max(dot(norm, lightDir), 0.0) * l.diffuse;
    result += pow(max(dot(viewDir, reflectDir), 0.0), shininess) * l.specular;

    if (l.distance != -1.0) {
        float d = length(l.lightVector.xyz - FragPos);
        float attenuation = 1.0 / (1.0 + (5.0 / l.distance) * d + (75.0 / (l.distance * l.distance)) * (d * d));
        result *= attenuation;
    }

    return vec4(result, 1.0) * color;
}

void main() {
    FragColor = computeLight(light, Normal, FragPos, color, viewPos);
}
