
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
        // positions (translated by +2 on x, y, z)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        1.0f, 1.0f, 3.0f,    // (-1+2, -1+2, 1+2)
        1.0f, 3.0f, 3.0f,    // (-1+2, 1+2, 1+2)
        3.0f, 3.0f, 1.0f,    // (1+2, 1+2, -1+2)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        1.0f, 3.0f, 1.0f,    // (-1+2, 1+2, -1+2)
        3.0f, 1.0f, 3.0f,    // (1+2, -1+2, 1+2)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        3.0f, 1.0f, 1.0f,    // (1+2, -1+2, -1+2)
        3.0f, 3.0f, 1.0f,    // (1+2, 1+2, -1+2)
        3.0f, 1.0f, 1.0f,    // (1+2, -1+2, -1+2)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        1.0f, 3.0f, 3.0f,    // (-1+2, 1+2, 1+2)
        1.0f, 3.0f, 1.0f,    // (-1+2, 1+2, -1+2)
        3.0f, 1.0f, 3.0f,    // (1+2, -1+2, 1+2)
        1.0f, 1.0f, 3.0f,    // (-1+2, -1+2, 1+2)
        1.0f, 1.0f, 1.0f,    // (-1+2, -1+2, -1+2)
        1.0f, 3.0f, 3.0f,    // (-1+2, 1+2, 1+2)
        1.0f, 1.0f, 3.0f,    // (-1+2, -1+2, 1+2)
        3.0f, 1.0f, 3.0f,    // (1+2, -1+2, 1+2)
        3.0f, 3.0f, 3.0f,    // (1+2, 1+2, 1+2)
        3.0f, 1.0f, 1.0f,    // (1+2, -1+2, -1+2)
        3.0f, 3.0f, 1.0f,    // (1+2, 1+2, -1+2)
        3.0f, 1.0f, 1.0f,    // (1+2, -1+2, -1+2)
        3.0f, 3.0f, 3.0f,    // (1+2, 1+2, 1+2)
        3.0f, 1.0f, 3.0f,    // (1+2, -1+2, 1+2)
        3.0f, 3.0f, 3.0f,    // (1+2, 1+2, 1+2)
        3.0f, 3.0f, 1.0f,    // (1+2, 1+2, -1+2)
        1.0f, 3.0f, 1.0f,    // (-1+2, 1+2, -1+2)
        3.0f, 3.0f, 3.0f,    // (1+2, 1+2, 1+2)
        1.0f, 3.0f, 1.0f,    // (-1+2, 1+2, -1+2)
        1.0f, 3.0f, 3.0f,    // (-1+2, 1+2, 1+2)
        3.0f, 3.0f, 3.0f,    // (1+2, 1+2, 1+2)
        1.0f, 3.0f, 3.0f,    // (-1+2, 1+2, 1+2)
        3.0f, 1.0f, 3.0f
    };
    Mesh* truc2 = setupMesh(cube, glm::vec3(0.0,0.5,0.0));
    //updateMesh(truc, cube);



    Light* sun = createLight(POINT, true);
    Light* sun2 = createLight(DIRECTIONAL, true);
    setLightColor(sun, glm::vec3(0.0, 0.5, 1.0));
    setLightColor(sun2, glm::vec3(1.0, 1.0, 0.8));

   
    while (shouldCloseTheApp()){
        setMeshPosition(truc2, glm::vec3(0.0, glm::sin((float)glfwGetTime())+1.0,3.0));
        setLightPosition(sun, glm::vec3(-2.0f + glm::sin((float)glfwGetTime()), 2.0f + glm::cos((float)glfwGetTime()), -2.0f));
        renderScene();
    }
    terminateRender();
    return 0;
}
