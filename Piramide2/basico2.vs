#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 matrix_model;
uniform mat4 matrix_view;
uniform mat4 matrix_projection;

void main() {
   gl_Position = matrix_projection * matrix_view * matrix_model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}