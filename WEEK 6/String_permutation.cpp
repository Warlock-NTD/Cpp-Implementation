#include<iostream>
#include<vector>
#define START 0
typedef int usg_t;
typedef char c;
static usg_t n, k;
std::vector<bool> check;
std::vector<c> source;
std::string res;
inline static void Back_Track_permutation(usg_t num);
int main(int argc, char* argv[])
{
	std::cin >> n >> k;
	for (usg_t i = 0; i < k; ++i)
		res.push_back('0');
	for (usg_t i = 0; i < n; ++i)
	{
		source.push_back('a' + i);
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
			if (num == (k - 1))
			{
				std::cout << res << '\n';
			}
			else
				Back_Track_permutation(num + 1);
			check.at(i) = true;
		}
	}
}
