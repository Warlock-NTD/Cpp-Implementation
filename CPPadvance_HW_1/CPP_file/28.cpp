#include <iostream>
#include<vector>
#define HOURS 24
#define ClOCK 12

typedef int usg_t;

int main()
{
	for (usg_t i = 0; i < HOURS; ++i)
	{
		if (i < ClOCK)
		{
			if (i == 0)
				std::cout << ClOCK << "midnight" << '\n';
			else
				std::cout << i << "am" << '\n';
		}
		if (i >= ClOCK)
		{
			if (i == ClOCK)
				std::cout << ClOCK << "noon" << '\n';
			else
				std::cout << (i - ClOCK) << "pm" << '\n';
		}
	}
	system("pause");
}
