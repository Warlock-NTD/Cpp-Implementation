#include<iostream>

typedef int usg_t;

int main(usg_t argc, char* argv[])
{
	// usg_t& n; // error reference n must have initializer by compulsory
	usg_t n;
	usg_t& ref = n;
	std::cout << &ref << '\t' << &n << std::endl;
	// &ref and n shared the same address 
	usg_t ano;
	// &ref = ano; // error : couldn't set the &ref to another variable .
	return 0;
}

