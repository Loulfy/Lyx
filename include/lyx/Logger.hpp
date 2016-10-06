//
// Created by loulfy on 03/10/16.
//

#ifndef LYX_LOGGER_HPP
#define LYX_LOGGER_HPP

#include <string>
#include <fstream>

#include "Export.hpp"

namespace lyx
{
    class API_LYX Logger
    {
        public:

            Logger(std::string fpath);
    };
}

#endif //LYX_LOGGER_HPP
