#pragma once
#include "Matrix.h"

class MatrixProvider
{
public:
	//Tinh tien
	static FixedMatrix getTtMatrix(int x, int y, int z);
	//Quay oy goc a
	static FixedMatrix getToyaMatrix(double sina, double cosa);
	//Quay ox goc b
	static FixedMatrix getToxbMatrix(double sinb, double cosb);
	//Quay oz goc t
	static FixedMatrix getToztMatrix(double sint, double cost);
	//Ty le 
	static FixedMatrix getTlMatrix(double scaleX, double scaleY, double scaleZ);
	//Bien dang
	static FixedMatrix getBdMatrix(double b, double c, double d, double f, double g, double i);
};

