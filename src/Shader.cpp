//
// Created by loulfy on 22/09/16.
//

#include "lyx/Shader.hpp"

#define GLEW_STATIC
#include <GL/glew.h>

using namespace std;

namespace lyx
{
    Shader::Shader(shader type) : m_ID(0)
    {
        switch(type)
        {
            case VERTEX:
                m_ID = glCreateShader(GL_VERTEX_SHADER);
                break;

            case FRAGMENT:
                m_ID = glCreateShader(GL_FRAGMENT_SHADER);
                break;

            case GEOMETRY:
                m_ID = glCreateShader(GL_GEOMETRY_SHADER);
                break;
        }

        if(m_ID == 0)
        {
            throw std::runtime_error("LYX::ERROR::OPENGL_CONTEXT_MISSING");
        }
    }

    Shader::Shader(shader type, string path) : Shader(type)
    {
        this->open(path);
        this->compile();
    }

    Shader::~Shader()
    {
        glDeleteShader(m_ID);
    }

    void Shader::open(string path)
    {
        ifstream file;

        file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        try
        {
            file.open(path);
            stringstream src;

            src << file.rdbuf();

            file.close();

            m_src = src.str();
        }
        catch(ifstream::failure e)
        {
            throw std::runtime_error("LYX::ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
        }
    }

    void Shader::compile()
    {
        GLint success;
        GLchar infoLog[512];

        // Shader compilation
        const char* data = m_src.c_str();
        glShaderSource(m_ID, 1, &data, NULL);
        glCompileShader(m_ID);

        // Print compile errors if any
        glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
        if(success != GL_TRUE)
        {
            glGetShaderInfoLog(m_ID, 512, NULL, infoLog);
            std::string error_compilation = "LYX::ERROR::SHADER::SRC::COMPILATION_FAILED\n" + std::string(infoLog);
            throw std::runtime_error(error_compilation);
        }
    }

    void Shader::set_source(string src)
    {
        m_src = src;
    }

    unsigned int Shader::id() const
    {
        return m_ID;
    }
}
