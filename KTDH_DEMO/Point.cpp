#include "Point.h"
#include <iostream>

Point::Point()
{
	x = 0; y = 0; z = 0;
}

Point::Point(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix.matrix[i][j] = 0;

	matrix.matrix[0][0] = x;
	matrix.matrix[0][1] = y;
	matrix.matrix[0][2] = z;
	matrix.matrix[0][3] = 1;
}

Point::~Point() {

}

void Point::update() {
	x = matrix.matrix[0][0];
	y = matrix.matrix[0][1];
	z = matrix.matrix[0][2];
}