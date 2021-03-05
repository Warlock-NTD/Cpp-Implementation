#include <iostream>

typedef int usg_t;

int main()
{
	usg_t num_1, num_2, num_3;
	std::cin >> num_1 >> num_2 >> num_3;
	if ((num_1 == num_2) && (num_2 == num_3))
		std::cout << "true";
	else
		std::cout << "false";
	return 0;
}
