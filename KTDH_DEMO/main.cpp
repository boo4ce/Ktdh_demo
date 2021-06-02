#include "Axis.h"
#include "MatrixProvider.h"
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
using namespace std;
GLfloat g_box;

MatrixProvider provider;

Axis axisX = Axis(2, 0, 0, Point(0, 0, 0));
Axis axisY = Axis(0, 2, 0, Point(0, 0, 0));
Axis axisZ = Axis(0, 0, 2, Point(0, 0, 0));

//mo comment de chon truc

//truc bat ki
//Axis randomAxis = Axis(3, 0.5, 2, Point(0, 0, -2));

//truc // trung canh
//Axis randomAxis = Axis(0, 0, 10, Point(1, 1, 0));

//truc // khac canh
//Axis randomAxis = Axis(0, 0, 10, Point(1, 0.3, 0));

//truc toa do
Axis randomAxis = Axis(0, 0, 10, Point(0, 0, 0));



FixedMatrix totalT;

Point leftTop = Point(-0.5, 0.5, -0.5);
Point rightTop = Point(-0.5, 0.5, 0.5);
Point leftBottom = Point(0.5, 0.5, 0.5);
Point rightBottom = Point(0.5, 0.5, -0.5);


double ini[4][4] = {
	{-0.5, 0.5, -0.5, 1},
	{-0.5, 0.5, 0.5, 1},
	{0.5, 0.5, 0.5, 1},
	{0.5, 0.5, -0.5, 1}
};

FixedMatrix coor = FixedMatrix(ini);

boolean pause = false;
boolean canRotate = true;

bool mouseLeftDown;
bool mouseRightDown;
bool mouseMiddleDown;
float mouseX, mouseY;
float cameraDistanceX;
float cameraDistanceY;
float cameraAngleX;
float cameraAngleY;
float cameraAngleZ;
float times = 1;

void t_rotate(Axis axis, int angle) {
	//tinh tien ve goc toa do
	totalT = provider.getTtMatrix(-axis.root.x, -axis.root.y, -axis.root.z).clone();

	//quay quanh truc oy goc -a
	totalT.multiWith(provider.getToyaMatrix(-axis.sina, axis.cosa));

	//quay quanh truc ox goc b
	totalT.multiWith(provider.getToxbMatrix(axis.sinb, axis.cosb));

	//quay quanh truc oz goc t
	totalT.multiWith(provider.getToztMatrix(sin(angle), cos(angle)));

	//quay quanh truc ox goc -b
	totalT.multiWith(provider.getToxbMatrix(-axis.sinb, axis.cosb));

	//quay quanh truc oy goc a
	totalT.multiWith(provider.getToyaMatrix(axis.sina, axis.cosa));

	//tinh tien ve vi tri ban dau
	totalT.multiWith(provider.getTtMatrix(axis.root.x, axis.root.y, axis.root.z));
}

void drawRandomAxis(Axis axis) {
	glDisable(GL_LIGHTING);

	glColor3f(1.0, 1.0, 1.0);
	axis.draw();

	glEnable(GL_LIGHTING);
}

void update() {
	leftTop.update();
	rightTop.update();
	leftBottom.update();
	rightBottom.update();
}

void drawRect() {
	glColor3f(1.0, 1.0, 0);
	glBegin(GL_POLYGON);

	//update();

	//glVertex3f(rightTop.x, rightTop.y, rightTop.z);
	//glVertex3f(leftBottom.x, leftBottom.y, leftBottom.z);
	//glVertex3f(rightBottom.x, rightBottom.y, rightBottom.z);
	//glVertex3f(leftTop.x, leftTop.y, leftTop.z);

	glVertex3f(coor.matrix[0][0], coor.matrix[0][1], coor.matrix[0][2]);
	glVertex3f(coor.matrix[1][0], coor.matrix[1][1], coor.matrix[1][2]);
	glVertex3f(coor.matrix[2][0], coor.matrix[2][1], coor.matrix[2][2]);
	glVertex3f(coor.matrix[3][0], coor.matrix[3][1], coor.matrix[3][2]);

	glEnd();
}

