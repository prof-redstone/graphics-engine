// render.hpp
#ifndef RENDER_HPP
#define RENDER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

// Forward declarations des classes utilisées
class Camera;
class Light;

// Structure Mesh
struct Mesh {
    unsigned int VAO;
    unsigned int VBO;
    std::vector<float> vertices;
    std::vector<float> normales;
    glm::mat4 model;
    glm::vec4 color;
    int shininess;

};

enum LightType {
    DIRECTIONAL, // w = 0.0
    POINT        // w = 1.0
};

struct Light {
    LightType type;
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float distance;

    bool castshadow;
    unsigned int depthMapFBO;
    unsigned int depthMap;
    unsigned int shadowWidth, shadowHeight;
    float near_plane = 0.1f, far_plane = 25.0f;
    float width = 10.0f;//ortho
    float fov = glm::radians(90.0f);//perspective
    float aspectRatio = 1.0f;//perspective
};

// Variables globales externes
extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;
extern GLFWwindow* window;
extern Camera camera;
extern Mesh* tempMesh;

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// Fonctions d'initialisation
int InitGLFW(GLFWwindow*& window);
void SetupRender();
void terminateRender();
// Fonctions de rendu
void renderScene();
void renderMesh(unsigned int shaderName);
void renderSkybox(unsigned int shader, unsigned int VAO, unsigned int cubemapTexture);

// Gestion des entrées
void processInput(GLFWwindow* window);

// Utilitaires
char* charger_shader(const char* filePath);
unsigned int ShaderLoader(const char* VertexShader, const char* FragmentShader);
unsigned int loadCubemap(std::vector<std::string> faces);
std::vector<float> addNormals(const std::vector<float>& verts);

// Setup des objets
Mesh* setupMesh(std::vector<float> vertices);
unsigned int setupSkyboxVAO();
unsigned int setupLightVAO();

// Gestion de la fenêtre
bool shouldCloseTheApp();

std::vector<float> computeNormals(const std::vector<float>& verts);

#endif // RENDER_HPP