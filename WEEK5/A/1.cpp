#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstring>
typedef int usg_t;
typedef char c_t;
typedef void* cadd;
int main(int argc , char* argv[]) 
{
	usg_t n;
	std::cin >> n;
	usg_t* a = new usg_t[n];
	c_t* b = new c_t[n];
	std::cout << a <<' ' <<(a + 1) << ' ' << a + 2 << ' ' << '\n';
	std::cout << (cadd) b << ' ' << (cadd)(b + 1) << ' ' << (cadd)(b + 2) << ' ' << '\n';
	// address of a[] concusetive with 4 bytes linear .
	// address of b[] concusetive with 1 byte linear .
	usg_t* aa = (a - 1);
	std::cout << aa << '\n';
	// address of aa concusetive with the first element of a[] with 4 bytes 
	c_t* bb = (b - 1);
	std::cout << (cadd)bb << '\n';
	// address of bb concusetive with the first element of b[] with 1 byte .
	delete[]a;
	delete[]b;
	return 0;
}
// sample output :
//00000284CF770A20 00000284CF770A24 00000284CF770A28
//00000284CF770520 00000284CF770521 00000284CF770522
//00000284CF770A1C
//00000284CF77051F
