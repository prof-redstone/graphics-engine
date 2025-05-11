
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "render.hpp"



int main(){
    std::cout << "Graphics Engine\n";

    SetupRender("Graphics Engine");

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
    Mesh* truc = setupMesh(vertices);

    std::vector<float> cube = {
        1.0f, 1.0f, 1.0f, 0.0, 1.0,//facing x neg
        1.0f, 1.0f, 3.0f, 1.0, 1.0,
        1.0f, 3.0f, 3.0f, 1.0, 0.0,

        1.0f, 1.0f, 1.0f, 0.0, 1.0,
        1.0f, 3.0f, 3.0f, 1.0, 0.0,
        1.0f, 3.0f, 1.0f, 0.0, 0.0,

        1.0f, 1.0f, 3.0f, 0.0, 1.0,//facing z pos
        3.0f, 1.0f, 3.0f, 1.0, 1.0,
        3.0f, 3.0f, 3.0f, 1.0, 0.0,

        1.0f, 1.0f, 3.0f, 0.0, 1.0,
        3.0f, 3.0f, 3.0f, 1.0, 0.0,
        1.0f, 3.0f, 3.0f, 0.0, 0.0,

        3.0f, 1.0f, 3.0f, 0.0, 1.0,//facing x pos
        3.0f, 1.0f, 1.0f, 1.0, 1.0,
        3.0f, 3.0f, 1.0f, 1.0, 0.0,

        3.0f, 1.0f, 3.0f, 0.0, 1.0,
        3.0f, 3.0f, 1.0f, 1.0, 0.0,
        3.0f, 3.0f, 3.0f, 0.0, 0.0,

        3.0f, 1.0f, 1.0f, 0.0, 1.0,//facing z neg
        1.0f, 1.0f, 1.0f, 1.0, 1.0,
        1.0f, 3.0f, 1.0f, 1.0, 0.0,

        3.0f, 1.0f, 1.0f, 0.0, 1.0,
        1.0f, 3.0f, 1.0f, 1.0, 0.0,
        3.0f, 3.0f, 1.0f, 0.0, 0.0,

        1.0f, 3.0f, 1.0f, 0.0, 1.0,//facing top
        1.0f, 3.0f, 3.0f, 1.0, 1.0,
        3.0f, 3.0f, 3.0f, 1.0, 0.0,

        1.0f, 3.0f, 1.0f, 0.0, 1.0,
        3.0f, 3.0f, 3.0f, 1.0, 0.0,
        3.0f, 3.0f, 1.0f, 0.0, 0.0,

        3.0f, 1.0f, 1.0f, 0.0, 1.0,//facing bottom
        3.0f, 1.0f, 3.0f, 1.0, 1.0,
        1.0f, 1.0f, 3.0f, 1.0, 0.0,

        3.0f, 1.0f, 1.0f, 0.0, 1.0,
        1.0f, 1.0f, 3.0f, 1.0, 0.0,
        1.0f, 1.0f, 1.0f, 0.0, 0.0,
    };
    std::vector<float> face = {
        1.0f, 1.0f, 1.0f, 0.0, 1.0,//facing x neg
        1.0f, 1.0f, 3.0f, 1.0, 1.0,
        1.0f, 3.0f, 3.0f, 1.0, 0.0,

        1.0f, 1.0f, 1.0f, 0.0, 1.0,
        1.0f, 3.0f, 3.0f, 1.0, 0.0,
        1.0f, 3.0f, 1.0f, 0.0, 0.0
    };

    Mesh* truc2 = setupMeshTexture(cube, glm::vec3(0.0,0.5,0.0));
    setMeshTextureFile(truc2, "sources/textures/back.jpg");
    updateMeshTexture(truc2, face);
    //updateMesh(truc, cube);
    //setMeshColor(truc2, glm::vec4(1.0,1.0,1.0,1.0));




    Light* sun = createLight(DIRECTIONAL, true);
    Light* led = createLight(POINT, true);
    setLightColor(sun, glm::vec3(1.0, 1.0, 1.0));
    setLightColor(led, glm::vec3(0.5, 1.0, 0.5));
    setLightIntensity(led, 0.1);
    setLightIntensity(sun, 1.0);

   
    while (shouldCloseTheApp()){
        //setMeshPosition(truc2, glm::vec3(0.0, glm::sin((float)glfwGetTime())+1.0,3.0));
        setLightPosition(led, glm::vec3(-2.0f + glm::sin((float)glfwGetTime()), 2.0f + glm::cos((float)glfwGetTime()), -2.0f));
        renderScene();
    }
    terminateRender();
    return 0;
}
