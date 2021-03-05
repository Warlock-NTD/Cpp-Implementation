#include <iostream>
#include<vector>

typedef int usg_t;

int main()
{
	usg_t N;
	std::cin >> N;
	for (usg_t i = N; i >=1 ; --i)
	{
		for (usg_t j = 1; j <= i; ++j)
		{
			std::cout << '*';
		}
		std::cout << '\n';
	}
	system("pause");
}
