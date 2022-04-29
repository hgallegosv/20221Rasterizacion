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


void Redisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, _argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 300);

    int nWindow = glutCreateWindow("test");

    //glutKeyboardFunc( SampleKeyboard );
    glutDisplayFunc( Redisplay );
    glutMainLoop();
    return 0;
}
