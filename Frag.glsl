#version 330 core

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec4 color;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 ambientColor;

void main(){
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * ambientColor;

    vec3 diffuse = diff * lightColor;
    vec4 result = vec4(ambient + diffuse,1.0) * color;
    FragColor = result;
}