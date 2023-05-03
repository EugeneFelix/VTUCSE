#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
float theta;
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.4,0.1); //RGB as FFF(float from 0.0 to 1.0 only
    glLineWidth(5);
    glBegin(GL_POLYGON);
        for(int i = 0; i < 360; i++) {
                theta = i * 3.1416/180;
                glVertex2f(250 + 150 * cos(theta), 250 + 150*sin(theta));
        }
    glEnd();
    glFlush();
}

void handler() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CIRCLE");
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1.0, 0.0, 1.0);
    glPointSize(1.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
#endif
