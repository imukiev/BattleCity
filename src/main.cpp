#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void error(int code, const char * desc)
{
    fputs(desc, stderr);
}

// 1) обработка разера окна
// 2) обработка нажатие клавиш для выхода

int windowSizeX = 640;
int windowSizeY = 480;

void keyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
}

void windowSize(GLFWwindow* pWindow, int width, int heigt) 
{
    windowSizeX = width;
    windowSizeY = heigt;
    glViewport(0, 0, width, heigt);
}


int main(void)
{
    GLFWwindow* pWindow;



    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(windowSizeX, windowSizeY, "Battle City", NULL, NULL);
    if (!pWindow)
    {
        std::cout << "glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(error);
    glfwSetKeyCallback (pWindow, keyCallback);
    glfwSetWindowSizeCallback(pWindow, windowSize);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if(!gladLoadGL())
    {
        std::cout << "Can not load GLAD!" << std::endl;
        return -1;
    }

    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 0, 1, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
