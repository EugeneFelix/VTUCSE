#ifndef CUBE_SPIN_H_INCLUDED
#define CUBE_SPIN_H_INCLUDED

#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>

/* GLOBAL DECLARATION BEGIN*/
static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;
GLfloat vertices[][3] = {{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
                        {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
                        {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
                        };
GLfloat normals[][3] = {{-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
                        {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, {-1.0, -1.0, 1.0},
                        {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
                        };
GLfloat colors[][3] = {{1.0, 0.0, 0.0}, {1.0, 0.0, 0.0},
                        {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0},
                        {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}
                        };
/* GLOBAL DECLARATION END*/

void polygon(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
        glColor3fv(colors[a]);
        glNormal3fv(normals[a]);
        glVertex3fv(vertices[a]);
        glColor3fv(colors[a]);
        glNormal3fv(normals[b]);
        glVertex3fv(vertices[b]);
        glColor3fv(colors[a]);
        glNormal3fv(normals[c]);
        glVertex3fv(vertices[c]);
        glColor3fv(colors[a]);
        glNormal3fv(normals[d]);
        glVertex3fv(vertices[d]);
    glEnd();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void controls_mouse(int btn, int state, int x, int y) {
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1 ;
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
        polygon(0, 3, 2, 1);
        polygon(2, 3, 7, 6);
        polygon(0, 4, 7, 3);
        polygon(1, 2, 6, 5);
        polygon(4, 5, 6, 7);
        polygon(0, 1, 5, 4);
    glFlush();
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void spinner() {
    theta[axis] += 0.2;
    if(theta[axis] > 360.0)
        theta[axis] -= 360.0;
    display();
    glutPostRedisplay();
}
void handler() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1, 1, 1, 1);
    glutInitWindowPosition(500,150);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating a cube...");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinner);
    glutMouseFunc(controls_mouse);
    glutMainLoop();
}
#endif
