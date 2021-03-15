#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#define SUCCESS 0
#define KING 206
#define EMPTY 240
#define DANGER 33
typedef int usg_t;
typedef unsigned char s;
typedef std::vector<s> row;
typedef std::vector<std::vector<s>> chess;
static usg_t countKing{ 1 };
static usg_t n;
static chess myChess;
inline void arrangeChess(usg_t i, usg_t j, const usg_t& n, chess & MyChess);
inline bool check(chess& MyChess);
inline void resetChess(chess& MyChess);
int main()
{
	srand(time(NULL));
	std::cin >> n;
	for (usg_t i = 0; i < n; ++i)
	{
		row temp(n);
		for (usg_t j = 0; j<n;++j)
		{
			temp.at(j) = EMPTY;
		}
		myChess.push_back(temp);
	}
	usg_t x{ rand() % n }, y{ rand() % n };
	//std::cout << x << ' ' << y << '\n';
	arrangeChess(x, y,n, myChess);
	//std::cout << countKing << '\n';
	for (usg_t si = 0; si < n; ++si)
	{
		for (usg_t sj = 0; sj < n; ++sj)
		{
			if (myChess.at(si).at(sj) == DANGER)
			{
				myChess.at(si).at(sj) = EMPTY;
			}
		}
	}
	for (auto ii : myChess)
	{
		for (auto jj : ii)
			std::cout << jj<<' ' ;
		std::cout << std::endl;
	}
	return SUCCESS;
}
inline void arrangeChess(usg_t i, usg_t j,const usg_t & n ,chess& MyChess)
{
	MyChess.at(i).at(j) = KING;
	if (countKing <= n) {
		usg_t cib{ i - 1 }, cjb{ j - 1 };
		while (true)
		{
			if ((cib < 0) || (cjb < 0))
				break;
			MyChess.at(cib).at(cjb) = DANGER;
			--cib;
			--cjb;
		}
		cib = i + 1, cjb = j - 1;
		while (true)
		{
			if ((cib >(n-1)) || (cjb < 0))
				break;
			MyChess.at(cib).at(cjb) = DANGER;
			++cib;
			--cjb;
		}
		usg_t ljf{j+1}, ljb{j-1};
		while (true)
		{
			if ((ljf > (n - 1))  && (ljb < 0))
				break;
			if (ljf <= (n - 1))
			{
				MyChess.at(i).at(ljf) = DANGER;
				++ljf;
			}
			if (ljb >= 0)
			{
				MyChess.at(i).at(ljb) = DANGER;
				--ljb;
			}
		}
		usg_t lif{ i + 1 }, lib{ i - 1 };
		while (true)
		{
			if ((lif > (n - 1)) && (lib < 0))
				break;
			if (lif <= (n - 1))
			{
				MyChess.at(lif).at(j) = DANGER;
				++lif;
			}
			if (lib >= 0)
			{
				MyChess.at(lib).at(j) = DANGER;
				--lib;
			}
		}
		usg_t cif{ i + 1 }, cjf{ j + 1 };
		while (true)
		{
			if ((cif > (n - 1)) || (cjf > (n - 1)))
				break;
			MyChess.at(cif).at(cjf) = DANGER;
			++cif;
			++cjf;
		}
		cif = i - 1, cjf = j + 1;
		while (true)
		{
			if ((cif < 0) || (cjf > (n - 1)))
				break;
			MyChess.at(cif).at(cjf) = DANGER;
			--cif;
			++cjf;
		}
		for (usg_t si = 0; si < n; ++si)
		{
			for (usg_t sj = 0; sj < n; ++sj)
			{
				if (MyChess.at(si).at(sj) == EMPTY)
				{
					++countKing;
					arrangeChess(si, sj, n, MyChess);
				}
			}
		}
	}
	if ((!check(MyChess)) && (countKing != n))
	{
		//std::cout << "playback" << '\n';
		countKing = 1;
		resetChess(MyChess);
		arrangeChess(rand() % n, rand() %n, n, MyChess);
	}
}
inline bool check(chess& MyChess)
{
	for (usg_t si = 0; si < n; ++si)
	{
		for (usg_t sj = 0; sj < n; ++sj)
		{
			if (MyChess.at(si).at(sj) == EMPTY)
			{
				return true;
			}
		}
	}
	return false;
}
inline void resetChess(chess& MyChess)
{
	for (usg_t si = 0; si < n; ++si)
	{
		for (usg_t sj = 0; sj < n; ++sj)
		{
			MyChess.at(si).at(sj) = EMPTY;
		}
	}
}
