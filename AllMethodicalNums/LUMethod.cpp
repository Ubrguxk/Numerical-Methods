#include <iostream>
#include "ReadingMatrixFromTab.h"
#include "MatrixCalculations.h"
#include <string>

float* LUMethod(std::string file) {
	// Read file to get Linear Equations which will be calculated
	int sizeTab = sizeOfTab(file);
	float** Tab = readFile(sizeTab + 1, file);

	// Read given file 

	std::cout << " Provided file: " << std::endl;
	readTab(Tab, sizeTab, sizeTab + 1);

	// Create L and U matrix
	float** L = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		L[i] = new float[sizeTab];
	}
	float** U = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		U[i] = new float[sizeTab];
	}

	// Fill with 0 and 1
	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < sizeTab; j++) {
			L[i][j] = 0;
			U[i][j] = 0;
			if (i == j) {
				L[i][j] = 1;
			}
		}
	}

	// Fill U and L

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < sizeTab; j++) {
			if (i <= j) {
				float sum = 0.0;
				for (int k = 0; k < i; k++) {
					sum += L[i][k] * U[k][j];
				}
				U[i][j] = Tab[i][j] - sum;
			}
			if (i > j) {
				float sum = 0.0;
				for (int k = 0; k < j; k++) {
					sum += L[i][k] * U[k][j];
				}
				L[i][j] = (Tab[i][j] - sum) / U[j][j];
			}
		}
	}

	// Read them
	std::cout << "U Matrix: " << std::endl;
	readTab(U, sizeTab, sizeTab);
	std::cout << "L Matrix: " << std::endl;
	readTab(L, sizeTab, sizeTab);

	// Calculate Y vector and read
	float* Y = new float[sizeTab];
	Y[0] = Tab[0][sizeTab];
	for (int i = 1; i < sizeTab; i++) {
		float sum = 0.0;
		for (int j = 0; j < i; j++) {
			sum += L[i][j] * Y[j];
		}
		Y[i] = Tab[i][sizeTab] - sum;
	}

	for (int i = 0; i < sizeTab; i++) {
		std::cout << "Y[" << i << "] = " << Y[i] << std::endl;
	}
	std::cout << std::endl;

	// Calculate X vector and read 
	float* X = new float[sizeTab];

	for (int i = sizeTab - 1; i >= 0; i--) {
		float sum = 0.0;
		for (int j = i + 1; j < sizeTab; j++) {
			sum += U[i][j] * X[j];
		}
		X[i] = (Y[i] - sum) / U[i][i];
	}

	for (int i = 0; i < sizeTab; i++) {
		std::cout << "X[" << i << "] = " << X[i] << std::endl;
	}

	// Clean up memory
	for (int i = 0; i < sizeTab; ++i) {
		delete[] L[i];
		delete[] U[i];
	}
	delete[] L;
	delete[] U;

	return X;
}