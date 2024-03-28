#include <fstream>

int** readFile(int numOfRows, std::string fileRead) {
	std::fstream file;
	file.open(fileRead, std::ios::in);
	if (!file.good()) {
		exit(0);
	}

	int sizeTab;
	file >> sizeTab;

	int** Tab = new int* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		Tab[i] = new int[2];
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