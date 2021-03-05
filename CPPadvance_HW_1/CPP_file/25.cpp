#include <iostream>
#include<vector>

#define N 5
typedef int usg_t;
inline void swap(usg_t& num1, usg_t& num2);

int main()
{
	std::vector <usg_t> num;
	usg_t t{ 0 };
	while (t < N)
	{
		usg_t temp;
		std::cin >> temp;
		num.push_back(temp);
		++t;
	}
	for (usg_t i = 0; i < (N / 2); ++i)
	{
		if (num.at(i) > num.at(N - i - 1))
			swap(num.at(i), num.at(N - i - 1));
	}
	for (usg_t i = 0; i <= (N / 2); ++i)
	{
		if (num.at(i) > num.at(N / 2))
			swap(num.at(i), num.at(N / 2));
	}
	for (usg_t i = N - 1; i >= (N / 2); --i)
	{
		if (num.at(i) < num.at(N / 2))
			swap(num.at(i), num.at(N / 2));

	}
	std::cout << num.at(N / 2) << '\n';

	system("pause");
}
inline void swap(usg_t& num1, usg_t& num2)
{
	usg_t temp = num1;
	num1 = num2;
	num2 = temp;
}
