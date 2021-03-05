#include <iostream>

typedef int usg_t;

int main()
{
	usg_t num_1, num_2;
	std::cin >> num_1 >> num_2;
	if ((num_1 % 7 == 0) && (num_2 % 7 == 0))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	system("pause");
}
