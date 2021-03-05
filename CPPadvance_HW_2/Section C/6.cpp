#include <iostream>
#include <vector>

typedef int usg_t;

int main()
{
	usg_t N;
	std::cin >> N;
	std::vector<usg_t>num;
	for (usg_t i = 1; i <= N; ++i)
	{
		num.push_back(i);
		std::cout << i << '\t';
	}
	std::cout << std::endl;
	for (usg_t i = 0; i < (N-1); ++i)
	{
		num.push_back(num.at(0));
		num.erase(num.begin());
		for (auto it : num)
		{
			std::cout << it << '\t';
		}
		std::cout << std::endl;
	}
	system("pause");
}

