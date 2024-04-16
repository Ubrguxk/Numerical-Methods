#include <iostream>
#include "ReadingMatrixFromTab.h"
#include "MatrixCalculations.h"
#include <string>

float** ReverseDiagonal(float** Tab, int sizeTab) {
	float** TrTab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		TrTab[i] = new float[sizeTab];
	}

	for (int i = 0; i < sizeTab; i++) {

		TrTab[i][i] = 1 / Tab[i][i];

		for (int j = 0; j < sizeTab; j++) {
			if (j != i) {
				TrTab[i][j] = 0;
			}
		}
	}

	return TrTab;
}

bool ifWeak(float** Tab, int sizeTab) {
	bool ifOneBigger = false;
	bool ifOneSmaller = false;

	for (int i = 0; i < sizeTab; i++) {
		float sum = NULL;
		float diagonal = Tab[i][i];
		for (int j = 0; j < sizeTab; j++) {
			if (i != j) {
				sum += Tab[i][j];
			}
		}
		//std::cout << i << ". Diagonal = " << diagonal << " Sum of all elements " << sum << std :: endl;

		if (diagonal > sum) {
			ifOneBigger = true;
		}
		if (diagonal < sum) {
			ifOneSmaller = true;
		}
	}
	if (ifOneSmaller == false && ifOneBigger == true) {
		return true;
	}
	else {
		return false;
	}

}

float* JacobieMethod(std::string file) {
	// Read file to get Linear Equations which will be calculated
	int sizeTab = sizeOfTab(file);
	float** Tab = readFile(sizeTab + 1, file);

	// Read given file 

	std::cout << " Provided file: " << std::endl;
	readTab(Tab, sizeTab, sizeTab + 1);

	// If weak

	if (ifWeak(Tab, sizeTab)) {
		std::cout << "Isnt weak" << std::endl;
	}
	else {
		std::cout << "Is weak" << std::endl;
	}

	// Iterations

	int x;
	std::cout << "Type how many ireratons: " << std::endl;
	std::cin >> x;

	//Matrixes
	float** U = TopTriangleMatrix(Tab, sizeTab);
	float** L = BottomTriangleMatrix(Tab, sizeTab);
	float** D = DiagonalMatrix(Tab, sizeTab);
	float** UL = addMatrix(U, L, sizeTab);
	float** D1 = ReverseDiagonal(D, sizeTab);

	std::cout << "U + L" << std::endl;
	readTab(UL, sizeTab, sizeTab);
	std::cout << "D-1" << std::endl;
	readTab(D1, sizeTab, sizeTab);

	// Iteration
	float* variables = new float[sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		variables[i] = 0;
	}
	std::cout << "Iterations: " << x << std::endl;

	for (int i = 0; i < x; i++) {
		// New X for current Iteratnion
		float* newX = new float[sizeTab];

		// Calculate new X
		for (int k = 0; k < sizeTab; k++) {
			// (L + U) * xi
			float sum = 0;
			for (int j = 0; j < sizeTab; j++) {
				if (k != j) {
					sum += UL[k][j] * variables[j];
				}
			}
			newX[k] = (-1 * D1[k][k]) * sum + D1[k][k] * Tab[k][sizeTab];
		}

		// Check the condition 
		float E = 0.001;

		bool ifCond = true;
		for (int k = 0; k < sizeTab; k++) {
			if (std::abs(newX[k] - variables[k]) >= E) {
				ifCond = false;
				break;
			}
		}

		if (ifCond) {
			std::cout << "Stop condition met after " << i + 1 << " iterations." << std::endl;
			break;
		}

		// Change results for current iteration
		for (int i = 0; i < sizeTab; i++) {
			variables[i] = newX[i];
		}

		delete[] newX;
	}

	std::cout << "Solution after " << x << " iterations:" << std::endl;
	for (int i = 0; i < sizeTab; i++) {
		std::cout << "x[" << i << "] = " << variables[i] << std::endl;
	}

	return variables;
}