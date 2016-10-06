//
// Created by loulfy on 06/10/16.
//

#include "lyx/VertexArray.hpp"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace lyx
{
    map<VertexArray::Primitive, unsigned int> VertexArray::DIC_PRIMITIVE = {
            {POINTS, GL_POINTS},
            {LINES, GL_LINES},
            {LINE_STRIP, GL_LINE_STRIP},
            {TRIANGLES, GL_TRIANGLES},
            {TRIANGLE_STRIP, GL_TRIANGLE_STRIP},
            {TRIANGLE_FAN, GL_TRIANGLE_FAN}};

    VertexArray::VertexArray(Primitive type) : m_ID(0), m_primitive(type)
    {
        glGenVertexArrays(1, &m_ID);
        if(m_ID == 0)
        {
            throw std::runtime_error("LYX::ERROR::OPENGL_CONTEXT_MISSING");
        }
    }

    VertexArray::VertexArray() : VertexArray(TRIANGLES)
    {

    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_ID);
    }

    void VertexArray::bind()
    {
        glBindVertexArray(m_ID);
    }
}