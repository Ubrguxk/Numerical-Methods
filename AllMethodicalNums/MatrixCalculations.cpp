#include <string>


float** addMatrix(float** tab1, float** tab2,int sizeTab) {
	float** Tab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		Tab[i] = new float[sizeTab];
	}

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < sizeTab; j++) {
			Tab[i][j] = tab1[i][j] + tab2[i][j];
		}

	}

	return Tab;
}

float** TopTriangleMatrix(float** Tab, int sizeTab) {
	float** TrTab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		TrTab[i] = new float[sizeTab];
	}

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < i; j++) {
			TrTab[i][j] = 0;
		}
		for (int j = i; j < sizeTab; j++) {
			if (i != j) {
				TrTab[i][j] = Tab[i][j];
			}
			else {
				TrTab[i][j] = 0;
			}
		}
	}

	//readTab(TrTab,sizeTab,sizeTab);

	return TrTab;
}

float** BottomTriangleMatrix(float** Tab, int sizeTab) {
	float** TrTab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		TrTab[i] = new float[sizeTab];
	}

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < i; j++) {
			if (i != j) {
				TrTab[i][j] = Tab[i][j];
			}
			else {
				TrTab[i][j] = 0;
			}
		}
		for (int j = i; j < sizeTab; j++) {
			TrTab[i][j] = 0;
		}
	}

	//readTab(TrTab, sizeTab, sizeTab);

	return TrTab;
}

float** DiagonalMatrix(float** Tab, int sizeTab) {
	float** TrTab = new float* [sizeTab];
	for (int i = 0; i < sizeTab; i++) {
		TrTab[i] = new float[sizeTab];
	}

	for (int i = 0; i < sizeTab; i++) {
		for (int j = 0; j < sizeTab; j++) {
			if (i == j) {
				TrTab[i][j] = Tab[i][j];
			}
			else {
				TrTab[i][j] = NULL;
			}
		}
	}

	//readTab(TrTab, sizeTab, sizeTab);

	return TrTab;
}
