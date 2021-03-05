#include <iostream>
#include<string>

typedef int usg_t;
constexpr usg_t LIMIT{ 10 };

int main()
{
	usg_t c_{ 0 };
	std::string f0{ "a" };
	std::string f1{ "b" };
	std::string temp;
	std::cout << f0 << '\n' << f1 << '\n';
	while (c_ < LIMIT)
	{
		temp = f1;
		f1.insert(f1.end(), f0.begin(), f0.end());
		std::cout << f1 << '\n';
		f0 = temp;
		++c_;
	}
	return 0;
}
