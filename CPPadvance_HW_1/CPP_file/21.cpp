#include <iostream>
#include<cmath>

typedef double usg_t;

int main()
{
	usg_t a, b, c;
	std::cin >> a >> b >> c;
	usg_t perimeter = (a + b + c) / 2;
	std::cout << sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c))
		<< std::endl;
	system("pause");
}
