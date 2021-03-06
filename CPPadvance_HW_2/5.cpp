#include <iostream>

typedef int usg_t;

inline usg_t gcd_(usg_t a, usg_t b)
{
	if (b == 0)
		return a;
	return gcd_(b,a%b );
}
int main()
{
	usg_t a, b;
	std::cin >> a >> b ;
	usg_t GCD = gcd_(a, b);
	std::cout << "Greatest Common Divisor : " << GCD << '\n';
	return 0;
}
