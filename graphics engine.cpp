
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
        1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // Sommet 1: position + texture
    1.0f, 1.0f, 3.0f, 0.0f, 1.0f,  // Sommet 2: position + texture
    1.0f, 3.0f, 3.0f, 1.0f, 1.0f,  // Sommet 3: position + texture

    // Face 2
    3.0f, 3.0f, 1.0f, 1.0f, 0.0f,  // Sommet 4: position + texture
    1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // Sommet 5: position + texture
    1.0f, 3.0f, 1.0f, 1.0f, 1.0f,  // Sommet 6: position + texture

    // Face 3
    3.0f, 1.0f, 3.0f, 0.0f, 0.0f,  // Sommet 7: position + texture
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // Sommet 8: position + texture
    3.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // Sommet 9: position + texture

    // Face 4
    3.0f, 3.0f, 1.0f, 0.0f, 0.0f,  // Sommet 10: position + texture
    3.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // Sommet 11: position + texture
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // Sommet 12: position + texture

    // Face 5
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // Sommet 13: position + texture
    1.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 14: position + texture
    1.0f, 3.0f, 1.0f, 0.0f, 1.0f,  // Sommet 15: position + texture

    // Face 6
    3.0f, 1.0f, 3.0f, 1.0f, 0.0f,  // Sommet 16: position + texture
    1.0f, 1.0f, 3.0f, 0.0f, 0.0f,  // Sommet 17: position + texture
    1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Sommet 18: position + texture

    // Face 7
    1.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 19: position + texture
    1.0f, 1.0f, 3.0f, 1.0f, 0.0f,  // Sommet 20: position + texture
    3.0f, 1.0f, 3.0f, 1.0f, 1.0f,  // Sommet 21: position + texture

    // Face 8
    3.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 22: position + texture
    3.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // Sommet 23: position + texture
    3.0f, 3.0f, 1.0f, 0.0f, 1.0f,  // Sommet 24: position + texture

    // Face 9
    3.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // Sommet 25: position + texture
    3.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 26: position + texture
    3.0f, 1.0f, 3.0f, 0.0f, 1.0f,  // Sommet 27: position + texture

    // Face 10
    3.0f, 3.0f, 3.0f, 1.0f, 0.0f,  // Sommet 28: position + texture
    3.0f, 3.0f, 1.0f, 1.0f, 1.0f,  // Sommet 29: position + texture
    1.0f, 3.0f, 1.0f, 0.0f, 1.0f,  // Sommet 30: position + texture

    // Face 11
    3.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 31: position + texture
    1.0f, 3.0f, 1.0f, 1.0f, 1.0f,  // Sommet 32: position + texture
    1.0f, 3.0f, 3.0f, 1.0f, 0.0f,  // Sommet 33: position + texture

    // Face 12
    3.0f, 3.0f, 3.0f, 0.0f, 0.0f,  // Sommet 34: position + texture
    1.0f, 3.0f, 3.0f, 1.0f, 0.0f,  // Sommet 35: position + texture
    3.0f, 1.0f, 3.0f, 1.0f, 1.0f
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
