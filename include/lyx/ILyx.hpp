//
// Created by loulfy on 22/09/16.
//

#ifndef LYX_ILYX_HPP
#define LYX_ILYX_HPP

#include "Export.hpp"

namespace lyx
{
    class API_LYX ILyx
    {
        public:

            virtual void render() = 0;
            virtual ~ILyx(){}
    };
}

#endif //LYX_ILYX_HPP
