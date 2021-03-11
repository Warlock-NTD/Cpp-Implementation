#include <iostream>
#include <cstdlib>
#include<ctime>
#define MAX 30
#define Start 0
#define LIMIT 100

typedef int usg_t;
inline void swap(usg_t& num1, usg_t& num2)
{
	usg_t temp = num1;
	num1 = num2;
	num2 = temp;
}
int main()
{
	srand(time(NULL));
	usg_t arr[MAX];
	for (usg_t i = Start; i < MAX; ++i)
		arr[i] = rand() % LIMIT;
	// array before sorting :
	std::cout << "before\n";
	for (auto i : arr)
		std::cout << i << ' ';
	std::cout << std::endl;
	// below is the Bubble sort : complexity : O(n^2)
	std::cout << "after\n";
	bool needSort{ false };
	for (usg_t i = 0 ; ; ++i)
	{
		needSort = false;
		for (usg_t j = 0;j < (MAX-1-i) ;++j)
		{
			if (arr[j] > arr[j + 1])
			{
				needSort = true;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (!needSort)
			break;
	}
	for (auto i : arr)
		std::cout << i << ' ';
	std::cout << std::endl;
	return 0;
}
