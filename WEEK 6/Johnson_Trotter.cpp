#include<iostream>
#include<vector>
#define START 0
typedef int usg_t;
static usg_t n;
std::vector<bool> check;
std::vector<usg_t> source;
std::vector<usg_t> res;
inline static void Back_Track_permutation(usg_t num);
int main(int argc, char* argv[])
{
	std::cin >> n;
	for (usg_t i = 0; i < n; ++i)
		res.push_back(0);
	for (usg_t i = 0; i < n; ++i)
	{
		source.push_back(i+1);
		check.push_back(true);
	}
	Back_Track_permutation(START);
	return 0;
}
inline static void Back_Track_permutation(usg_t num)
{
	for (usg_t i = 0; i < n; ++i)
	{
		if (check.at(i))
		{
			res.at(num) = source.at(i);
			check.at(i) = false;
			if (num == (n - 1))
			{
				for (auto i : res)
					std::cout << i;
				std::cout << std::endl;
			}
			else
				Back_Track_permutation(num + 1);
			check.at(i) = true;
		}
	}
}
