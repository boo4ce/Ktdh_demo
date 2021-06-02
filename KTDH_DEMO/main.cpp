#include "Axis.h"
#include <math.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
using namespace std;
GLfloat g_box;

Axis axisX = Axis(2, 0, 0, Point(0, 0, 0));
Axis axisY = Axis(0, 2, 0, Point(0, 0, 0));
Axis axisZ = Axis(0, 0, 2, Point(0, 0, 0));

//Axis randomAxis = Axis(1, 3, 2, Point(0, 0, -3.0));

//truc // trung canh
//Axis randomAxis = Axis(0, 0, 10, Point(1, 1, 0));

//truc // khac canh
Axis randomAxis = Axis(0, 0, 10, Point(3, 1, 0));

//truc toa do
//Axis randomAxis = Axis(0, 0, 10, Point(0, 0, 0));



FixedMatrix totalT;

Point leftTop = Point(-1, 1, -1);
Point rightTop = Point(-1, 1, 1);
Point leftBottom = Point(1, 1, 1);
Point rightBottom = Point(1, 1, -1);

FixedMatrix getTtMatrix(int x, int y, int z) {
	double tt[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) tt[i][j] = 1;
			else tt[i][j] = 0;

	tt[3][0] = x;
	tt[3][1] = y;
	tt[3][2] = z;

	return FixedMatrix(tt);
}

FixedMatrix getToyaMatrix(double sina, double cosa) {
	double mt[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) mt[i][j] = 1;
			else mt[i][j] = 0;

	mt[0][0] = cosa;
	mt[0][2] = -sina;
	mt[2][0] = sina;
	mt[2][2] = cosa;

	FixedMatrix(mt).printMatrix();
	return FixedMatrix(mt);
}

FixedMatrix getToxbMatrix(double sinb, double cosb) {
	double mt[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) mt[i][j] = 1;
			else mt[i][j] = 0;

	mt[1][1] = cosb;
	mt[1][2] = sinb;
	mt[2][1] = -sinb;
	mt[2][2] = cosb;

	return FixedMatrix(mt);
}

FixedMatrix getToztMatrix(double sint, double cost) {
	double mt[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) mt[i][j] = 1;
			else mt[i][j] = 0;

	mt[0][0] = cost;
	mt[0][1] = sint;
	mt[1][0] = -sint;
	mt[1][1] = cost;

	return FixedMatrix(mt);
}

void t_rotate(Axis axis, int angle) {
	//tinh tien ve goc toa do
	totalT = getTtMatrix(-axis.root.x, -axis.root.y, -axis.root.z).clone();

	//quay quanh truc oy goc -a
	totalT.multiWith(getToyaMatrix(-axis.sina, axis.cosa));

	//quay quanh truc ox goc b
	totalT.multiWith(getToxbMatrix(axis.sinb, axis.cosb));

	//quay quanh truc oz goc t
	totalT.multiWith(getToztMatrix(sin(angle), cos(angle)));

	//quay quanh truc ox goc -b
	totalT.multiWith(getToxbMatrix(-axis.sinb, axis.cosb));

	//quay quanh truc oy goc a
	totalT.multiWith(getToyaMatrix(axis.sina, axis.cosa));

	//tinh tien ve vi tri ban dau
	totalT.multiWith(getTtMatrix(axis.root.x, axis.root.y, axis.root.z));

	cout << "Total matrix: \n";
	totalT.printMatrix();
}

void rotate() {
	leftTop.matrix.multiWith(totalT);
	rightTop.matrix.multiWith(totalT);
	leftBottom.matrix.multiWith(totalT);
	rightBottom.matrix.multiWith(totalT);

	glutPostRedisplay();
	Sleep(100);
}

void drawRandomAxis(Axis axis) {
	glDisable(GL_LIGHTING);

	glColor3f(1.0, 1.0, 1.0);
	axis.draw();

	glEnable(GL_LIGHTING);
}

void drawRect() {
	glColor3f(1.0, 1.0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(leftTop.matrix.matrix[0][0], leftTop.matrix.matrix[0][1], leftTop.matrix.matrix[0][2]);
	glVertex3f(rightTop.matrix.matrix[0][0], rightTop.matrix.matrix[0][1], rightTop.matrix.matrix[0][2]);
	glVertex3f(leftBottom.matrix.matrix[0][0], leftBottom.matrix.matrix[0][1], leftBottom.matrix.matrix[0][2]);
	glVertex3f(rightBottom.matrix.matrix[0][0], rightBottom.matrix.matrix[0][1], rightBottom.matrix.matrix[0][2]);
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

void display(void)
{
	std::cout << "Run";
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glPushMatrix();
	glTranslatef(-2, -2, 0);
	DrawCoodinate();

	drawRandomAxis(randomAxis);
	/*glCallList(g_box);*/
	drawRect();
	glPopMatrix();

	rotate();

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
	t_rotate(randomAxis, 30);
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

	glutMainLoop();
	return 0;
}
