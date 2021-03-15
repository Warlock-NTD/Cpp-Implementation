#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstring>
typedef int usg_t;
typedef char c_t;
typedef void* cadd;
inline usg_t factorial(usg_t n);
int main(int argc , char* argv[]) 
{
	usg_t n;
	std::cin >> n; 
	std::cout << factorial(n);
	return 0;
}
inline usg_t factorial(usg_t n)
{
	std::cout << "n = "<< n <<" at " << &n << std::endl;
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return n * (factorial(n - 1));
}
// in conclusion each stack combine with the concusetive exactly 100 bytes
