#include <fstream>
#include <iostream>

float** readFile(int numOfRows, std::string fileRead) {
	std::fstream file;
	file.open(fileRead, std::ios::in);
	if (!file.good()) {
		exit(0);
	}

	int sizeTab;
	file >> sizeTab;

	float** Tab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		Tab[i] = new float[numOfRows];
	}

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < numOfRows; j++) {
			file >> Tab[i][j];
		}

	}

	file.close();
	return Tab;
}

int sizeOfTab(std::string fileRead) {
	std::fstream file;
	file.open(fileRead, std::ios::in);
	if (!file.good()) {
		exit(0);
	}
	int sizeTab;
	file >> sizeTab;
	file.close();
	return sizeTab;
}

void readTab(float** Tab, int sizeTab,int rows) {

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < rows; j++) {
			if (Tab[i][j] == 0) {
				std::cout << "0 ";
			}
			else {
				std::cout << Tab[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
