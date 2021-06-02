#pragma once
#include "Matrix.h"

class MatrixProvider
{
public:
	static FixedMatrix getTtMatrix(int x, int y, int z);
	static FixedMatrix getToyaMatrix(double sina, double cosa);
	static FixedMatrix getToxbMatrix(double sinb, double cosb);
	static FixedMatrix getToztMatrix(double sint, double cost);
	static FixedMatrix getTlMatrix(double scaleX, double scaleY, double scaleZ);
};

