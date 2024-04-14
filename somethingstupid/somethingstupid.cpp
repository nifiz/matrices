#include <iostream>
#include "matrix.h"

int main()
{
	Math::matrix m(5,5, 12.5);
	std::cout << m[0][0] << '\n';
	{ m[0][0] = 5; }
	std::cout << m[0][0];
}