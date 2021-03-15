#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstring>
typedef int usg_t;
typedef char c_t;
typedef void* cadd;
inline usg_t someNum (usg_t n);
int main(int argc , char* argv[]) 
{
	usg_t n;
	std::cin >> n; 
	std::cout << &n << '\n';
	someNum(n);
	return 0;
}
inline usg_t someNum(usg_t n)
{
	std::cout << &n << '\n';
	return n;
}
// output : 
//0000002BB4F0F634
//0000002BB4F0F610

