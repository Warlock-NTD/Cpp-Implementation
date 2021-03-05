#include <iostream>
#include<vector>

typedef int usg_t;

int main()
{
	usg_t N;
	std::cin >> N;
	for (usg_t i = 1; i <= N; ++i)
	{
		for (usg_t j = 1; j <= i; ++j)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
	system("pause");
}
