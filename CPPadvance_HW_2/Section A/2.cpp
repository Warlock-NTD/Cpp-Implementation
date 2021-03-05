#include <iostream>

typedef int usg_t;

int main()
{
	usg_t k;
	std::cin >> k;
	while (true)
	{
		k /= 3;
		if (k < 3)
		{
			std::cout << k << std::endl;
			break;
		}
	}

	system("pause");
}
