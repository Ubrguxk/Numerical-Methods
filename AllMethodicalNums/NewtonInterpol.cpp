#include <iostream>
#include "ReadingMatrixFromTab.h"
#include <string>

/*

2. Newton Interpolation- multinomial interpetation

This function calculates the Interpolation function based on the joins from given file and x provided by the user.
To calcualte this you need to solve this equation:
𝑊𝑛(𝑥) = ∑𝑏𝑘 * 𝑝𝑘(𝑥)

Where:
𝑝𝑘 = ∏ (𝑥 − 𝑥𝑖)
𝑏𝑘 = ∑ (𝑓(𝑥𝑖))/(∏ (𝑥𝑖 − 𝑥𝑗))

Where:
- xi: value of x currently calculated
- xj: the indexes of all points besides xi
- x: given by the user

1. 𝑝𝑘 = ∏ (𝑥 − 𝑥𝑖)
To better understand this equation let's expand it for for i = 1 and i = 2
p1 = (x - x0) (x - x1)
p2 = (x - x0) (x - x1) (x - x2)
For every i the value of x - xi and all i before are multiplied. The results are list of pk
for p0 = 1

2. 𝑏𝑘 = ∑ (𝑓(𝑥𝑖))/(∏ (𝑥𝑖 − 𝑥𝑗))
To better understand this equation let's expand it for i = 1 and i = 2

b1 = f(x0)/(x0 - x1) + f(x1)/(x1-x0)
b2 = f(x0)/(x0 - x1)(x0 - x2) + f(x1)/(x1-x0)(x1 - x2) + f(x2)/(x2-x0)(x2-x1)

for b0 = f(x0)
For each k, a sum of elements is calculated. These elements consist of every function value f(xi) divided by the product of differences between xi and all other points xj, excluding xi itself.

After calculating the values of bk and pk for each interpolation point, they are multiplied by their corresponding values and added together, forming the sum:
b1 * p1 + b2 * p2 + b3 * p3 + ....
*/

float* pk(float** Tab, float x, int sizeTab) {
	/*
	This function calculates all of the pk values for the Interpolation.

	Parameters:
	- Tab: Values of joints used in the calculations.
	- x: Provided by user, for this point the interpolation is calculated.
	- sizeTab: Number of joints.

	This function creates a b matrix, and fills it with pk values corresponing to the indexes of p.
	*/
	// Create an array to save results fill it with ones
	float* p = new float[sizeTab];
	std::fill(p, p + sizeTab, 1.0);
	
	// p0 = 1
	p[0] = 1.0;

	// Calculate every pk for i indexes 
	for (int i = 1; i < sizeTab; i++) {
		// Multiply by x - xj, where j are all of the indexes before i
		for (int j = 0; j < i; j++) {
			p[i] *= x - Tab[j][0];
		}
	}
	return p;

}

float* bk(float** Tab, int sizeTab) {
	/*
	This function calculates all of the bk values for the Interpolation.

	Parameters:
	- Tab: Values of joints used in the calculations.
	- sizeTab: Number of joints.

	This function creates a b matrix, and fills it with bk values corresponing to the indexes of b.
	*/

	// Create an array to save results and fill it with zeros
	float* b = new float[sizeTab];
	std::fill(b, b + sizeTab, 0.0);

	// b0 = f(x0)
	b[0] = Tab[0][1];

	// Calculating every bk for each i index
	for (int i = 1; i < sizeTab; i++) {
		// Arrays to store temporary values for each calculation
		float* tops = new float[i + 1];
		float* bottoms = new float[i + 1];

		// To guarentee correct results of dividing the method of common denominator is used
		// Calculating every fraction in each bk amd seving it temporarily
		for (int j = 0; j <= i; j++) {
			tops[j] = Tab[j][1];
			bottoms[j] = 1.0;

			for (int k = 0; k <= i; k++) {
				if (j != k) {
					bottoms[j] *= (Tab[j][0] - Tab[k][0]);
				}
			}
		}

		// Calculating the common denomiator
		float denominator = 1.0;
		for (int j = 0; j <= i; j++) {
			denominator *= bottoms[j];
		}

		// Calculate the sum of all the fractions
		float allTops = 0.0;

		for (int j = 0; j <= i; j++) {
			allTops += tops[j] * (denominator / bottoms[j]);
		}

		// Calculate bk and store it in the array
		b[i] = allTops / denominator;

		// delete temporary viarbles
		delete[] tops;
		delete[] bottoms;

	}

	return b;
}

float interPolNew(std::string file) {
	/*
	This function conducts all the necessary calculations for Lagrange Interpolation.

	Parameters:
	- file: File from which the joint points are read

	This function reads the file to obtain the necessary joint points, prompts the user to input the value of x,
	and then calls the appropriate functions to calculate the result of interpolation.
	*/

	// Read file for needed joints and create a tab
	int sizeTab = sizeOfTab(file);
	float** Tab = readFile(2, file);

	// User provides interpolated x

	float x;
	std::cout << " Please put in calculated x: " << std::endl;
	std::cin >> x;

	std::cout << " Number of joints read from file: " << sizeTab << std::endl;
	std::cout << " Inputed x = " << x << std::endl;

	float* Bresults = bk(Tab,sizeTab);
	float* Presults = pk(Tab, x,sizeTab);

	// Calculate every bk * pk and add it to the finish 
	float finish = 0.0;
	for (int i = 0; i < sizeTab; i++) {
		std::cout << "For i = " << i << " bk = " << Bresults[i] << ", pk = " << Presults[i] << " , bk * pk = " << Bresults[i] * Presults[i] << std::endl;
		finish += Bresults[i] * Presults[i];
		//std::cout << finish << std::endl;
	}
	std::cout << " Interpolation result = " << finish << std::endl;
	return finish;
}