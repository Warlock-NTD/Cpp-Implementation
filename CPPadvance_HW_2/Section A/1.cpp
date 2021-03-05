#include <iostream>
#define LIMIT 100

typedef int usg_t;

int main()
{
	// (a)

	// Best Solution 1 :
#if 0
	for (usg_t i = 0; i <= LIMIT - 2; i+=2)
		std::cout << i  << '\n';
#endif

	// Best Solution 2:
#if 0
	for (usg_t i = 0; i <= LIMIT; ++i)
	{
		i += (i  % 2);
		std::cout << i << '\n';
	}
#endif

	// (b)
#if 0
	usg_t n = LIMIT/2;
	usg_t i = 0;
	while (n--)
	{
		i += 2;
		std::cout << i << '\n';
	}
#endif

	// (c)
#if 0
	usg_t i{ 0 };
	while (i <= 100)
	{
		if (i % 2 == 0)
			std::cout << i << '\n';
		++i;
	}
#endif
	// (d)

#if 0
	usg_t i{ 0 };
	while (true)
	{
		if (i > 100)
			break;
		i += (i % 2);
		std::cout << i << '\n';
		++i;
	}
#endif
	// (e)

#if 0
	for (usg_t i = 0; i <= 100; ++i)
	{
		if (i % 2 != 0)
			continue;
		std::cout << i << '\n';
	}
#endif

	system("pause");
}
