//
// Created by loulfy on 22/09/16.
//

#ifndef LYX_SHADER_HPP
#define LYX_SHADER_HPP

#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "Export.hpp"

namespace lyx
{
    class API_LYX Shader
    {
        public:

            enum shader
            {
                VERTEX,
                FRAGMENT,
                GEOMETRY
            };

            Shader(shader type);
            Shader(shader type, std::string path);
            ~Shader();
            void open(std::string path);
            void compile();

            void set_source(std::string src);
            unsigned int id() const;

        private:

            unsigned int m_ID;
            std::string m_src;
    };
}

#endif //LYX_SHADER_HPP
