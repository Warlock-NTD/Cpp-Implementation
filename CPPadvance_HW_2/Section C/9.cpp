#include <iostream>

typedef long usg_t;

int main()
{	
	usg_t N;
	std::cin >> N;
	usg_t minX, minY;
	std::cin >> minX >> minY;
	--N;
	while (N--)
	{
		usg_t tempX, tempY;
		std::cin >> tempX >> tempY;
		minX = (minX < tempX) ? minX : tempX;
		minY = (minY < tempY) ? minY : tempY;
	}
	std::cout << (minX * minY);
	return 0;
}
