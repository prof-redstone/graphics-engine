#pragma once
#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <string>

enum LightType {
    DIRECTIONAL, // w = 0.0
    POINT        // w = 1.0
};

class Light {
public:
    unsigned int depthMapFBO;
    unsigned int depthMap;
    unsigned int shadowWidth, shadowHeight;
    LightType type;
    glm::vec3 position;  // Pour les lumi�res ponctuelles
    glm::vec3 direction; // Pour les lumi�res directionnelles
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float distance;
    glm::mat4 lightSpaceMatrix;
    // Constructeurs
    inline Light(LightType type = POINT);
    inline Light(LightType type, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float distance = -1.0f);

    // Initialisation
    inline void init(unsigned int shadowWidth = 2048, unsigned int shadowHeight = 2048);

    // Mise � jour
    inline void update();
    inline void setPosition(const glm::vec3& position);
    inline void setDirection(const glm::vec3& direction);
    inline void setColors(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular);
    inline void setDistance(float distance);

    // Fonctions de rendu
    /*void beginShadowPass();
    void endShadowPass();*/

    // Getters
    glm::vec4 getLightVector();
    glm::vec3 getAmbient() const { return ambient; }
    glm::vec3 getDiffuse() const { return diffuse; }
    glm::vec3 getSpecular() const { return specular; }
    float getDistance() const { return distance; }
    glm::mat4 getLightSpaceMatrix() const { return lightSpaceMatrix; }
    unsigned int getDepthMap() const { return depthMap; }
};

Light::Light(LightType type)
    : type(type),
    position(0.0f, 0.0f, 0.0f),
    direction(0.0f, 0.0f, -1.0f),
    ambient(0.2f, 0.2f, 0.2f),
    diffuse(0.5f, 0.5f, 0.5f),
    specular(1.0f, 1.0f, 1.0f),
    distance(-1.0f),
    depthMapFBO(0),
    depthMap(0),
    shadowWidth(2048),
    shadowHeight(2048),
    lightSpaceMatrix(1.0f)
{}

Light::Light(LightType type, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float distance)
    : type(type),
    position(position),
    direction(0.0f, 0.0f, -1.0f), 
    ambient(ambient),
    diffuse(diffuse),
    specular(specular),
    distance(distance),
    depthMapFBO(0),
    depthMap(0),
    shadowWidth(2048),
    shadowHeight(2048),
    lightSpaceMatrix(1.0f)
{}

void Light::init(unsigned int shadowWidth, unsigned int shadowHeight) {
    shadowWidth = shadowWidth;
    shadowHeight = shadowHeight;

    // G�n�rer le FBO pour la carte de profondeur des ombres
    glGenFramebuffers(1, &depthMapFBO);

    // Cr�er la texture de profondeur
    glGenTextures(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
        shadowWidth, shadowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    // Attacher la texture au FBO
    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
    glDrawBuffer(GL_NONE);  // Pas besoin de buffer de couleur
    glReadBuffer(GL_NONE);  // Pas besoin de lire des couleurs
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Mettre � jour la matrice de l'espace lumi�re
    update();
}


void Light::update() {
    // Mise � jour de la matrice de l'espace lumi�re
    // Pour une lumi�re directionnelle ou ponctuelle
    float near_plane = 0.1f, far_plane = 25.0f;
    float fov = glm::radians(90.0f);
    float aspectRatio = 1.0f;

    glm::mat4 lightProjection;
    glm::mat4 lightView;

    if (type == DIRECTIONAL) {
        lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
        lightView = glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
    }else {
        lightProjection = glm::perspective(fov, aspectRatio, near_plane, far_plane);
        lightView = glm::lookAt(position, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    lightSpaceMatrix = lightProjection * lightView;
}


void Light::setPosition(const glm::vec3& a_position) {
    position = a_position;
    if (type == POINT) {
        update();
    }
}

void Light::setDirection(const glm::vec3& a_direction) {
    direction = glm::normalize(a_direction);
    if (type == DIRECTIONAL) {
        update();
    }
}

void Light::setColors(const glm::vec3& a_ambient, const glm::vec3& a_diffuse, const glm::vec3& a_specular) {
    ambient = a_ambient;
    diffuse = a_diffuse;
    specular = a_specular;
}

void Light::setDistance(float a_distance) {
    distance = a_distance;
}

glm::vec4 Light::getLightVector() {
    if (type == POINT) {
        return glm::vec4(position, 1.0);
    }else{
        return glm::vec4(direction, 0.0);
    }
}

#endif 