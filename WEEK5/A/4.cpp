#include<iostream>
#include<string>

typedef std::string s;
typedef int usg_t;
constexpr usg_t sizeArr{ 100 };
void doSomething ( s ref ,usg_t arr[] )
{
	std::cout << &ref << '\n' << &arr << '\n';
}
void doSomethingElse(s& ref, usg_t arr[])
{
	std::cout << &ref << '\n' << &arr << '\n';
}
void doSomethingMoreElse(s& ref, usg_t* arr)
{
	std::cout << &ref << '\n' << &arr << '\n';
}
int main(usg_t argc, char* argv[])
{
	s ref;
	usg_t arr[sizeArr];
	usg_t* ar = &arr[0];
	doSomething(ref, arr);
	doSomethingElse(ref, arr);
	doSomethingMoreElse(ref, ar);

	std::cout << &ref << '\n' << &arr << '\n';
	return 0;
}
// out put :
//000000E5BF12FB18
//000000E5BF12F768
//000000E5BF12F788
//000000E5BF12F768
//000000E5BF12F788
//000000E5BF12F768
//000000E5BF12F788
//000000E5BF12F7D0
// conclusion : 
// both string and array could be passed by value
// string could be passed by reference
// string and array could be passed by address .
