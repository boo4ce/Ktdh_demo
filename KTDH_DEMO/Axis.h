#pragma once
#include "glut.h"
#include "Point.h"
#include <math.h>

class Axis {
public:
	Point point1;
	Point point2;

	Point root;

	int a, b, c, d;

	double sina, cosa, sinb, cosb;

	Axis(int a, int b, int c, Point point);
	~Axis();

	void draw();
};
