#include <iostream>
# include<iomanip>

typedef double d_usg_t;
typedef int i_usg_t;

int main()
{	
	d_usg_t x;
	i_usg_t y;
	std::cin >> x >> y;
	i_usg_t yc = y, xc = x;
	--yc;
	std::cout << " pow "<<pow(x, y) << std::endl;
	while (yc--)
	{
		if (y == 0) {
			xc = 1;
			break;
		}
		xc *= x;
	}
	std::cout <<" check " <<xc << '\n';
	return 0;
}
