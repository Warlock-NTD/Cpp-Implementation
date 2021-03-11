#include <iostream>
#include <string>

typedef int usg_t;

int main()
{
	// std::string s; // print by each : still print nothing
	//std::cout << s; // still print but printed nothing
	std::string s{ "abcd" }; // print each : print a	b	c	d
	std::cout << s; // print abcd
	/*for (auto i : s)
		std::cout << i << '\t';*/
	return 0;
}
