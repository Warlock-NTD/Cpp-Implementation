#include<iostream>
#include<vector>
#define MAX 20
#define SUCCESS 0
#define START 0
#define QUEEN 206
#define EMPTY 240
typedef int usg_t;
typedef unsigned char c;
typedef std::vector<c> row;
typedef std::vector<std::vector<c>> chess;
typedef std::vector<bool> cross;
usg_t n;
chess myChess;
cross Road_0;
cross Road_n;
cross Line;
usg_t offset;
usg_t solution{ 0 };
std::vector<usg_t> col_idx;
inline void createChess(chess& ref, const usg_t& n);
inline void Back_Track_Set(usg_t row);
inline void PrintSolution();
inline void resetChess();
int main()
{
	std::cin >> n;
	if (n > MAX)
		exit(0);
	offset = n - 1;
	for (usg_t i = 0; i < (2*n-1); ++i)
	{
		Road_0.push_back(1);
		Road_n.push_back(1);
	}
	for (usg_t i = 0; i < n; ++i)
	{
		Line.push_back(1);
		col_idx.push_back(-1);
	}
	createChess(myChess,n);
	Back_Track_Set(START);
	return SUCCESS;
}
inline void createChess(chess& ref, const usg_t &n)
{
	for (usg_t i = 0; i < n; ++i)
	{
		row temp;
		for (usg_t j = 0; j < n; ++j)
		{
			temp.push_back(EMPTY);
		}
		ref.push_back(temp);
	}
}
inline void resetChess()
{
	for (usg_t i = 0; i < n; ++i)
		for (usg_t j = 0; j < n; ++j)
			myChess.at(i).at(j) = EMPTY;
}
inline void Back_Track_Set(usg_t row)
{
	for (usg_t col = 0; col < n; ++col)
	{
		if (Road_0.at(row+col) && Road_n.at(row - col + offset) && Line.at(col))
		{
			col_idx.at(row) = col;
			Road_0.at(row + col) = 0;
			Road_n.at(row - col + offset) = 0;
			Line.at(col) = 0;
			if (row == offset)
			{
				++solution;
				PrintSolution();
			}
			else
				Back_Track_Set(row+1);
			// recovery .
			Road_0.at(row + col) = 1;
			Road_n.at(row - col + offset) = 1;
			Line.at(col) = 1;
		}
	}
}
inline void PrintSolution()
{
	std::cout << "Solution " << solution << " : \n";
	for (usg_t i = 0; i < n; ++i)
		myChess.at(i).at(col_idx.at(i)) = QUEEN;
	for (auto i : myChess) {
		for (auto j : i)
			std::cout << j << ' ';
		std::cout << std::endl;
	}
	resetChess();
	std::cout << std::endl;
}
