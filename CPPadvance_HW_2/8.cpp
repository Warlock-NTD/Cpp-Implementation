#include <iostream>

typedef double usg_t;

int main()
{
	usg_t a, b, c;
	std::cin >> a >> b >> c;
	usg_t delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
	{
		std::cout << "Quadratic Equation has 2 complicate Solutions are : "<<'\n';
		std::cout << "x(1) = " << (-b / (2 * a)) << " + " << (sqrt(abs(delta)) / (2 * a)) << 'i' << '\n';
		std::cout << "x(2) = " << (-b / (2 * a)) << " - " << (sqrt(abs(delta)) / (2 * a)) << 'i' << '\n';
	}
	else if (delta == 0)
	{
		std::cout << "Quadratic Equation has 1 duplicate Solution is : "<<'\n';
		std::cout << "x = " << (-b / (2 * a)) << '\n';
	}
	else
	{
		std::cout << "Quadratic Equation has 2 Solutions are : " << '\n';
		std::cout << "x(1) = " << ((-b / (2 * a))+(sqrt(delta) / (2 * a))) <<'\n';
		std::cout << "x(2) = " << ((-b / (2 * a))-(sqrt(delta) / (2 * a))) <<'\n';
	}
	return 0;
}
