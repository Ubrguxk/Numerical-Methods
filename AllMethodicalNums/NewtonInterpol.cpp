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
To better understand this equation i will write this for i = 0, i = 1 and i = 2
p0 = (x - x0)
p1 = (x - x0) (x - x1)
p2 = (x - x0) (x - x1) (x - x2)
For every i the value of x - xi and all i before are multiplied. The results are list of pk

2. 𝑏𝑘 = ∑ (𝑓(𝑥𝑖))/(∏ (𝑥𝑖 − 𝑥𝑗))
To better understand this equation i will write this for i = 0, i = 1 and i = 2

*/

int interPolNew(std::string file) {
	return 0;
}