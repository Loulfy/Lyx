//
// Created by loulfy on 06/10/16.
//

#include "lyx/Buffer.hpp"

#define GLEW_STATIC
#include <GL/glew.h>

using namespace std;

namespace lyx
{
    map<Buffer::buffer, unsigned int> Buffer::DIC_BUFF = {{ARRAY, GL_ARRAY_BUFFER}, {INDEX, GL_ELEMENT_ARRAY_BUFFER}};
    map<Buffer::drawer, unsigned int> Buffer::DIC_DRAW = {{STATIC, GL_STATIC_DRAW}, {DYNAMIC, GL_DYNAMIC_DRAW}, {STREAM, GL_STREAM_DRAW}};

    Buffer::Buffer(buffer type) : m_ID(0), m_target(type)
    {
        glGenBuffers(1, &m_ID);
        if(m_ID == 0)
        {
            throw std::runtime_error("LYX::ERROR::OPENGL_CONTEXT_MISSING");
        }
    }

    Buffer::Buffer() : Buffer(ARRAY)
    {

    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &m_ID);
    }

    void Buffer::bind()
    {
        glBindBuffer(DIC_BUFF.at(m_target), m_ID);
    }

    void Buffer::data(drawer type, const float* data, int size)
    {
        this->bind();
        glBufferData(DIC_BUFF.at(m_target), size * sizeof(float), data, DIC_DRAW.at(type));
    }

    void Buffer::update(const float* data, int offset, int size)
    {
        this->bind();
        glBufferSubData(DIC_BUFF.at(m_target), offset, size, data);
    }
}