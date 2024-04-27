#include "Window.h"

#include "Renderer.h"

typedef struct
{
    uint8_t _majorVersion, _minorVersion;
    int _windowSizeX, _windowSizeY;
    char* title;
    GLFWwindow* _windowContext;
} WindowData;

WindowData _windowData;
void ResizeWindow();

void InitWindow(const WindowSettings settings)
{
    _windowData = (WindowData){settings._majorVersion, settings._minorVersion, settings._windowSizeX, settings._windowSizeY, settings.title};

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _windowData._majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _windowData._minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _windowData._windowContext = glfwCreateWindow(_windowData._windowSizeX, _windowData._windowSizeY, _windowData.title, NULL, NULL);
    glfwMakeContextCurrent(_windowData._windowContext);
    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
    glfwSetFramebufferSizeCallback(_windowData._windowContext, ResizeWindow);
    glfwSetKeyCallback(_windowData._windowContext, KeyPressed);
}

void CleanWindow()
{
    glfwTerminate();
}

void UpdateWindow()
{
    glfwGetWindowSize(_windowData._windowContext, &_windowData._windowSizeX, &_windowData._windowSizeY);
    glClearColor(0.0f, 0.54f, 0.54f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDepthFunc(GL_LESS);
    glfwSwapBuffers(_windowData._windowContext);
    glfwPollEvents();
}

void ResizeWindow()
{
    glViewport(0, 0, _windowData._windowSizeX, _windowData._windowSizeY);
}

void KeyPressed()
{

}

int WindowShouldClose()
{
    return !glfwWindowShouldClose(_windowData._windowContext);
}