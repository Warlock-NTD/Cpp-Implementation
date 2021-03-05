#include <iostream>

typedef int usg_t;
#define Div 19
#define Div2 4
#define Div3 100
static bool check{ 0 };
inline void checkLeapLunar(const usg_t& y)
{
	usg_t dayExtra{ y % Div };
	if ((dayExtra == 0) || (dayExtra == 3) || (dayExtra == 6) || (dayExtra == 9) || (dayExtra == 11)
		|| (dayExtra == 14) || (dayExtra == 17))
	{
		std::cout << y << " is Lunar Leap Year\n";
		check = true;
	}
}
inline void checkLeapGlobal(const usg_t& y)
{
	if ((y % Div3 != 0) && (y % Div2 == 0))
	{
		std::cout << y << " is Global Leap Year\n";
		check = true;
	}
	else if ((y % Div3 == 0) && ((y / Div3) % Div2 == 0))
	{
		std::cout << y << " is Global Leap Year\n";
		check = true;
	}
}
int main()
{
	usg_t year;
	std::cin >> year;
	checkLeapGlobal(year);
	checkLeapLunar(year);
	if (!check)
		std::cout << year << " is Normal year .\n";
	system("pause");
}
