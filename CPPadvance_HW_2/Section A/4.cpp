#include <iostream>
#define Div2 4
#define Div3 100
#define Default_day_medium 30
#define Default_day_long 31
#define Default_day_short_Leap 29
#define Default_day_short 28
#define Default_month 12
#define Leap_macro 366
#define Year_macro 365
#define special_month 2
#define middle_month 8

typedef int usg_t;
inline bool checkLeapGlobal(const usg_t& y);
usg_t getSheed(usg_t& d, usg_t& m, usg_t& y);
usg_t excSheed_y(usg_t& sheed);
usg_t excSheed_m(usg_t& sheed, const usg_t& y);

int main()
{
	usg_t day, month, year;
	std::cin >> day >> month >> year;
	usg_t sheed = getSheed(day, month, year);
	while (true)
	{
		usg_t k;
		std::cin >> k;
		if (!k)
			break;
		usg_t sheed_temp = sheed + k;
		usg_t y = excSheed_y(sheed_temp);
		usg_t m = excSheed_m(sheed_temp, y);
		usg_t d = sheed_temp;
		std::cout << d << " / " << m << " / " << y << '\n';
	}
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
usg_t getSheed(usg_t& d, usg_t& m, usg_t& y)
{
	usg_t numSheed{ 0 };
	for (usg_t i = 1; i <= y; ++i)
		if (checkLeapGlobal(i))
			numSheed += Leap_macro;
		else
			numSheed += Year_macro;
	for (short i = 1; i < m; ++i)
	{
		if (i == special_month)
		{
			numSheed += Default_day_short;
			if (checkLeapGlobal(y))
				numSheed += 1;
			continue;
		}
		else if (((i % 2 == 0) && (i >= middle_month)) || ((i % 2 != 0) && (i < middle_month)))
		{
			numSheed += Default_day_long;
		}
		else if (((i % 2 != 0) && (i >= middle_month)) || ((i % 2 == 0) && (i < middle_month)))
		{
			numSheed += Default_day_medium;
		}
	}
	numSheed += d;
	return numSheed;
}
usg_t excSheed_y(usg_t& sheed)
{
	usg_t y{ 1 };
	while (true)
	{
		if (checkLeapGlobal(y))
		{
			sheed -= Leap_macro;
			if (sheed < Leap_macro)
				break;
			++y;
		}
		else
		{
			sheed -= Year_macro;
			if (sheed < Year_macro)
				break;
			++y;
		}
	}
	return y;
}
usg_t excSheed_m(usg_t& sheed , const usg_t & y)
{
	usg_t m{ 1 };
	while (true)
	{
		if (m == special_month)
		{
			if (checkLeapGlobal(y) && (sheed <= Default_day_short_Leap))
				break;
			else if (!checkLeapGlobal(y) && (sheed <= Default_day_short))
				break ;
			if (checkLeapGlobal(y))
			{
				sheed -= Default_day_short_Leap;
				++m;
				continue;
			}
			else
			{
				sheed -= Default_day_short;
				++m;
				continue;
			}
		}
		else if (((m % 2 == 0) && (m >= middle_month)) || ((m % 2 != 0) && (m < middle_month)))
		{
			if ( sheed <= Default_day_long)
				break;
			sheed -= Default_day_long;
			++m;
		}
		else if (((m % 2 != 0) && (m >= middle_month)) || ((m % 2 == 0) && (m < middle_month)))
		{
			if (sheed <= Default_day_medium)
				break;
			sheed -= Default_day_medium;
			++m;
		}
	}
	return m ;
}
