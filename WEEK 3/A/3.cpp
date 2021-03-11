#include <iostream>
#include <string>

typedef int usg_t;

int main()
{
	/*int daytab[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};*/
	int daytab[][12] = {
	31,28,31,30,31,30,31,31,30,31,30,31,
	31,29,31,30,31,30,31,31,30,31,30,31
	};
	// print the same value;
	// get error when we delete the column index 
	// erase particular element then the 0 value will be fill in those position .
	for (usg_t i = 0; i <2; ++i)
	{
		for (usg_t j = 0; j < 12; ++j)
			std::cout << daytab[i][j] << '\t';
		std::cout << std::endl;
	}
	return 0;
}
