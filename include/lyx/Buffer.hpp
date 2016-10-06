//
// Created by loulfy on 06/10/16.
//

#ifndef LYX_BUFFER_HPP
#define LYX_BUFFER_HPP

#include <stdexcept>
#include <map>

#include "Export.hpp"

namespace lyx
{
    class API_LYX Buffer
    {
        public:

            enum buffer
            {
                ARRAY,
                INDEX
            };

            enum drawer
            {
                STATIC,
                DYNAMIC,
                STREAM
            };

            Buffer();
            Buffer(buffer type);
            ~Buffer();

            void bind();
            void data(drawer type, const float* data, int size);
            void update(const float* data, int offset, int size);

        private:

            unsigned int m_ID;
            buffer m_target;

            static std::map<buffer, unsigned int> DIC_BUFF;
            static std::map<drawer, unsigned int> DIC_DRAW;
    };
}

#endif //LYX_BUFFER_HPP
