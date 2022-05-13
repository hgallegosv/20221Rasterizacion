cmake_minimum_required(VERSION 3.19)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnOpenGL basic_lighting_diffuse.cpp camera.h shader_m.h glad.c)

target_link_libraries(LearnOpenGL -lOpenGL32 -lGLU32 -lglfw3 -lGLEW32)