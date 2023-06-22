/* Athabasca University

   Comp390 - Introduction to Computer Graphics
   Assignment 1 Question 2
   Name: Odiaka Evans
   Student ID: 3438562

   program drawing 5 houses from one draw home function
   using tranformation techniques and state maintaining

*/


#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>

typedef float vertex2D[2];

void drawHome(vertex2D* squar, vertex2D* triangl) {

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_TRIANGLES); //triangle for the top section of house
	glVertex2fv(triangl[0]);
	glVertex2fv(triangl[1]);
	glVertex2fv(triangl[2]);
	glEnd();


	glBegin(GL_QUADS); //square for the house
	glVertex2fv(squar[0]);
	glVertex2fv(squar[1]);
	glVertex2fv(squar[2]);
	glVertex2fv(squar[3]);
	glEnd();
}
void renderScene() {
	//performs rotation and translation on the single draw house function and applies antiailiasing techniques
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	vertex2D squareV[4] = { {-1,2},{1,2},{1,4},{-1,4} };
	vertex2D triV[3] = { {-1 - 0.2,4 }, {1 + 0.2,4}, {0, 4.5} };

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	drawHome(squareV, triV);
	glTranslatef(-2.0, 0.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 1);
	drawHome(squareV, triV);

	glTranslatef(-2.0, 0.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 1);
	drawHome(squareV, triV);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(2.0, 0.0, 0.0);
	glRotatef(-30.0, 0.0, 0.0, 1);
	drawHome(squareV, triV);

	glTranslatef(2.0, 0.0, 0.0);
	glRotatef(-30.0, 0.0, 0.0, 1);
	drawHome(squareV, triV);
	glPopMatrix();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	renderScene();
	glutSwapBuffers();
}
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0); //set display window color to white
	//glMatrixMode(GL_PROJECTION); //set projection parameters


}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
	glMatrixMode(GL_MODELVIEW);
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); //initialize glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //set display mode
	glutInitWindowPosition(50, 50);//set top left display windwo mode
	glutInitWindowSize(600, 600);
	int windowH = glutCreateWindow("Assignment 1 Program 2 Athabasca");
	glutSetWindow(windowH);
	init(); //execute initialization method
	glutDisplayFunc(display); //set graphics to display window+
	glutReshapeFunc(reshape);
	glutMainLoop(); //display everything and wait


}