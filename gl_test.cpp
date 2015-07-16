#include <iostream>
#include <Eigen/Core>
#include <GL/glut.h>

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char *argv[]){
    std::cout << "GL Test" << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
