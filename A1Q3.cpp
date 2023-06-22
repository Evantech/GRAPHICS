/* Athabasca University

   Comp390 - Introduction to Computer Graphics
   Assignment 1 Question 3
   Name: Odiaka Evans
   Student ID: 3438562

  program 3 color and shading

*/




#include "gl/glut.h"



// initialize

void initialize() {

	// set background color

	glClearColor(1.0, 1.0, 1.0, 0.0);

}



// render

void render() {

	// setting color of four vertices should be set to red, green, blue, and yellow, respectively
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glBegin(GL_QUADS);

	glColor4f(0.0, 1.0, 0.0, 0.0);//green
	glVertex2f(-2.0, 2.0);

	glColor4f(0.0, 0.0, 1.0, 0.0); //blue
	glVertex2f(2.0, 2.0);

	glColor4f(0.9, 0.9, 0.1, 0.0); //yellow color
	glVertex2f(2.0, -2.0);
	glColor4f(1.0, 0.0, 0.0, 0.0); //red
	glVertex2f(-2.0, -2.0);
	glEnd();

}



// display registry

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();



	// viewing

	gluLookAt(0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



	render();



	glutSwapBuffers();

}



// reshape registry

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);

	glMatrixMode(GL_MODELVIEW);

}



// main program

void main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);



	int windowHandle = glutCreateWindow("Athabasca University - Comp390 A3");

	glutSetWindow(windowHandle);



	glutDisplayFunc(display);

	glutReshapeFunc(reshape);



	initialize();



	glutMainLoop();

}