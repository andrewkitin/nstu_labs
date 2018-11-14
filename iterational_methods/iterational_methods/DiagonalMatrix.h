#pragma once
#include <cstdlib>
#include <string>

typedef float real;

class DiagonalMatrix {
	real* D; // valuable diagonals
	real* shift_L; //where is lower diagonals
	real* shift_U; //where is upper diagonals
	int m, n; //count of null diagonals, matrix size

public:
	
	DiagonalMatrix();
	DiagonalMatrix(std::string* pathToDiag, std::string* pathToShift);
	~DiagonalMatrix();
};


