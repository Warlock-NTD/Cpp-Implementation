#include <iostream>
#include<cmath>

typedef double usg_t;

int main()
{
	usg_t weight, height;
	std::cin >> weight >> height;
	std::cout <<"BMI : "<< (weight / pow(height, 2)) << " (kg/m2)\n";
	system("pause");
}
