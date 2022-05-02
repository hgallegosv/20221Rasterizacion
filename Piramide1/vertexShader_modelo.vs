#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 matrix_model;

out vec4 posicion;

void main() {
   posicion = matrix_model * vec4(aPos, 1.0);
   gl_Position = posicion;

   //normal = matrix_model * vec4(aNormal, 1.0);
   //normal = normalize(normal);

   // iluminacion difusa en vertex shader
   //vec3 posicionLuz = vec3(1., 1., -10.);
   //vec3 colorLuz = vec3(1., 1., 1.);
   //vec4 color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //float kd = 0.8;
   //float diff = max(0.0, dot(normalize(posicionLuz - aPos), aNormal));
   //colorFinal = color.rgb * colorLuz * kd * diff;
}
