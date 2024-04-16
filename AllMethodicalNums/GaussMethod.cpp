#include <iostream>
#include "ReadingMatrixFromTab.h"
#include <string>

bool if0onDiagonal(float** Tab, int sizeTab) {
	// 0 false 1 true
	for (int i = 0; i < sizeTab; i++) {
		if (Tab[i][i] == 0.0) {
			std::cout << " 0 on diagonal. Check your file. " << std::endl;
			return 1;
		}
	}
	return 0;
}

float** simplifyTab(float**& Tab, int sizeTab) {

	for (int j = 0; j < sizeTab - 1; j++) {
		for (int i = j + 1; i < sizeTab; i++) {
			float denominator = Tab[i][j] / Tab[j][j];
			for (int k = 0; k < sizeTab + 1; k++) {
				Tab[i][k] = Tab[i][k] - denominator * Tab[j][k];
			}
		}
	}
	std::cout << "After Alterations: " << std::endl;
	readTab(Tab, sizeTab, sizeTab+1);
	return Tab;
}

float* calculateVariables(float** Tab, int sizeTab) {
	float* Variables = new float[sizeTab];
	Variables[0] = Tab[sizeTab - 1][sizeTab] / Tab[sizeTab - 1][sizeTab - 1];
	std::cout << "x0 = " << Variables[0] << std::endl;

	for (int i = 1; i < sizeTab; i++) {
		float top = Tab[sizeTab - 1 - i][sizeTab];

		for (int j = 0; j < i; j++) {
			top -= Tab[sizeTab - 1 - i][sizeTab - 1 - j] * Variables[j];
		}

		Variables[i] = top / Tab[sizeTab - 1 - i][sizeTab - 1 - i];
		std::cout << "x" << i << " = " << Variables[i] << std::endl;
	}
	return Variables;
}

float* GaussMethod(std::string file) {
	/*
	This function conducts all the necessary calculations for Lagrange Interpolation.

	Parameters:
	- file: File from which the joint points are read

	This function reads the file to obtain the necessary joint points, prompts the user to input the value of x,
	and then calls the appropriate functions to calculate the result of interpolation.
	*/

	// Read file to get Linear Equations which will be calculated
	int sizeTab = sizeOfTab(file);
	float** Tab = readFile(sizeTab+1, file);

	std::cout << " Provided file: " << std::endl;
	readTab(Tab, sizeTab,sizeTab+1);

	// Control check if Diagonal doesnt contain 0
	if (if0onDiagonal(Tab, sizeTab) == 1) { return 0; }

	Tab = simplifyTab(Tab, sizeTab);
	float* variables = calculateVariables(Tab, sizeTab);

	return variables;

}