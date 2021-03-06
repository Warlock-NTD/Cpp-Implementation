#include <iostream>
#define KEVIN 273.15

typedef double usg_t;


int main()
{
	usg_t F, C, K;
	std::cin >> F;
	C = (F - 32) * 5 / 9;
	K = C + KEVIN;
	std::cout << "Fahrenheit\t\t\tCELSIUS\t\t\tAbsolute Value" << '\n';
	std::cout << F << "\t\t\t\t" << C << "\t\t" << K << std::endl;
	return 0;
}
