#include <iostream>
#include<vector>

typedef int usg_t;

int main()
{
	while (true)
	{
		usg_t N;
		std::cin >> N;
		if (N == (-1))
		{
			std::cout << "Bye" << std::endl;
			break;
		}
		std::cout << ((N >= 0) ? ((N % 5 == 0) ? (N / 5) : (-1)) : (-1)) << '\n';
	}

	system("pause");
}
