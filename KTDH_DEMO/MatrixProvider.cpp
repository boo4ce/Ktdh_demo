#include "MatrixProvider.h"

FixedMatrix MatrixProvider::getTlMatrix(double scaleX, double scaleY, double scaleZ) {
	double tt[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i == j) tt[i][j] = 1;
			else tt[i][j] = 0;

	tt[0][0] = scaleX;
	tt[1][1] = scaleY;
	tt[2][2] = scaleZ;

	return FixedMatrix(tt);
}


FixedMatrix MatrixProvider::getTtMatrix(int x, int y, int z) {
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

FixedMatrix MatrixProvider::getToyaMatrix(double sina, double cosa) {
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

FixedMatrix MatrixProvider::getToxbMatrix(double sinb, double cosb) {
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

FixedMatrix MatrixProvider::getToztMatrix(double sint, double cost) {
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
