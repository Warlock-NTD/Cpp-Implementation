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
static map GameMap;
static map Present;
inline void setMapDefault(map& Game, usg_t n);
inline void showMap(map& Game);
inline void createGame(map& Pre, usg_t n, usg_t mine);
inline void setConer(map& Game, usg_t n);

int main(usg_t argc, char* argv[])
{
	srand(time(NULL));
	std::cout << "Choose the size of GameBoard [1,9] : ";
	usg_t n;
	std::cin >> n;
	if ((n >= 10) || (n <= 0)) return -1;
	std::cout << "Choose number of BOMB [1,9] : ";
	usg_t mine;
	std::cin >> mine;
	if ((mine >= 10) || (mine <= 0)) return -1;
	// start the game .
	setMapDefault(GameMap, n);
	createGame(Present, n,mine);
	// system("cls");
	showMap(GameMap);
	// showMap(Present);
	
	return 0;
}
inline void setConer(map& Game,usg_t n) 
{
	usg_t count{ 0 };
	if (!(Game.at(0).at(1) - MINE)) { ++count; };
	if (!(Game.at(1).at(1) - MINE)) { ++count; };
	if (!(Game.at(1).at(0) - MINE)) { ++count; };
	if ((count != 0) && (Game.at(0).at(0) != MINE))	Game.at(0).at(0) = (count + convert);
	count = 0;
	if (!(Game.at(0).at(n - 2) - MINE)) { ++count; };
	if (!(Game.at(1).at(n - 2) - MINE)) { ++count; };
	if (!(Game.at(1).at(n - 1) - MINE)) { ++count; };
	if ((count != 0) && (Game.at(0).at(n - 1) != MINE))	Game.at(0).at(n - 1) = (count + convert);
	count = 0;
	if (!(Game.at(n - 2).at(n - 2) - MINE)) { ++count; };
	if (!(Game.at(n - 1).at(n - 2) - MINE)) { ++count; };
	if (!(Game.at(n - 2).at(n - 1) - MINE)) { ++count; };
	if ((count != 0) && (Game.at(n - 1).at(n - 1) != MINE)) Game.at(n - 1).at(n - 1) = (count + convert);
	count = 0;
	if (!(Game.at(n - 2).at(0) - MINE)) { ++count; };
	if (!(Game.at(n - 2).at(1) - MINE)) { ++count; };
	if (!(Game.at(n - 1).at(1) - MINE)) { ++count; };
	if ((count != 0) && (Game.at(n - 1).at(0) != MINE)) Game.at(n - 1).at(0) = (count + convert);
}
inline void setMapDefault(map& Game, usg_t n)
{
	for (usg_t i = 0; i < n; ++i)
	{
		std::vector<c> temp;
		for (usg_t j = 0; j < n; ++j)
		{
			temp.push_back(NONE);
		}
		Game.push_back(temp);
	}
}
inline void createGame(map& Pre, usg_t n, usg_t mine)
{
	Pre = GameMap;
	while (mine--)
	{
		usg_t r = rand() % n;
		usg_t c = rand() % n;
		GameMap.at(r).at(c) = MINE;
	}
	setConer(GameMap,n);
	/*for (usg_t i = 1 ; i< n-1; ++i)
		for (usg_t j = 1; j < n-1; ++j)
		{
			usg_t count{ 0 };
			if ()
		}*/
}
inline void showMap(map& Game)
{
	for (auto i : Game) {
		for (auto j : i)
			std::cout << j << ' ';
		std::cout << '\n';
	}
}

