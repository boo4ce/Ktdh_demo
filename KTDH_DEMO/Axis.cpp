#include "Axis.h"

Axis::Axis(int a, int b, int c, Point point)
{
	int x = point.x, y = point.y, z = point.z;

	point1 = Point(x - 5 * a, y - 5 * b, z - 5 * c);

	point2 = Point(x + 5 * a, y + 5 * b, z + 5 * c);

	root = point;

	this->a = a;
	this->b = b;
	this->c = c;

	this->d = -(a * x + b * y + c * z);

	this->sina = ((double)a / (sqrt(a * a + c * c)));
	this->cosa = ((double)c / (sqrt(a * a + c * c)));

	this->sinb = ((double)b / (sqrt(a * a + b * b + c * c)));
	this->cosb = (sqrt(a * a + c * c) / (sqrt(a * a + b * b + c * c)));
}

Axis::~Axis() {
	
};

void Axis::draw() {
	glBegin(GL_LINES);
	glVertex3f(point1.x, point1.y, point1.z);
	glVertex3f(point2.x, point2.y, point2.z);
	glEnd();
}