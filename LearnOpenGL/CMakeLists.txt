cmake_minimum_required(VERSION 3.19)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 14)

#add_executable(LearnOpenGL multiple_lights.cpp camera.h shader_m.h glad.c stb_image.h stb_image.cpp)
add_executable(LearnOpenGL textures.cpp glad.c stb_image.h stb_image.cpp)

target_link_libraries(LearnOpenGL -lOpenGL32 -lGLU32 -lglfw3 -lGLEW32)