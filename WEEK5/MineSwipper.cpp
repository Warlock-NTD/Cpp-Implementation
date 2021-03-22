#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<string>
#define cast static_cast<unsigned char>
typedef int usg_t;
typedef unsigned char c;
typedef std::vector<std::vector<c>> map;
c HIDE{ cast(254) }, NONE{ cast(240) }, MINE{ cast(229) }, convert{ cast(48) };
static map GameMap; // attemp of game
static map Present; // current alias of attemp .
static usg_t mine; // number of mine in Game .
static usg_t n; // size if the Game .
inline void setMapDefault(map& Game, usg_t n, c shape);
inline void showMap(map& Game);
inline void createGame();
inline void setFlag(map& Game, usg_t n);
inline void PlayRound();
inline void ResetGame();
inline void checkGame(const usg_t& x, const usg_t& y, bool& check);
inline void impact(usg_t x, usg_t y);
int main(usg_t argc, char* argv[])
{
	srand(time(NULL));
	ResetGame();
	return 0;
}
inline void setMapDefault(map& Game, usg_t n,c shape)
{
	for (usg_t i = 0; i < n; ++i)
	{
		std::vector<c> temp;
		for (usg_t j = 0; j < n; ++j)
		{
			temp.push_back(shape);
		}
		Game.push_back(temp);
	}
}
inline void createGame()
{
	usg_t i{ 0 };
	while (i<=mine)
	{
			usg_t r = rand() % n;
			usg_t c = rand() % n;
			if (GameMap.at(r).at(c) != MINE)
			{
				GameMap.at(r).at(c) = MINE;
				++i;
			}
	}
	setFlag(GameMap, n);
}
inline void showMap(map& Game)
{
	system("cls");
	for (auto i : Game) {
		for (auto j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}
}
inline void setFlag(map& Game, usg_t n)
{
	for (usg_t i = 0; i < n; ++i)
	{
		for (usg_t j = 0; j < n; ++j)
		{
			usg_t count{ 0 };
			for (usg_t a = i - 1; a <= i + 1; ++a)
			{
				if ((a < 0) || (a > (n - 1)))
					continue;
				for (usg_t b = j - 1; b <= j + 1; ++b) {
					if ((b < 0) || (b > (n - 1)))
						continue;
					if (Game.at(a).at(b) == MINE)
						++count;
				}
			}
			if ((count != 0) && (Game.at(i).at(j) != MINE)) Game.at(i).at(j) = (count + convert);
		}
	}
}
inline void PlayRound()
{
	bool checkLiving{ true };
	do 
	{
		showMap(Present);
		usg_t x, y;
		std::cout << "\nChoose the Position to sweep : \n" << "Row = ";
		std::cin >> x;
		std::cout << "Column = ";
		std::cin >> y;
		if ((x > n) || (y > n) || (x < 1) || (y < 1))
			continue;
		checkGame(x, y,checkLiving);
	} while (checkLiving);
	if (!checkLiving)
	{
		c Ques;
		std::cout << "Play Again ? Y/N\n";
		std::cin >> Ques;
		if (Ques == 'Y' || Ques == 'y')
		{
			ResetGame();
		}
		else
		{
			exit(0);
		}
	}
}
inline void checkGame(const usg_t &x, const usg_t &y, bool & check)
{
	if (GameMap.at(x - 1).at(y - 1) == MINE)
	{
		showMap(GameMap);
		std::cout << "\nYOU ARE DEAD !!!\n";
		check = false;
	}
	else
	{
		if (GameMap.at(x - 1).at(y - 1) != NONE) {
			Present.at(x - 1).at(y - 1) = GameMap.at(x - 1).at(y - 1);
		}
		else {
			impact(x, y);
		}
	}
}
inline void impact(usg_t x, usg_t y)
{
			for (usg_t a = x - 2; a <= x ; a++)
			{
				if ((a < 0) || (a > (n - 1)))
					continue;
				for (usg_t b = y - 2; b <= y ; b++) {
					if ((b < 0) || (b > (n - 1)))
						continue;
					if (GameMap.at(a).at(b) != MINE)
					{
						if (GameMap.at(a).at(b) != NONE)
						{
							Present.at(a).at(b) = GameMap.at(a).at(b);
						}
						else if ((GameMap.at(a).at(b) == NONE) && (Present.at(a).at(b) == HIDE))
						{
							Present.at(a).at(b) = GameMap.at(a).at(b);
							impact(a+1, b+1);
						}
					}
				}
			}
}
inline void ResetGame()
{
	GameMap.clear();
	Present.clear();
	system("cls");
	std::cout << "Choose the size of GameBoard in range [1,infinity] : ";
	std::cin >> n;
	if (n <= 1) exit(0);
	std::cout << "Choose number of BOMB [1," << (n * n) << "] : ";
	std::cin >> mine;
	if ((mine >= (n * n)) || (mine <= 0)) exit(0);
	setMapDefault(GameMap, n, NONE);
	setMapDefault(Present, n, HIDE);
	createGame();
	system("cls");
	PlayRound();
}
