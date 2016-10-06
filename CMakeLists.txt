cmake_minimum_required(VERSION 3.5)
project(lyx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_subdirectory(example)

include_directories(include)

set(SOURCE_FILES
        include/lyx/Context.hpp
        include/lyx/Program.hpp
        include/lyx/Shader.hpp
        include/lyx/Export.hpp
        include/lyx/Logger.hpp
        include/lyx/Buffer.hpp
        include/lyx/ILyx.hpp
        src/Context.cpp
        src/Program.cpp
        src/Shader.cpp
        src/Logger.cpp
        src/Buffer.cpp include/lyx/VertexArray.hpp src/VertexArray.cpp)

add_library(lyx SHARED ${SOURCE_FILES})

target_link_libraries(lyx GLEW glfw3 GL X11 Xxf86vm pthread Xrandr Xinerama Xi Xcursor dl)