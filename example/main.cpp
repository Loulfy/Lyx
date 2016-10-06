#include <iostream>
#include <lyx/Context.hpp>

#include "Test.hpp"

int main()
{
    lyx::Context ctx;

    Test test;

    ctx.run(&test);

    return EXIT_SUCCESS;
}