GLuint MakeCube()
{
	GLuint boxDisplay;
	boxDisplay = glGenLists(1);
	glNewList(boxDisplay, GL_COMPILE);

	glBegin(GL_QUADS);
	//// Front Face
	//glNormal3f(0.0, 0.0, 1.0f);
	//glVertex3f(-1.0f, -1.0f, 1.0f);
	//glVertex3f(1.0f, -1.0f, 1.0f);
	//glVertex3f(1.0f, 1.0f, 1.0f);
	//glVertex3f(-1.0f, 1.0f, 1.0f);

	 //Back Face
	//glNormal3f(0.0, 0.0, -1.0f);
	//glVertex3f(-1.0f, -1.0f, -1.0f);
	//glVertex3f(-1.0f, 1.0f, -1.0f);
	//glVertex3f(1.0f, 1.0f, -1.0f);
	//glVertex3f(1.0f, -1.0f, -1.0f);

	//// Top Face
	//glNormal3f(0.0, 0.1, 0.0f);
	glVertex3f(leftTop.x, leftTop.y, leftTop.z);
	glVertex3f(rightTop.x, rightTop.y, rightTop.z);
	glVertex3f(leftBottom.x, leftBottom.y, leftBottom.z);
	glVertex3f(rightBottom.x, rightBottom.y, rightBottom.z);

	//// Bottom Face
	//glNormal3f(0.0, -1.0, 0.0f);
	//glVertex3f(-1.0f, -1.0f, -1.0f);
	//glVertex3f(1.0f, -1.0f, -1.0f);
	//glVertex3f(1.0f, -1.0f, 1.0f);
	//glVertex3f(-1.0f, -1.0f, 1.0f);

	////// Right face
	//glNormal3f(1.0, 0.0, 0.0f);
	//glVertex3f(1.0f, -1.0f, -1.0f);
	//glVertex3f(1.0f, 1.0f, -1.0f);
	//glVertex3f(1.0f, 1.0f, 1.0f);
	//glVertex3f(1.0f, -1.0f, 1.0f);

	////// Left Face
	//glNormal3f(-1.0, 0.0, 0.0f);
	//glVertex3f(-1.0f, -1.0f, -1.0f);
	//glVertex3f(-1.0f, -1.0f, 1.0f);
	//glVertex3f(-1.0f, 1.0f, 1.0f);
	//glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glEndList();
	return boxDisplay;
}

void DrawCoodinate()
{
	glDisable(GL_LIGHTING);
	
	glColor3f(1, 0, 0);
	axisX.draw();
	glColor3f(0, 1, 0);
	axisY.draw();
	glColor3f(0, 0, 1);
	axisZ.draw();

	glEnable(GL_LIGHTING);
}

void translate(double x, double y, double z) {
	coor.multiWith(provider.getTtMatrix(x, y, z));
	glutPostRedisplay();
}

void scale(double x, double y, double z) {
	coor.multiWith(provider.getTlMatrix(x, y, z));
	glutPostRedisplay();
}

void rotate() {
	/*leftTop.matrix.multiWith(totalT);
	rightTop.matrix.multiWith(totalT);
	leftBottom.matrix.multiWith(totalT);
	rightBottom.matrix.multiWith(totalT);*/

	coor.multiWith(totalT);
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	if (canRotate) {
		glRotatef(cameraAngleX, 0, 1, 0);
		glRotatef(cameraAngleY, 1, 0, 0);
		glRotatef(cameraAngleZ, 0, 0, 1);
	}
	else {
		translate(cameraAngleX * 0.1f, cameraAngleY * 0.1f, cameraAngleZ * 0.1f);
	}

	glPushMatrix();
	//glTranslatef(cameraDistanceX, cameraAngleY, 0);

	DrawCoodinate();

	drawRandomAxis(randomAxis);
	drawRect();

	glPopMatrix();

	if (!pause) {
		rotate();
	}

	Sleep(100);
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	g_box = MakeCube();
	t_rotate(randomAxis, 20);
}

void reset() {
	//cameraAngleX = 0;
	//cameraAngleY = 0;
	//cameraAngleZ = 0;
	if (!canRotate) {
		cameraAngleX = 0;
		cameraAngleY = 0;
		cameraAngleZ = 0;
	}
}

void mouseCB(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON) {
	
		if (state == GLUT_DOWN)
		{
			pause = !pause;
			glutPostRedisplay();
		}

		return;
	}

	mouseX = x;
	mouseY = y;
	times = 1;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			mouseLeftDown = true;
		}
		else if (state == GLUT_UP) {
			mouseLeftDown = false;
			reset();
		}
	} else if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN)
		{
			mouseRightDown = true;
		}
		else if (state == GLUT_UP) {
			mouseRightDown = false;
			reset();
		}
	}

	/*
		 * Mouse wheel control graphic zoom
	*/
	//else if (state == GLUT_UP && button == GLUT_WHEEL_UP)
	//{
	//	times = 0.008f + 1;
	//	glutPostRedisplay();
	//}

	//else if (state == GLUT_UP && button == GLUT_WHEEL_DOWN)
	//{
	//	times = -0.008f + 1;
	//	glutPostRedisplay();
	//}
}

void mouseMotionCB(int x, int y)
{
	if (mouseLeftDown)
	{
		cameraAngleY += (x - mouseX) * 0.1f;
		cameraAngleX += (y - mouseY) * 0.1f;
		mouseX = x;
		mouseY = y;
		glutPostRedisplay();
	}

	if (mouseRightDown)
	{
		/*cameraDistanceX = (x - mouseX) * 0.01f;
		cameraDistanceY = -(y - mouseY) * 0.01f;*/
		cameraAngleZ += (x - mouseX) * 0.1f;
		mouseY = y;
		mouseX = x;
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'z':
			scale(0.5, 0.5, 0.5);
			break;
		case 'x':
			scale(2, 2, 2);
			break;
		case 'l':
			reset();
			canRotate = !canRotate;
			cout << "Lock Rotate: " << canRotate << endl;
			break;
	}
}

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("spinning rectangle");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseCB);
	glutMotionFunc(mouseMotionCB);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
