#include <iostream>

typedef double usg_t;

int main()
{
	usg_t a, b, c;
	std::cin >> a >> b >> c;
	if (((a + b) > c) && ((b + c) > a) && ((c + a) > b))
	{
		std::cout << "Perimeter :" << (a + b + c) << '\n';
		std::cout << "Type : ";
		if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) ||
			(pow(a, 2) + pow(c, 2) == pow(b, 2)) ||
			(pow(b, 2) + pow(c, 2) == pow(a, 2)))
			std::cout << "Right ";
		if (a == b && a == c)
			std::cout << "Equilateral ";
		else if ((a == b && a != c) || (c == a && c != b) || (b == c && b != a))
			std::cout << "Isosceles ";
		std::cout << "Triangle\n";
	}
	else
		std::cout << "Not Triangle\n";
	return 0;
}
