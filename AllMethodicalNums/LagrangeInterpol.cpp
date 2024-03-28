#include <iostream>
#include "ReadingMatrixFromTab.h"
#include <string>

/*
1. Lagrange Interpolation - multinomial interpretation

This function calculates the interpolation function based on the points read from the given file and the value of x provided by the user.
It consists of two steps:
1.   I𝑖 (𝑥) = ∏ (𝑥 − 𝑥𝑗) / (𝑥𝑖 − 𝑥𝑗)
2.   𝐿𝑛(𝑥) = ∑𝑓(𝑥𝑖)*I𝑖(𝑥)

Where:
- xi: value of x currently calculated
- xj: the indexes of all points besides xi
- x: given by the user

1. I𝑖 (𝑥) = ∏ (𝑥 − 𝑥𝑗) / (𝑥𝑖 − 𝑥𝑗)
To better explain this equation, I will write it for i = 0 and i = 1:

I0 = ((x-x1)(x-x2)(x-x3))/(x0 - x1)(x0 - x2)(x0 - x3)
I1 = ((x-x0)(x-x2)(x-x3))/(x1 - x0)(x1 - x2)(x1 - x3)

As you can see, the xj stands for every x value in points besides xi,
and xi is the point currently being calculated.

The results of these calculations will be the list of I values.

2. 𝐿𝑛(𝑥) = ∑𝑓(𝑥𝑖)*I𝑖(𝑥)
After calculating the list of Ii values, we need to multiply them by their corresponding f(xi) values
and sum up all of the multiplications.
*/

float senOne(int** Tab, int i, float x, int sizeTab) {
	/*
	This function calculates the numerator (top) of the Lagrange interpolation formula for a given x.

	Parameters:
	- Tab: Pointer to the array of joint points read from the file
	- i: Index of the current joint being considered
	- x: Interpolated x value input by the user
	- sizeTab: Number of joints in the array

	The Lagrange interpolation formula is:
	I𝑖 (𝑥) = ∏ (𝑥 − 𝑥𝑗) / (𝑥𝑖 − 𝑥𝑗)

	Where:
	- 𝑥𝑗: x value of the joint currently being iterated
	- 𝑥𝑖: x value of the current joint (𝑖-th joint)
	- 𝑥: Interpolated x value input by the user

	This function iterates through all joints and calculates the product (𝑥 − 𝑥𝑗) for all joints except the current one (𝑥𝑖).
	It then calculates the product (𝑥𝑖 − 𝑥𝑗) for all joints except the current one (𝑥𝑖).
	Finally, it returns the result of dividing the products, which represents the numerator of the Lagrange interpolation formula.
	*/
	float top = 1;
	float bottom = 1;

	for (int k = 0; k < sizeTab; k++) {
		if (k != i) {
			top *= x - Tab[k][0];
			bottom *= Tab[i][0] - Tab[k][0];
		}
		//std::cout << top << " " << bottom << std::endl;
	}
	float res = top / bottom;
	//std::cout << res << std::endl;
	return res;
}

float senTwo(int** Tab, float* Results, int sizeTab) {
	/*
	This function calculates the sum of the products of the function values (𝑓(𝑥𝑖)) and the individual Lagrange basis functions (I𝑖(𝑥)).

	Parameters:
	- Tab: Pointer to the array of joint points read from the file
	- Results: Pointer to the array of calculated Lagrange basis function values (I𝑖(𝑥))
	- sizeTab: Number of joints in the array

	This function iterates through all joints and calculates the product of the function value (𝑓(𝑥𝑖)) and the corresponding Lagrange basis function value (I𝑖(𝑥)).
	It then sums up all these products and returns the final interpolation result.
	*/
	float finish = 0;
	for (int i = 0; i < sizeTab; i++) {
		float tmp = Tab[i][1] * Results[i];
		finish += tmp;
	}
	return finish;
}

int interPolLag(std::string file) {
	/*
	This function conducts all the necessary calculations for Lagrange Interpolation.

	Parameters:
	- file: File from which the joint points are read

	This function reads the file to obtain the necessary joint points, prompts the user to input the value of x,
	and then calls the appropriate functions to calculate the result of interpolation.
	*/

	// Read file for needed joints and create a tab
	int sizeTab = sizeOfTab(file);
	int** Tab = readFile(2, file);

	// User provides interpolated x

	float x;
	std::cout << " Please put in calculated x: " << std::endl;
	std::cin >> x;

	std::cout << " Number of joints read from file: " << sizeTab << std::endl;
	std::cout << " Inputed x = " << x << std::endl;

	// Create array to store results of first equation
	float* firstResults = new float[sizeTab];

	// Calculate Ii for every joint
	for (int i = 0; i < sizeTab; i++) {
		firstResults[i] = senOne(Tab, i, x, sizeTab);
		// Uncomment below line for debugging if necessary
		// std::cout << firstResults[i] << std::endl;
	}

	// Calculate final result using equation 2
	float result = senTwo(Tab, firstResults, sizeTab);

	// Output the interpolation result
	std::cout << " Interpolation result = " << result << std::endl;
	return result;
}