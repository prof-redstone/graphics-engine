/*#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

//#include "camera.h"
//#include "light.h"
#include "render.hpp"

/*
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
int InitGLFW(GLFWwindow*& window);
void processInput(GLFWwindow* window);
char* charger_shader(const char* filePath);
unsigned int ShaderLoader(const char* VertexShader, const char* FragmentShader);
unsigned int loadCubemap(std::vector<std::string> faces);
std::vector<float> computeNormals(const std::vector<float>& verts);
void renderSkybox(unsigned int shader, unsigned int VAO, unsigned int cubemapTexture);
unsigned int setupSkyboxVAO();
unsigned int setupLightVAO();

unsigned int SCR_WIDTH = 1000;
unsigned int SCR_HEIGHT = 800;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;*/



int main(){
    std::cout << "Graphics Engine\n";


    /*GLFWwindow* window;
    if (InitGLFW(window) == -1) return -1;    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_DEPTH_TEST);

    //---SKY BOX---
    unsigned int shaderSkybox = ShaderLoader("SkyboxVertex.glsl", "SkyboxFrag.glsl");

    unsigned int VAO_SKY = setupSkyboxVAO();

    std::vector<std::string> faces{
        "sources/skybox/right.jpg",
        "sources/skybox/left.jpg",
        "sources/skybox/top.jpg",
        "sources/skybox/bottom.jpg",
        "sources/skybox/front.jpg",
        "sources/skybox/back.jpg"
    };
    unsigned int cubemapTexture = loadCubemap(faces);


    //---LIGHT---
    unsigned int shaderLight = ShaderLoader("LightVertex.glsl", "LightFrag.glsl");

    float LightVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f
    };

    unsigned int VAO_LIGHT = setupLightVAO();

    //---MESH---
    unsigned int shaderProgram = ShaderLoader("MainVertex.glsl", "MainFrag.glsl");
    unsigned int shaderProgramDepth = ShaderLoader("DepthShadowVertex.glsl", "DepthShadowFrag.glsl");*/
    SetupRender();
    std::vector<float> vertices = {
        -1.0f,-1.0f,-1.0f, 
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, 

        1.0f, 1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, 

        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,

        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        -0.5f, 1.5f, -0.5f, 
        -0.5f, 1.5f, 0.5f,
        -0.5f, 2.5f, 0.5f, 

        0.5f, 2.5f, -0.5f,
        -0.5f, 1.5f, -0.5f,
        -0.5f, 2.5f, -0.5f, 

        0.5f, 1.5f, 0.5f,
        -0.5f, 1.5f, -0.5f,
        0.5f, 1.5f, -0.5f,

        0.5f, 2.5f, -0.5f,
        0.5f, 1.5f, -0.5f,
        -0.5f, 1.5f, -0.5f,

        -0.5f, 1.5f, -0.5f,
        -0.5f, 2.5f, 0.5f,
        -0.5f, 2.5f, -0.5f,

        0.5f, 1.5f, 0.5f,
        -0.5f, 1.5f, 0.5f,
        -0.5f, 1.5f, -0.5f,

        -0.5f, 2.5f, 0.5f,
        -0.5f, 1.5f, 0.5f,
        0.5f, 1.5f, 0.5f,

        0.5f, 2.5f, 0.5f,
        0.5f, 1.5f, -0.5f,
        0.5f, 2.5f, -0.5f,

        0.5f, 1.5f, -0.5f,
        0.5f, 2.5f, 0.5f,
        0.5f, 1.5f, 0.5f,

        0.5f, 2.5f, 0.5f,
        0.5f, 2.5f, -0.5f,
        -0.5f, 2.5f, -0.5f,

        0.5f, 2.5f, 0.5f,
        -0.5f, 2.5f, -0.5f,
        -0.5f, 2.5f, 0.5f,

        0.5f, 2.5f, 0.5f,
        -0.5f, 2.5f, 0.5f,
        0.5f, 1.5f, 0.5f,

         20.0f, -0.0f, -20.0f,
        - 20.0f, -0.0f, -20.0f,  
         20.0f, -0.0f,  20.0f,

         20.0f, -0.0f,  20.0f,
        -20.0f, -0.0f, -20.0f, 
        -20.0f, -0.0f,  20.0f
    };
    Mesh mesh = setupMesh(vertices);
    /*
    std::vector<float> normals = computeNormals(vertices);


    unsigned int VBOPos, VBONorm, VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);//VAO actif

    glGenBuffers(1, &VBOPos);//generate VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBOPos);//VBO actif
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW); //remplissage VBO actif

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//configuring VBO layout
    glEnableVertexAttribArray(0); // enable attribute

    glGenBuffers(1, &VBONorm);
    glBindBuffer(GL_ARRAY_BUFFER, VBONorm);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), normals.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);*/


    //shadow
    //Light sunLight(POINT);
    //sunLight.init(2058, 2058);
    /*unsigned int depthMapFBO;
    glGenFramebuffers(1, &depthMapFBO);

    const unsigned int SHADOW_WIDTH = 2058, SHADOW_HEIGHT = 2058;

    unsigned int depthMap;
    glGenTextures(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
        SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);*/

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    while (shouldCloseTheApp()){
        renderScene();
        /*float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(0);


        sunLight.setPosition(glm::vec3(-2.0f + glm::sin((float)glfwGetTime()), 2.0f + glm::cos((float)glfwGetTime()), -2.0f));
        sunLight.update();
        glViewport(0, 0, sunLight.shadowWidth, sunLight.shadowHeight);
        glClear(GL_DEPTH_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, sunLight.depthMapFBO);

        glUseProgram(shaderProgramDepth);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgramDepth, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(sunLight.lightSpaceMatrix));
        glCullFace(GL_FRONT);

        glm::mat4 model = glm::mat4(1.0);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgramDepth, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

        glCullFace(GL_BACK);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);



        // 2. then render scene as normal with shadow mapping (using depth map)
        glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);  
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        glBindTexture(GL_TEXTURE_2D, sunLight.depthMap);

        model = glm::mat4(1.0);
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        glm::vec4 color = glm::vec4(0.0f, 1.0f, 0.5f, 1.0f);
        glm::vec4 lightVector = glm::vec4(-2.0f + glm::sin((float)glfwGetTime()), 2.0f + glm::cos((float)glfwGetTime()), -2.0f, 1.0);//w=1.0 position, w=0.0 direction
        glm::vec3 ambient = glm::vec3(0.2f, 0.18f, 0.16f);
        glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
        glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
        int shininess = 32;

        glUseProgram(shaderProgram);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(sunLight.lightSpaceMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniform3fv(glGetUniformLocation(shaderProgram, "viewPos"), 1, glm::value_ptr(camera.Position));
        glUniform4fv(glGetUniformLocation(shaderProgram, "color"), 1, glm::value_ptr(color));
        glUniform4fv(glGetUniformLocation(shaderProgram, "light.lightVector"), 1, glm::value_ptr(lightVector));
        glUniform3fv(glGetUniformLocation(shaderProgram, "light.ambient"), 1, glm::value_ptr(ambient));
        glUniform3fv(glGetUniformLocation(shaderProgram, "light.diffuse"), 1, glm::value_ptr(diffuse));
        glUniform3fv(glGetUniformLocation(shaderProgram, "light.specular"), 1, glm::value_ptr(specular));
        glUniform1i(glGetUniformLocation(shaderProgram, "shininess"), shininess);
        glUniform1f(glGetUniformLocation(shaderProgram, "light.distance"), -1.0);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, sunLight.depthMap);
        glUniform1i(glGetUniformLocation(shaderProgram, "shadowMap"), 0);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

        //---LIGHT---

        glUseProgram(shaderLight);
        model = glm::mat4(glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f + glm::sin((float)glfwGetTime()), 2.0f + glm::cos((float)glfwGetTime()), -2.0f)));
        model = glm::scale(model, glm::vec3(0.1f));
        glUniformMatrix4fv(glGetUniformLocation(shaderLight, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shaderLight, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shaderLight, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(glGetUniformLocation(shaderLight, "color"), 1, glm::value_ptr(glm::vec4(1.0f)));
        
        glBindVertexArray(VAO_LIGHT);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        //---SkyBox---
        renderSkybox(shaderSkybox, VAO_SKY, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();*/
    }
    glfwTerminate();
    return 0;
}
/*
unsigned int setupLightVAO() {
    float LightVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f
    };

    unsigned int VBO_LIGHT, VAO_LIGHT;
    glGenVertexArrays(1, &VAO_LIGHT);
    glGenBuffers(1, &VBO_LIGHT);

    glBindVertexArray(VAO_LIGHT);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_LIGHT);
    glBufferData(GL_ARRAY_BUFFER, sizeof(LightVertices), LightVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    return VAO_LIGHT;
}

unsigned int setupSkyboxVAO() {
    float skyboxVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f
    };

    unsigned int VBO_SKY, VAO_SKY;
    glGenVertexArrays(1, &VAO_SKY);
    glGenBuffers(1, &VBO_SKY);

    glBindVertexArray(VAO_SKY);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_SKY);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    return VAO_SKY;
}

void renderSkybox(unsigned int shader, unsigned int VAO, unsigned int cubemapTexture) {
    glDepthFunc(GL_LEQUAL);  // change la fonction de profondeur pour que la skybox passe le test quand z=1.0
    glUseProgram(shader);
    glm::mat4 view_skybox = glm::mat4(glm::mat3(camera.GetViewMatrix())); // Supprime la translation pour que la skybox ne bouge pas avec la caméra
    glm::mat4 projection_skybox = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(view_skybox));
    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(projection_skybox));

    // Lier la texture du cubemap
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthFunc(GL_LESS); //fonction de profondeur par défaut

}

std::vector<float> computeNormals(const std::vector<float>& verts) {
    std::vector<float> normals(verts.size(), 0.0f);

    for (size_t i = 0; i < verts.size(); i += 9) {
        glm::vec3 v0(verts[i], verts[i + 1], verts[i + 2]);
        glm::vec3 v1(verts[i + 3], verts[i + 4], verts[i + 5]);
        glm::vec3 v2(verts[i + 6], verts[i + 7], verts[i + 8]);

        glm::vec3 edge1 = v1 - v0;
        glm::vec3 edge2 = v2 - v0;
        glm::vec3 normal = glm::normalize(glm::cross(edge1, edge2));

        for (int j = 0; j < 3; ++j) {
            normals[i + j * 3 + 0] = normal.x;
            normals[i + j * 3 + 1] = normal.y;
            normals[i + j * 3 + 2] = normal.z;
        }
    }

    return normals;
}

unsigned int loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
    SCR_WIDTH = width;
    SCR_HEIGHT = height;
}

int InitGLFW(GLFWwindow*& window) {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Graphics engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    //glViewport(0, 0, 800, 600);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Erreur lors de l'initialisation de GLEW" << std::endl;
        return -1;
    }

    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

char* charger_shader(const char* filePath) {
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier shader " << filePath << std::endl;
        return nullptr;
    }

    std::stringstream buffer;
    buffer << shaderFile.rdbuf();
    std::string shaderCode = buffer.str();

    char* shaderSource = new char[shaderCode.size() + 1];
    std::copy(shaderCode.begin(), shaderCode.end(), shaderSource);
    shaderSource[shaderCode.size()] = '\0'; // Terminaison avec '\0'

    return shaderSource;
}

unsigned int ShaderLoader(const char* VertexShader, const char* FragmentShader) {
    char infoLog[512];
    int success;

    // --- VERTEX SHADER ---
    char* vertexShaderSource = charger_shader(VertexShader);
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "Erreur compilation VERTEX shader (" << VertexShader << "):\n" << infoLog << std::endl;
    }

    // --- FRAGMENT SHADER ---
    char* fragmentShaderSource = charger_shader(FragmentShader);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "Erreur compilation FRAGMENT shader (" << FragmentShader << "):\n" << infoLog << std::endl;
    }

    // --- SHADER PROGRAM ---
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "Erreur linkage du shader program:\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
*/