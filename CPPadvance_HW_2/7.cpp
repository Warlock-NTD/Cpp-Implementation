#include <iostream>

typedef double usg_t;

int main()
{
	usg_t a1, b1, c1, a2, b2, c2;
	std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	usg_t D = a1 * b2 - a2 * b1;
	usg_t Dx = c1 * b2 - c2 * b1;
	usg_t Dy = a1 * c2 - a2 * c1;
	if (D != 0)
		std::cout << "There is 1 Answer of the Multiple Equations :\n"
		<<"x = " << Dx / D << '\n' << "y = " << Dy / D << std::endl;
	else
	{
		if (Dx != 0 || Dy != 0)
			std::cout << " No Answer Satisfy the Multiple Equations" << std::endl;
		else
			std::cout << "Many Uncountable Answer of Multiple Equations" << std::endl;
	}
	return 0;
}
/*
* a1 x + b1 y = c1
* a2 x + b2 y = c2
* D = a1b2 - a2b1
* Dx = c1b2 - c2b1
* Dy = a1c2 - a2c1
* D # 0 --> x = Dx/D, y = Dy/D
* D = 0 , Dx || Dy # 0 --> /0
* D = 0 , Dx = Dy = 0 --> many
*/
