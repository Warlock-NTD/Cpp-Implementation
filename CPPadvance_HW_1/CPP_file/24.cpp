#include <iostream>

#define Div2 4
#define Div3 100
#define Default_sec 6
#define Default_sheed 733773
#define Default_day 1
#define Default_month 1
#define Default_year 2010
#define Leap_macro 366
#define Year_macro 365 

typedef int usg_t;
inline bool checkLeapGlobal(const usg_t& y);
inline void printSec(usg_t& d);
usg_t getSheed(usg_t& d, usg_t& m, usg_t& y);
usg_t solvingDelta(usg_t& del, const std::string& sign);

int main()
{
	usg_t day, month, year;
	std::cin >> day >> month >> year;
	usg_t sheed = getSheed(day, month, year);
	usg_t secKey;
	if (sheed < Default_sheed)
	{
		usg_t delta = Default_sheed - sheed;
		delta %= 7;
		const std::string Q{ "past" };
		secKey = solvingDelta(delta, Q);
	}
	else if (sheed > Default_sheed)
	{
		usg_t delta = sheed - Default_sheed;
		delta %= 7;
		const std::string Q{ "future" };
		secKey = solvingDelta(delta, Q);
	}
	else
		secKey = Default_sec;
	printSec(secKey);
	
	system("pause");
}
inline bool checkLeapGlobal(const usg_t& y)
{
	if ((y % Div3 != 0) && (y % Div2 == 0))
		return true;
	else if ((y % Div3 == 0) && ((y / Div3) % Div2 == 0))
		return true;
	return false;
}
inline void printSec(usg_t& d)
{
	switch (d)
	{
	case  1:
		std::cout << "Sunday" << '\n';
		break;
	case 2:
		std::cout << "Monday" << '\n';
		break;
	case 3:
		std::cout << "Tuesday" << '\n';
		break;
	case 4:
		std::cout << "Wednesday" << '\n';
		break;
	case 5:
		std::cout << "Thursday" << '\n';
		break;
	case 6:
		std::cout << "Friday" << '\n';
		break;
	case 7:
		std::cout << "Saturday" << '\n';
		break;
	}
}
usg_t getSheed(usg_t& d, usg_t& m, usg_t& y)
{
	usg_t numSheed{ 0 };
	for (usg_t i = 1; i < y; ++i)
		if (checkLeapGlobal(i))
			numSheed += 366;
		else
			numSheed += 365;
	for (short i = 1; i < m; ++i)
	{
		if (i == 2)
		{
			numSheed += 28;
			if (checkLeapGlobal(y))
				numSheed += 1;
			continue;
		}
		else if (((i % 2 == 0) && (i >= 8)) || ((i % 2 != 0) && (i < 8)))
		{
			numSheed += 31;
		}
		else if (((i % 2 != 0) && (i >= 8)) || ((i % 2 == 0) && (i < 8)))
		{
			numSheed += 30;
		}
	}
	numSheed += d;
	return numSheed;
}
usg_t solvingDelta(usg_t& del, const std::string & sign)
{
	usg_t circle1[] {6,7,1,2,3,4,5};
	usg_t circle2[] {6,5,4,3,2,1,7};
	if (sign == "past")
		return circle2[del];
	else if (sign == "future")
		return circle1[del];
}

