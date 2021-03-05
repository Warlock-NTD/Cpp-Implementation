#include <iomanip>
#include <iostream>
#include <cmath>

typedef double usg_t ;

int main()
{
	usg_t x,y ;
	std::cin>> x>> y;
	std::cout<<std::setprecision(15) << sqrt (x*x + y*y)<<'\n';
	return 0;
}
