#include <iostream>

typedef int usg_t;

int main()
{
	usg_t N;
	std::cin >> N;
	usg_t compare = N / static_cast<int>(sqrt(N));
	if (compare == sqrt(N))
		std::cout << N << " is Square Number\n";
	else
		std::cout << N << " is not Square Number\n";
	return 0;
}
