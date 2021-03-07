#include <iostream>

typedef int usg_t;

bool checkFibo(usg_t& n, usg_t & c)
{
	usg_t F{ 0 };
	usg_t exp{ 0 };
	while (F < n)
	{
		++exp;
		F = (1 / sqrt(5)) * (pow(((1 + sqrt(5)) / 2), exp) - pow(((1 - sqrt(5)) / 2), exp));
		if (F == n)
		{
			c = exp;
			return true;
		}
	}
	c = exp;
	return false;
}
int main()
{
	usg_t N;
	std::cin >> N;
	usg_t count;
	if (checkFibo(N, count))
		std::cout << N << " is Fibonacci\n";
	else
		std::cout << N << " is not Fibonacci\n";
	//std::cout << count << '\n';
	while (true)
	{
		std::cout << "F(" << count << ") = "
			<< (1 / sqrt(5)) * (pow(((1 + sqrt(5)) / 2), count) - pow(((1 - sqrt(5)) / 2), count)) << '\n';
		--count;
		if (count == 0)
			break;
	}
	return 0;
}
