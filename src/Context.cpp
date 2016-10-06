//
// Created by loulfy on 22/09/16.
//

#include <lyx/Context.hpp>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace lyx
{
    Context::Context() : Context(600, 400)
    {

    }

    Context::Context(int width, int height)
    {
        // Initialize GLFW 3
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // SET the window no re-sizable
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        // SET anti-aliasing
        glfwWindowHint(GLFW_SAMPLES, 8);

        // Create a windowed window and it is OpenGL context
        m_window = glfwCreateWindow(width, height, "LYX", nullptr, nullptr);
        if(m_window == nullptr)
        {
            glfwTerminate();
            throw std::runtime_error("LYX::ERROR::Failed to create GLFW window");
        }

        // Make the window context current
        glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_window));

        // Initialize GLEW
        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK)
        {
            glfwTerminate();
            throw std::runtime_error("LYX::ERROR::Failed to initialize GLEW");
        }

        // SET the user pointer in the window
        glfwSetWindowUserPointer(static_cast<GLFWwindow*>(m_window), this);
    }

    Context::~Context()
    {
        glfwTerminate();
    }

    void Context::run(ILyx* app)
    {
        m_lyx = app;

        while(!glfwWindowShouldClose(static_cast<GLFWwindow*>(m_window)))
        {
            glfwPollEvents();

            glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_lyx->render();

            glfwSwapBuffers(static_cast<GLFWwindow*>(m_window));
        }
    }
}