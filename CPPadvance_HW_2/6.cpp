#include <iostream>

typedef int usg_t;

class Fraction
{
private :
	usg_t numerator;
	usg_t denominator;
public:
	Fraction (usg_t & num , usg_t & den) : numerator{num}, denominator{den}
	{}
	 usg_t gcd_user(usg_t a, usg_t b);
	 void printSimplify();
	 ~Fraction()
	 {}
};
void Fraction::printSimplify()
{
	usg_t div = gcd_user(denominator, numerator);
	std::cout << "The Simplify Fraction : " << (numerator / div) << " / " << (denominator / div) << std::endl;
}
usg_t Fraction::gcd_user(usg_t a, usg_t b)
{
	while (b)
	{
		usg_t temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main()
{
	usg_t num, den;
	std::cin >> num >> den;
	Fraction fac (num, den);
	fac.printSimplify();
	return 0;
}
