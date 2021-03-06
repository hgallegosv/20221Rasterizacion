#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>

using namespace std;

float vertices1[] = {
        0, 0, 0,    0.25, 0, 0.5,   0.5, 0, 0,
        0.25, 0, 0.5,   0.5, 0, 0,   0.25, 0.5, 0,
        0, 0, 0,    0.25, 0, 0.5,   0.25, 0.5, 0,
        0, 0, 0,    0.5, 0, 0,      0.25, 0, 0.5
};
float vertices2[] = {
        0, 0, 0,
        0.5, 0, 0,
        0.25, 0.25, 0.5,
        0.25, 0.5, 0,
};
unsigned int indices2[] = {
        0, 2, 1,
        2, 1, 3,
        0, 2, 3,
        0, 1, 3
};
float tx=0, ty=0;
float gx=0;
GLuint p_id;
GLint vertex_id = 0;
GLuint matrix_model_id;

char* readShader(char *nameFile) {
    FILE* filePointer = fopen(nameFile, "rb");
    char* content = NULL;
    long numVal = 0;
    fseek(filePointer, 0L, SEEK_END);
    numVal = ftell(filePointer);
    fseek(filePointer, 0L, SEEK_SET);
    content = (char*) malloc((numVal+1) * sizeof(char));
    fread(content, 1, numVal, filePointer);
    content[numVal] = '\0';
    fclose(filePointer);
    return content;
}
static void LinkProgram(GLuint id){
    GLint status;
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &status);
    if (!status) {
        GLint len;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) malloc(len*sizeof(char));
        glGetProgramInfoLog(id, len, 0, message);
        printf(message);
        free(message);
    }
}
static void CompileShader(GLuint id){
    GLint status;
    glCompileShader(id);
    glGetShaderiv(id, GL_LINK_STATUS, &status);
    if (!status) {
        GLint len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) malloc(len*sizeof(char));
        glGetShaderInfoLog(id, len, 0, message);
        printf(message);
        free(message);
    }
}
static void CreateShaderProgram (char* vertexShaderFile, char* fragmentShaderFile, GLuint &p_id) {
    char*	vertexShader   = readShader(vertexShaderFile);
    char*	fragmentShader = readShader(fragmentShaderFile);

    /* vertex shader */
    GLuint v_id = glCreateShader(GL_VERTEX_SHADER);
    if (v_id == 0)
        cout << "Could not create vertex shader object";

    glShaderSource(v_id, 1, (const char**) &vertexShader, 0);
    CompileShader(v_id);

    /* fragment shader */
    GLuint f_id = glCreateShader(GL_FRAGMENT_SHADER);
    if (f_id == 0)
        cout << "Could not create fragment shader object";

    glShaderSource(f_id, 1, (const char**) &fragmentShader, 0);
    CompileShader(f_id);

    /* program */
    p_id = glCreateProgram();
    if (p_id == 0)
        cout << "Could not create program object";
    glAttachShader(p_id, v_id);
    glAttachShader(p_id, f_id);
    LinkProgram(p_id);

}

void Redisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(p_id);
    glVertexAttribPointer(vertex_id, 3, GL_FLOAT, GL_FALSE, 0, (const void *)vertices2);
    glEnableVertexAttribArray(vertex_id);

    //mat4 matrix_model;
    //matrix_model.traslacion(tx, ty, 0);
    //matrix_model.traslacion(0.5, 0.3, 0.1);
    //matrix_model.rotacion(gx, 0, 0);
    glm::mat4 matrix_model = glm::rotate(glm::mat4(1.0f), gx, glm::vec3(1.f, 0, 0));
    GLboolean transpose = GL_FALSE;
    glUniformMatrix4fv(matrix_model_id, 1, transpose, glm::value_ptr(matrix_model));

    //glDrawArrays(GL_TRIANGLES, 0, 12);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, (const void *) indices2);


    //matrix_model.traslacion(-0.5, 0.3, 0.1);
    matrix_model = glm::translate(glm::mat4(1.0f),  glm::vec3(-0.5, 0.3, 0.1));
    transpose = GL_FALSE;
    glUniformMatrix4fv(matrix_model_id, 1, transpose, glm::value_ptr(matrix_model));

    //glDrawArrays(GL_TRIANGLES, 0, 12);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, (const void *) indices2);

    glDisableVertexAttribArray(vertex_id);
    glutSwapBuffers();
}

void setup() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    CreateShaderProgram("../vertexShader_modelo.vs", "../fragmentShader.fs", p_id);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glBindAttribLocation(p_id, vertex_id, "aPos");
    matrix_model_id = glGetUniformLocation(p_id, "matrix_model");
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0);
        case 'a': tx -= 0.1; break;
        case 'd': tx += 0.1; break;
        case 'w': ty += 0.1; break;
        case 's': ty -= 0.1; break;
        case 'x': gx += 0.1; break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(400, 300);

    int nWindow = glutCreateWindow("test");

    glutKeyboardFunc( keyboard );
    glutDisplayFunc( Redisplay );

    //glewExperimental = GL_TRUE;
    glewInit();

    setup();
    glutMainLoop();
    return 0;
}
