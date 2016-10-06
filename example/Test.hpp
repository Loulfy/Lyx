//
// Created by loulfy on 22/09/16.
//

#ifndef LYX_TEST_HPP
#define LYX_TEST_HPP

#include <lyx/ILyx.hpp>
#include <lyx/Buffer.hpp>
#include <lyx/Shader.hpp>
#include <lyx/Program.hpp>
#include <lyx/VertexArray.hpp>

class Test : public lyx::ILyx
{
    public:

        Test();
        void render() override;

    private:

        lyx::Shader m_vert;
        lyx::Shader m_frag;
        lyx::Program m_shader;
        lyx::Buffer m_buff;
        lyx::VertexArray m_vao;
};


#endif //LYX_TEST_HPP
