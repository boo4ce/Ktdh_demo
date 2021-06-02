#pragma once
#include "Matrix.h"
#include "glut.h"

class Point {
public:

	GLfloat x, y, z;
	FixedMatrix matrix;

	Point();
	Point(GLfloat x, GLfloat y, GLfloat z);
	~Point();
};