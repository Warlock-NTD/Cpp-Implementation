#include <iostream>
#include<vector>

typedef int usg_t;
inline void swap(usg_t& num1, usg_t& num2);

int main()
{
	usg_t N;
	std::cin >> N;
	std::vector <usg_t> num;
	usg_t t{ 0 };
	double ave{ 0.0 };
	while (t < N)
	{
		usg_t temp;
		std::cin >> temp;
		ave += temp;
		num.push_back(temp);
		++t;
	}
	ave /= N;
	usg_t max{ num.at(0) }, min{ num.at(0) };
	for (usg_t i = 1; i < N; ++i)
	{
		if (max < num.at(i))
			swap(max, num.at(i));
		if (min > num.at(i))
			swap(min, num.at(i));
	}
	std::cout << "Mean : " << ave << '\n' << "Max : " << max << '\n' << "Min : " << min << std::endl;

	system("pause");
}
inline void swap(usg_t& num1, usg_t& num2)
{
	usg_t temp = num1;
	num1 = num2;
	num2 = temp;
}
