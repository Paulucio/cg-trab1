#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <iostream>
#include "tinyxml2/tinyxml2.h"
#include "sources/janela.h"
#include "sources/quadrado.h"
#include "sources/funcoes.h"

using namespace std;

//Global Variables
Janela MainWindow;
Quadrado Square;
bool DRAWN_FLAG = false, ALTERATION_STATE = false, INSIDE_SQUARE = false;
GLfloat mx_click, my_click;

//Main function
int main(int argc, char** argv)
{
    readXMLFile(argv[1], MainWindow, Square);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(MainWindow.getWidth(),MainWindow.getHeight());
    glutInitWindowPosition(100,100);
    glutCreateWindow(MainWindow.getTitle().c_str());
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}