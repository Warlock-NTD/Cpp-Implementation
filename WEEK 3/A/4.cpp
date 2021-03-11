#include <iostream>
#include <string>

typedef int usg_t;

int main()
{
	int daytab[] = {
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,29,31,30,31,30,31,31,30,31,30,31
	};
	// std::cout << daytab[-1]; // print trash value
	// std::cout << daytab[sizeof(daytab) / sizeof(int) ]; // print trash value
	// std::cout << daytab[sizeof(daytab) / sizeof(int) + 1]; // print trash value
	/*daytab[sizeof(daytab) / sizeof(int)] = 69;
	std::cout << daytab[sizeof(daytab) / sizeof(int)];*/ // overrun buffer of array, offset of array = 96 .
	/*daytab[sizeof(daytab) / sizeof(int) + 1] = 69;
	std::cout << daytab[sizeof(daytab) / sizeof(int) + 1];*/ // overrun buffer of array, offset of array = 96 .
	return 0;
}
