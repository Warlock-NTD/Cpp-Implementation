#include <iostream>
#include<cstdlib>

typedef int usg_t;

int main()
{
	usg_t num_1, num_2;
	std::cin >> num_1 >> num_2;
	std::cout << "The Bigger : " << ((num_1 + num_2) + abs(num_1 - num_2)) / 2 << std::endl;
	system("pause");
}
