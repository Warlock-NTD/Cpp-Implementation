#include <iostream>
#define div 10

typedef long long usg_t;


int main()
{
	usg_t number;
	std::cin >> number;
	usg_t sum{ 0 };
	while (number)
	{
		sum += number % div;
		number /= div;
	}
	std::cout << sum << std::endl;
	return 0;
}
