#include <iostream>
#include <GL/freeglut.h>


float vertices1[] = {
        0, 0, 0,    0.25, 0, 0.5,   0.5, 0, 0,
        0.25, 0, 0.5,   0.5, 0, 0,   0.25, 0.5, 0,
        0, 0, 0,    0.25, 0, 0.5,   0.25, 0.5, 0,
        0, 0, 0,    0.5, 0, 0,      0.25, 0, 0.5
};
float vertices2[] = {
        0, 0, 0,
        0.5, 0, 0,
        0.25, 0, 0.5,
        0.25, 0.5, 0,
};
int indices2[] = {
        0, 2, 1,
        2, 1, 3,
        0, 2, 3,
        0, 1, 3
};
GLuint p_id;

static void CreateShaderProgram (char* vertexShaderFile, char* fragmentShaderFile, GLuint &p_id) {
    char*	vertexShader   = readShader(vertexShaderFile);
    char*	fragmentShader = readShader(fragmentShaderFile);

    /* vertex shader */
    GLuint v_id = glCreateShader(GL_VERTEX_SHADER);
    if (v_id == 0)
        Error("Could not create vertex shader object");

    glShaderSource(v_id, 1, (const char**) &vertexShader, 0);
    CompileShader(v_id);

    /* fragment shader */
    GLuint f_id = glCreateShader(GL_FRAGMENT_SHADER);
    if (f_id == 0)
        Error("Could not create fragment shader object");

    glShaderSource(f_id, 1, (const char**) &fragmentShader, 0);
    CompileShader(f_id);

    /* program */
    p_id = glCreateProgram();
    if (p_id == 0)
        Error("Could not create program object");
    glAttachShader(p_id, v_id);
    glAttachShader(p_id, f_id);
    LinkProgram(p_id);

}


void Redisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, _argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 300);

    int nWindow = glutCreateWindow("test");

    CreateShaderProgram("vertexShader.vs", "fragmentShader.fs", p_id);


    //glutKeyboardFunc( SampleKeyboard );
    glutDisplayFunc( Redisplay );
    glutMainLoop();
    return 0;
}
