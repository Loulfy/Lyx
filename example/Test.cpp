//
// Created by loulfy on 22/09/16.
//

#include "Test.hpp"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace lyx;

Test::Test() : m_vert(Shader::VERTEX, "shaders/basic_vs.glsl"), m_frag(Shader::FRAGMENT, "shaders/basic_fs.glsl")
{
    m_shader.attach(m_frag);
    m_shader.attach(m_vert);
    m_shader.link();
    m_shader.use();

    m_vao.bind();

    float vertices[] = {
            0.0f,  0.5f, // Vertex 1 (X, Y)
            0.5f, -0.5f, // Vertex 2 (X, Y)
            -0.5f, -0.5f  // Vertex 3 (X, Y)
    };

    m_buff.data(Buffer::STATIC, vertices, 6);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
}

void Test::render()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
