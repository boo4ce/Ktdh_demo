#pragma once

class FixedMatrix {
public:
	double matrix[4][4];

	FixedMatrix();
	FixedMatrix(double matrix[4][4]);
	~FixedMatrix();

	void multiWith(FixedMatrix);
	FixedMatrix clone();
	void printMatrix();
};