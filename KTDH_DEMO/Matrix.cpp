#include "Matrix.h"
#include <iostream>
FixedMatrix::FixedMatrix()
{

}

FixedMatrix::FixedMatrix(double matrix[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

FixedMatrix::~FixedMatrix() {

}

FixedMatrix FixedMatrix::clone() {
	double res[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res[i][j] = matrix[i][j];
		}
	}

	return FixedMatrix(res);
}

void FixedMatrix::multiWith(FixedMatrix a) {
	double res[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				res[i][j] += matrix[i][k] * a.matrix[k][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = res[i][j];
			//std::cout << matrix[i][j];
		}
		//std::cout << std::endl;
	}
}

void FixedMatrix::printMatrix() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}