#include <iostream>
#include "ReadingMatrixFromTab.h"
#include <string>

void readTab(int** Tab, int sizeTab) {

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < sizeTab + 1; j++) {
			std::cout << Tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int* GaussMethod(std::string file) {
	/*
	This function conducts all the necessary calculations for Lagrange Interpolation.

	Parameters:
	- file: File from which the joint points are read

	This function reads the file to obtain the necessary joint points, prompts the user to input the value of x,
	and then calls the appropriate functions to calculate the result of interpolation.
	*/

	// Read file for needed joints and create a tab
	int sizeTab = sizeOfTab(file);
	int** Tab = readFile(sizeTab+1, file);

	std::cout << " Provided file: " << std::endl;
	readTab(Tab, sizeTab);

	return 0;

}