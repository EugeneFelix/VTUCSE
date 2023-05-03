#ifndef SCAN_LINE_H_INCLUDED
#define SCAN_LINE_H_INCLUDED

#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
float
    x1, x2, x3, x4, y1, y2, y3, y4;
int
    fillFlag = 0;

void edge_detect(float x1,float y1,float x2,float y2,int *le,int *re) {
    float mx, x, temp;
    int i;
    if ((y2 - y1) < 0) {
        temp = y1;
        y1 = y2;
        y2 = temp;
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if ((y2 - y1) != 0) mx = (x2 - x1) / (y2 - y1);
    else mx = x2 - x1;
    x = x1;
    for (i = y1; i <= y2; i++) {
        if (x < (float) le[i])
            le[i] = (int) x;
        if (x > (float) re[i])
            re[i] = (int) x;
        x += mx;
    }
}

void scanfill(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    int le[500], re[500];
    for (int i = 0; i < 500; i++) {
        le[i] = 500;
        re[i] = 0;
    }
    edge_detect(x1, y1, x2, y2, le, re);
    edge_detect(x2, y2, x3, y3, le, re);
    edge_detect(x3, y3, x4, y4, le, re);
    edge_detect(x4, y4, x1, y1, le, re);
    for (int y = 0; y < 500; y++)
        for (int i = (int) le[y]; i < (int) re[y]; i++) {
            glColor3f(0.0, 0.44, 0.12);
            glBegin(GL_POINTS);
                glVertex2i(i, y);
            glEnd();
        }
}
void display() {
    x1 = 200.0;
    y1 = 200.0;
    x2 = 100.0;
    y2 = 300.0;
    x3 = 200.0;
    y3 = 400.0;
    x4 = 300.0;
    y4 = 300.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
    if (fillFlag == 1)
        scanfill(x1, y1, x2, y2, x3, y3, x4, y4);
    glFlush();
}

void fillMenu(int option) {
    if (option == 1)
        fillFlag = 1;
    if (option == 2)
        fillFlag = 2;
    display();
}
void handler() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("SCAN_LINE ALGORITHM");
    glClearColor(1, 1, 1, 1);
    glColor3f(1.0, 0.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(display);
    glutCreateMenu(fillMenu);
        glutAddMenuEntry("Fill Polygon", 1);
        glutAddMenuEntry("Empty Polygon", 2);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}

#endif
