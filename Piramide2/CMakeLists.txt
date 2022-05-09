cmake_minimum_required(VERSION 3.19)
project(Piramide2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Piramide2 main.cpp glad.c)

target_link_libraries(Piramide2 -lOpenGL32 -lGLU32 -lglfw3 -lGLEW32)