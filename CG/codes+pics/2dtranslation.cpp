#include <Windows.h>
#include <glew.h>
#include <freeglut.h>
#include <iostream>
#include <math.h>

using namespace std;


void translateRectangle(int P[][2], int T[])
{
   
    glBegin(GL_LINE_LOOP);
    glVertex2f(P[0][0], P[0][1]);
    glVertex2f(P[1][0], P[0][1]);
    glVertex2f(P[1][0], P[1][1]);
    glVertex2f(P[0][0], P[1][1]);
        glEnd();
    // calculating translated coordinates
    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];

  
    glBegin(GL_LINE_LOOP);
    glVertex2f(P[0][0], P[0][1]);
    glVertex2f(P[1][0], P[0][1]);
    glVertex2f(P[1][0], P[1][1]);
    glVertex2f(P[0][0], P[1][1]);
    glEnd();
    glFlush();
 
}


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    int P[2][2] = { 50, 80, 120, 180 };
    int T[] = { 100, 100 }; // translation factor
      
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformaton Scaling ");
    init();

    translateRectangle(P, T);

    glutMainLoop();
    return 0;
}
