#include <iostream>
#define KEVIN 273.15

typedef double usg_t;


int main()
{
	usg_t MIN, MAX, STEP;
	std::cin >> MIN >> MAX >> STEP;
	std::cout << "Fahrenheit\t\t\tCELSIUS\t\t\tAbsolute Value" << '\n';
	usg_t count{ 0 };
	usg_t run = MIN;
	while (count <= ((MAX-MIN)/STEP ))
	{
		usg_t F, C, K;
		F = run;
		C = (F - 32) * 5 / 9;
		K = C + KEVIN;
		std::cout << F << "\t\t\t\t" << C << "\t\t\t" << K << std::endl;
		if (run <= (MAX - STEP))
			run += STEP;
		else
			run = MAX;
		++count;
	}
	return 0;
}
