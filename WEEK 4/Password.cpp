#include <iostream>
#include<string>
#include<vector>

typedef std::string s;
typedef int usg_t;
inline s stringrev(s& str)
{
	s temp;
	for (usg_t i = 0; i < str.size(); ++i)
		temp.push_back(str.at(str.size() - 1 - i));
	return temp;
}
int main()
{
	usg_t n;
	std::cin >> n;
	std::vector<s> pass;
	std::vector<s>revpass;
	for (usg_t i = 0; i < n; ++i)
	{
		s temp;
		std::cin >> temp;
		pass.push_back(temp);
		revpass.push_back(stringrev(temp));
	}
	for (auto i : pass)
		for (auto j : revpass)
			if (i == j)
			{
				std::cout << i.size() << ' ' << i.at(i.size() / 2 );
				exit(0);
			}
	return 0;
}
