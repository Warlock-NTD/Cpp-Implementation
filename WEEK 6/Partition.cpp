#include<iostream>
#include<vector>
#define START 0
typedef int usg_t;
inline static void BackTrack_set(std::vector<usg_t>&line,usg_t pos, usg_t diff);
inline static void PrintLine(std::vector<usg_t> &line);
int main(int argc, char* argv[])
{
	usg_t n;
	std::cin >> n;
	std::vector<usg_t> line(n+1);
	usg_t diff{ n };
	line.at(0) = n - 1;
	BackTrack_set(line,START, diff);
	return 0;
}
inline static void BackTrack_set(std::vector<usg_t>&line,usg_t pos, usg_t diff)
{
	if (diff == 0)
		PrintLine(line);
	else
		for (usg_t i = line.at(pos); i > 0; --i)
			if (i <= diff)
			{
				line.at(pos + 1) = i;
				BackTrack_set(line,pos + 1, diff - i);
			}
}
inline static void PrintLine(std::vector<usg_t>&line)
{
	for (usg_t i = 1; i < line.size(); ++i)
		if (line.at(i) != 0)
			std::cout << line.at(i) << ' ';
	std::cout << std::endl;
}
