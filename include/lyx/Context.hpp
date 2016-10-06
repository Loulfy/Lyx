//
// Created by loulfy on 22/09/16.
//

#ifndef LYX_CONTEXT_HPP
#define LYX_CONTEXT_HPP

#include <cstdlib>
#include <stdexcept>

#include "Export.hpp"
#include "ILyx.hpp"

namespace lyx
{
    class API_LYX Context
    {
        public:

            Context();
            Context(int width, int height);
            ~Context();

            void run(ILyx* app);

        private:

            void* m_window;

            ILyx* m_lyx;
    };
}

#endif //LYX_CONTEXT_HPP
