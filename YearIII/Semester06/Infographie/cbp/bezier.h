#ifndef BEZIER_H_INCLUDED
#define BEZIER_H_INCLUDED

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1416

typedef struct WorldCoordPoint3D {
	GLfloat x, y, z;
};

void binomialCoeff(GLint n, GLint *coefficients) {
	for (int i = 0; i <= n; i++) {
		coefficients[i] = 1;
		for (int j = n; j >= k + 1; j--)
			coefficients[k] *= j;
		for (int j = n - k; j >= 2; j--)
			coefficients[k] /= j;
	}
}

void bezierCurve(WorldCoordPoint3D *controlPoints, GLint numControlPoints, GLint numBezierCurvePoints) {
	WorldCoordPoint3D bezierCurvePoint;
	GLfloat u;
	GLint n = numControlPoints - 1;
	GLint *coefficients, k;
	coefficients = new GLint[numControlPoints];
	
	binomialCoeff(numControlPoints - 1, coefficients);
	
	glBegin(GL_LINE_STRIP);
	for (k = 0; k <= numBezierCurvePoints; k++) {
		u = GLfloat(k) / GLfloat(numBezierCurvePoints);
		GLfloat blendFunction;
		bezierPoint->x = bezierPoint->y = bezierPoint->z = 0.0;
		for (int k = 0; k < numControlPoints; k++) {
			blendFunction = coefficients[k] * pow(u, k) * pow(1 - u, n - k);
			bezierPoint->x += controlPoints[k].x * blendFunction;
			bezierPoint->y += controlPoints[k].y * blendFunction;
			bezierPoint->z += controlPoints[k].z * blendFunction;
		}
		glVertex2f(bezierCurvePoint.x, bezierCurvePoint.y);
	}
	glEnd();
	delete[] coefficients;
}

void displayFunction() {
	GLint numControlPoints = 4, numBezierCurvePoints = 20;
	float theta = 0;
	WorldCoordPoint3D controlPoints[4] = { { 20, 100, 0 },{ 30, 110, 0 },{ 50, 90, 0 },{ 60, 100, 0 } };
	controlPoints[1].x += 10 * sin(theta * PI / 180.0);
	controlPoints[1].y += 5 * sin(theta * PI / 180.0);
	controlPoints[2].x -= 10 * sin((theta + 30) * PI / 180.0);
	controlPoints[2].y -= 10 * sin((theta + 30) * PI / 180.0);
	controlPoints[3].x -= 4 * sin((theta) * PI / 180.0);
	controlPoints[3].y += sin((theta - 30) * PI / 180.0);
	theta += 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5);
	glPushMatrix();
	glLineWidth(5);
	glColor3f(255 / 255, 153 / 255.0, 51 / 255.0); //Indian flag: saffron color code
	for (int i = 0; i < 8; i++) {
		glTranslatef(0, -0.8, 0);
		bezierCurve(controlPoints, numControlPoints, numBezierCurvePoints);
	}
	glColor3f(1, 1, 1); //Indian flag: white color code
	for (int i = 0; i < 8; i++) {
		glTranslatef(0, -0.8, 0);
		bezierCurve(controlPoints, numControlPoints, numBezierCurvePoints);
	}
	glColor3f(19 / 255.0, 136 / 255.0, 8 / 255.0); //Indian flag: green color code
	for (int i = 0; i < 8; i++) {
		glTranslatef(0, -0.8, 0);
		bezierCurve(controlPoints, numControlPoints, numBezierCurvePoints);
	}
	glPopMatrix();
	glColor3f(0.7, 0.5, 0.3);
	glRectf(1, 1, 1, 1);
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void handler() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bezier Curve");
	glutDisplayFunc(displayFunction);
	glutMainLoop();
}

#endif // BEZIER_H_INCLUDED