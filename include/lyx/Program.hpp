//
// Created by loulfy on 03/10/16.
//

#ifndef LYX_PROGRAM_HPP
#define LYX_PROGRAM_HPP

#include "Shader.hpp"
#include "Export.hpp"

namespace lyx
{
    class API_LYX Program
    {
        public:

            Program();
            ~Program();
            void attach(Shader& shader);
            void link();
            void use();

        private:

            unsigned int m_ID;
    };
}

#endif //LYX_PROGRAM_HPP
