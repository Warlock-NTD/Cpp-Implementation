#include <iostream>

typedef int usg_t;

int main()
{
	usg_t a, b;
	std::cin >> a >> b ;
	usg_t com{ 2 };
	usg_t exp_a{ 0 }, exp_b{ 0 };
	usg_t LCM{ 1 };
	while (true)
	{
		if ((a % com != 0) && (b % com != 0)) {
			if ((exp_a != 0) || (exp_b != 0))
			{
				LCM *= (pow(com, std::max(exp_a, exp_b)));
				exp_a = 0, exp_b = 0;
				if (a == 1 && b == 1)
					break;
			}
			++com;
		}
		else if (a % com == 0) {
			a /= com;
			++exp_a;
		}
		else if (b % com == 0)
		{
			b /= com;
			++exp_b;
		}
	}
	std::cout << "Least common multiple : " << LCM << '\n';
	return 0;
}
