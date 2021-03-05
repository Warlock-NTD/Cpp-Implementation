#include <iostream>

typedef int usg_t;

int main()
{
	usg_t N;
	std::cin >> N;
	for (usg_t i = 0; i < N; ++i)
	{
		for (usg_t j = 0; j < (2*N-1); ++j)
		{
			if ((j < (N - 1 - i)) || j > (N - 1 + i))
				std::cout << ' ';
			else
				std::cout << '*';	
		}
		std::cout << std::endl;
	}
	
	system("pause");
}
