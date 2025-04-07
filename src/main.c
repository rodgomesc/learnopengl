#include <stdio.h>
#include <stdbool.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    printf("GLFW version %d.%d\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR);

    /* --------------------------- Initialization --------------------------- */

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }    
    glfwMakeContextCurrent(window);
   
    if (!gladLoadGL(glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    // callback for window resizing
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    /*   ----------------- Game Loop ----------------- */
    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    /*   ----------------- Game Loop ----------------- */


    /*   ----------------- Cleanup ----------------- */
    glfwTerminate();
    gladLoaderUnloadGL();
    /*   ----------------- Cleanup ----------------- */
    return 0;


}
