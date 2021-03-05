#include <iostream>
#include<cstdlib>
#include<ctime>

typedef int usg_t;
static usg_t countingWon{ 0 };
constexpr usg_t LIMIT{ 101 };

int main()
{
	srand(usg_t(time(0)));
	usg_t countTime{ 1 };
	usg_t MAXTIME;
	std::cout << " How many time would you want Bob to try ? \n";
	std::cin >> MAXTIME;
		while ((countTime++) <= MAXTIME) 
		{
			std::cout << "\t\t\t ******\n";
			usg_t guessing_1{ rand() % LIMIT };
			usg_t guessing_2{ rand() % LIMIT };
			usg_t show_hiden;
			show_hiden = rand() % 2;
			usg_t displayed{ 0 };
				if (show_hiden == 0)
				{
					std::cout <<"Bob want to see Card 1, and it has Value : " <<guessing_1 << '\n';
					displayed = 1;
				}
				else if (show_hiden == 1)
				{
					std::cout <<"Bob want to see Card 2, and it has Value : " <<guessing_2 << '\n';
					displayed = 2;
				}
				usg_t choosing{ 0 };
		if ((displayed == 1) && (guessing_1 >= (LIMIT / 2)))
				choosing = 1;
		else if ((displayed == 2) && (guessing_2 >= (LIMIT / 2)))
				choosing = 2;
		else if ((displayed == 2) && (guessing_2 < (LIMIT / 2)))
				choosing = 1;
		else if ((displayed == 1) && (guessing_1 < (LIMIT / 2)))
				choosing = 2;
		std::cout << "BOB has choosen Card " << choosing << '\n';
		if (choosing == 1)
		{
			if (guessing_1 > guessing_2)
			{
						++countingWon;
						std::cout << "BOB WON" << std::endl;
			}
			else
						std::cout << "BOB LOSE" << std::endl;
		}
		else if (choosing == 2)
		{
		if (guessing_1 < guessing_2)
			{
						++countingWon;
						std::cout << "BOB WON" << std::endl;
			}
			else
						std::cout << "BOB LOSE" << std::endl;
		}
		}
		std::cout << "\t\t\t ******\n";
		std::cout << "BOB HAVE WON " << countingWon << " TIME " <<std::endl;
		std::cout << "BOB RATE WON : " << (countingWon * 1.0 * 100 / MAXTIME) << "%" << std::endl;
}
