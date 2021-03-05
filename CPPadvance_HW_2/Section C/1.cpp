#include <iostream>

typedef int usg_t;

bool checkPrime(usg_t& num)
{
	for (usg_t i = 2; i <= (num / 2); ++i)
		if (!(num % i))
			return false;
	return true;
}
int main()
{
	usg_t num;
	std::cin >> num;
	if (checkPrime(num))
		std::cout << num << " is Prime\n";
	else
		std::cout << num << " not Prime\n";
	system("pause");
}
