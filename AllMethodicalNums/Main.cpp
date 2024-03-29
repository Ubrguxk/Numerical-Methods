#include <iostream>
#include "LagrangeInterpol.h"
#include "NewtonInterpol.h"
#include "GaussMethod.h"
#include <fstream>

/*		Numerical Methods - various task

This main is the centre where given 

1. Lagrange Interpolation - multinomial interpetation 

This function calculates the Interpolation function based on the joins from given file and x provided by the user. 
It contains two steps:
1.	I𝑖 (𝑥) = ∏ (𝑥 − 𝑥𝑗) / (𝑥𝑖 − 𝑥𝑗) 
2.  𝐿𝑛(𝑥) = ∑ 𝑓(𝑥𝑖)*I𝑖(𝑥) 

2. Newton Interpolation- multinomial interpetation 

This function calculates the Interpolation function based on the joins from given file and x provided by the user.
To calcualte this you need to solve this equation:
𝑊𝑛(𝑥) = ∑𝑏𝑘 * 𝑝𝑘(𝑥)

Where:
𝑝𝑘 = ∏ (𝑥 − 𝑥𝑖)
𝑏𝑘 = ∑ (𝑓(𝑥𝑖))/(∏ (𝑥𝑖 − 𝑥𝑗))

3. Solving system of linear equations using Gauss method. Not Including where diagonal can be 0

4. Solving system of linear equations using Gauss method. Including where diagonal can be 0

5.Solving system of linear equations using LU decomposition 

*/

int main() {
	while (true) {
		std::string file = "GaussData-1.txt";
		std::ifstream fileRead(file);
		if (!fileRead.good()) {
			std::cout << "File not found" << std::endl;
			exit(0);
		}
		std::cout << "Methodical numbers - implementation in C++" << std::endl << std::endl;
		std::cout << "Currently read file - " << file << std::endl << std::endl;
		std::cout << "q - Lagrange Interpolation" << std::endl;
		std::cout << "w - Newton Interpolation" << std::endl;
		std::cout << "e - Solving system of linear equations using Gauss method" << std::endl << "		^ Not Including where diagonal can be 0" << std::endl;
		std::cout << "r - Solving system of linear equations using Gauss method" << std::endl << "		^ Including where diagonal can be 0" << std::endl;
		std::cout << "t - Solving system of linear equations using LU decomposition" << std::endl;
		std::cout << "z - exit" << std::endl;
		char x;
		float res;
		std::cin >> x;
		switch (x) {
			case 'q':
				res = interPolLag(file);
				break;
			case 'w':
				res = interPolNew(file);
				break;
			case 'e':
				break;
			case 'r':
				break;
			case 't':
				break;
			case 'z':
				exit(0);
				break;
			default:
				std::cout << "There is not such an option" << std::endl;
				break;
		}	
		std::cout << std::endl;
	}

}