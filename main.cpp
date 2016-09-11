#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <iostream>
#include "tinyxml2/tinyxml2.h"
#include "sources/janela.h"
#include "sources/quadrado.h"
#include "sources/funcoes.h"

using namespace tinyxml2;
using namespace std;

//Global Variables
Janela MainWindow;
Quadrado Square;
bool DRAWN_FLAG = false, ALTERATION_STATE = false, INSIDE_SQUARE = false;

//Functions for OpenGL
void init(void)
{
    /*Selecionar cor de fundo*/
    glClearColor(MainWindow.getBgColors(RED),MainWindow.getBgColors(GREEN),MainWindow.getBgColors(BLUE), 0.0);
    //cout << " Janela "<< MainWindow.getBgColors(RED) << MainWindow.getBgColors(GREEN) << MainWindow.getBgColors(BLUE) << endl;
    /* Inicializar sistema de viz.*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
//    glOrtho(0.0,MainWindow.getWidth(),0.0,MainWindow.getHeight(),-1.0,1.0);
}

void display(void)
{
    /*Limpar todos os pixels */
    glClear(GL_COLOR_BUFFER_BIT);

    if(DRAWN_FLAG)
    {
        glColor3fv((GLfloat*)(Square.getRGBColors()));
        glBegin(GL_POLYGON);
            for(int i = 0; i < 4; i++)
                glVertex3fv((GLfloat*)(Square.getVertices(i)));
        glEnd();
//        cout << Square.getVertices(3)[0] << endl;
    }
    glutSwapBuffers();
}

void idle(void)
{
    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
    int wx = MainWindow.getWidth();
    int hy = MainWindow.getHeight();
    float x_norm, y_norm;
    bool inside;
    y = hy - y; //Adjusting Y-Axis

    x_norm = x/float(wx);
    y_norm = y/float(hy);

//    x_norm = x;
//    y_norm = y;

    inside = Square.insideSquare(x_norm,y_norm); //Test if the mouse click was inside of the square

//    cout << "x: " << x << " y: " << y << endl;
//    cout << "xn: " << x_norm << " yn: " << y_norm << endl;
//    cout << "Vertices: x0 -> " << Square.getVertices(0,X_AXIS) << " y -> " << Square.getVertices(0,Y_AXIS) << endl
//         << "x1 -> " << Square.getVertices(1,X_AXIS) << " y -> " << Square.getVertices(1,Y_AXIS) << endl
//         << "x2 -> " << Square.getVertices(2,X_AXIS) << " y -> " << Square.getVertices(2,Y_AXIS) << endl
//         << "x3 -> " << Square.getVertices(3,X_AXIS) << " y -> " << Square.getVertices(3,Y_AXIS) << endl;

    if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN && DRAWN_FLAG == false)
    {
        DRAWN_FLAG = true;
        ALTERATION_STATE = true;
        Square.setXc(x_norm);
        Square.setYc(y_norm);
        Square.updateVertices();
    }

    if(inside)
        INSIDE_SQUARE = true;
    else INSIDE_SQUARE = false;

    if (key == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        if(inside)
        {
            DRAWN_FLAG = false;
            ALTERATION_STATE = false;
        }
    }
}

void mouseMotion(int x, int y)
{
    if(ALTERATION_STATE)
    {
        int wx = MainWindow.getWidth();
        int hy = MainWindow.getHeight();
        float x_norm, y_norm;

        y = hy - y; //Adjusting Y-Axis

        x_norm = x / float(wx);
        y_norm = y / float(hy);

//        x_norm = x;
//        y_norm = y;

        if (INSIDE_SQUARE)
        {
          //  cout << "Inside" << endl;
            Square.setXc(x_norm);
            Square.setYc(y_norm);
            Square.updateVertices();
        }
        //else cout << "Outside" << endl;
    }

}

//Main function
int main(int argc, char** argv)
{
    readXMLFile(argv[1], MainWindow, Square);
    Square.setLength(Square.getLength()/MainWindow.getWidth());

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