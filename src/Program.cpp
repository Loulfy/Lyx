//
// Created by loulfy on 03/10/16.
//

#include "lyx/Program.hpp"

#define GLEW_STATIC
#include <GL/glew.h>

namespace lyx
{
    Program::Program() : m_ID(glCreateProgram())
    {
        if(m_ID == 0)
        {
            throw std::runtime_error("LYX::ERROR::OPENGL_CONTEXT_MISSING");
        }
    }

    Program::~Program()
    {
        glDeleteProgram(m_ID);
    }

    void Program::attach(Shader& shader)
    {
        glAttachShader(m_ID, shader.id());
    }

    void Program::link()
    {
        //Link
        glLinkProgram(m_ID);

        //Check
        GLint success;
        GLchar infoLog[512];
        glGetProgramiv(m_ID, GL_LINK_STATUS, &success);

        if(success != GL_TRUE)
        {
            glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
            std::string error_link = "LYX::ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(infoLog);
            throw std::runtime_error(error_link);
        }
    }

    void Program::use()
    {
        glUseProgram(m_ID);
    }
}