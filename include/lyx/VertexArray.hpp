//
// Created by loulfy on 06/10/16.
//

#ifndef LYX_VERTEXARRAY_HPP
#define LYX_VERTEXARRAY_HPP

#include <map>

#include "Export.hpp"

namespace lyx
{
    class API_LYX VertexArray
    {
        public:

            enum Primitive
            {
                POINTS,
                LINES,
                LINE_STRIP,
                TRIANGLES,
                TRIANGLE_STRIP,
                TRIANGLE_FAN
            };

            VertexArray();
            VertexArray(Primitive type);
            ~VertexArray();

            void bind();

        private:

            unsigned int m_ID;
            Primitive m_primitive;

            static std::map<Primitive, unsigned int> DIC_PRIMITIVE;
    };
}

#endif //LYX_VERTEXARRAY_HPP
