cmake_minimum_required(VERSION 3.19)
project(Piramide1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Piramide1 main.cpp mat4.cpp mat4.h)

target_link_libraries(Piramide1 -lOpenGL32 -lfreeGLUT -lglew32)