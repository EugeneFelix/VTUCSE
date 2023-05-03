#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "stdio.h"
#include<GL/glut.h>
#include<GL/gl.h>
int x1, x2, y1, y2;
void init() {
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,200.0,0,150.0);
    glMatrixMode(GL_MODELVIEW);
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.4,0.1); //RGB as FFF(float from 0.0 to 1.0 only
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2i(180,15);
        glVertex2i(10,145);
    glEnd();
    glFlush();
}

void handler() {
    printf("EEEEnter Coooordinates...!\n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(500,150);
    glutInitWindowSize(1080,960);
    glutCreateWindow("GL Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

#endif
