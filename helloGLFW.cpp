#define GLFW_INCLUDE_NONE
#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>
#include "glad.h"
#include <iostream>
#include "Sphere.h"

using std::cout, std::endl;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    // init glfw, set OpenGL to 3.3 and core features
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    GLFWwindow* window = glfwCreateWindow(800, 400, "Learning OpenGL", NULL, NULL);
    if (window == NULL) {
        cout << "Window Failed to Create" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to Initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, 800, 400);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    Sphere c3(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1, true, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    glm::vec3 temp = c3.getNormal(glm::vec3(1.0, 1.0, 1.0));
    cout << "<" << temp.x << ", " << temp.y << ", " << temp.z << ">" << endl;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}