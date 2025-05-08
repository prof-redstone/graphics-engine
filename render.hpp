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

// Variables globales externes
extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;
extern GLFWwindow* window;
extern Camera camera;
extern Mesh tempMesh;

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// Fonctions d'initialisation
int InitGLFW(GLFWwindow*& window);
void SetupRender();

// Fonctions de rendu
void renderScene();
void renderMesh(Mesh mesh);
void renderSkybox(unsigned int shader, unsigned int VAO, unsigned int cubemapTexture);

// Gestion des entrées
void processInput(GLFWwindow* window);

// Utilitaires
char* charger_shader(const char* filePath);
unsigned int ShaderLoader(const char* VertexShader, const char* FragmentShader);
unsigned int loadCubemap(std::vector<std::string> faces);
std::vector<float> addNormals(const std::vector<float>& verts);

// Setup des objets
Mesh setupMesh(std::vector<float> vertices);
unsigned int setupSkyboxVAO();
unsigned int setupLightVAO();

// Gestion de la fenêtre
bool shouldCloseTheApp();

std::vector<float> computeNormals(const std::vector<float>& verts);

#endif // RENDER_HPP