#ifndef TRI_ROT_H_INCLUDED
#define TRI_ROT_H_INCLUDED

#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#define ORX 0.0
#define ORY 0.0

int
    x, y, rFlag = 0, shapeC;
float
    th = 0.0, trX = 0.0, trY = 0.0;

void draw_pixel(float x1, float y1) {
    glColor3f(0.0,1.0,0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2f(x1, y1);
    glEnd();
}

void shape(int shape) {
    if(shape == 1) {
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(100,100);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2f(250,400);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2f(400,100);
        glEnd();
    }
    if(shape == 5) {
        glBegin(GL_POLYGON);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(100,100);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2f(250,400);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2f(400,100);
        glEnd();
    }
    if(shape == 2) { // Filled Rectangle
        glBegin(GL_QUADS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(-55.0f, 55.0f);
            glVertex2f(-55.0f, 0.0f);
            glColor3f(0.0, 1.0, 0.0);
            glVertex2f(55.0f, 0.0f);
            glVertex2f(55.0f, 55.0f);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if(rFlag == 1 | rFlag == 2 | rFlag == 3 | rFlag == 4) {
        trX = 0.0;
        trY = 0.0;
        th += 0.1;
        draw_pixel(ORX, ORX);
    }
    if(rFlag == 5 | rFlag == 6 | rFlag == 7 | rFlag == 8) {
        trX = x;
        trY = y;
        th += 0.1;
        draw_pixel(x, y);
    }
    glTranslatef(trX, trY, 0.0);
    glRotatef(th,0.0, 0.0, 1.0);
    glTranslatef(-trX, -trY, 0.0);
    glColor4ub(0, 0, 255, 100);
    shape(shapeC);
    glutPostRedisplay();
    glutSwapBuffers();
}

void rotateMenu(int option) {
    switch(option) {
        case 1: rFlag = 1;
                shapeC = 1;
                break;
        case 2: rFlag = 2;
                shapeC = 2;
                break;
        case 3: rFlag = 3;
                shapeC = 3;
                break;
        case 4: rFlag = 4;
                shapeC = 4;
                break;
        case 5: rFlag = 5;
                shapeC = 5;
                break;
        case 6: rFlag = 6;
                shapeC = 6;
                break;
        case 7: rFlag = 7;
                shapeC = 7;
                break;
        case 8: rFlag = 8;
                shapeC = 8;
                break;
        case 10: exit(0);
    }
}

void handler() {
    printf("Enter points to rotate through\n");
    scanf("%d %d", &x, &y);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Create and Rotate Triangle");
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutCreateMenu(rotateMenu);
        glutAddMenuEntry("Rotate Hollow Triangle around the origin", 1);
        glutAddMenuEntry("Rotate Filled Rectangle the origin", 2);
        glutAddMenuEntry("Rotate Hollow Triangle the origin", 3);
        glutAddMenuEntry("Rotate Hollow Rectangle the origin", 4);

        glutAddMenuEntry("Rotate Filled Triangle around a fixed point", 5);
        glutAddMenuEntry("Rotate Filled Rectangle around a fixed point", 6);
        glutAddMenuEntry("Rotate Hollow Triangle around a fixed point", 7);
        glutAddMenuEntry("Rotate Hollow Rectangle around a fixed point", 8);
        glutAddMenuEntry("Stop Rotating", 9);
        glutAddMenuEntry("Say Goodbye", 10);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    glutMainLoop();
}
#endif
