#include <iostream>

typedef double usg_t;

int main()
{
	int n;
	std::cout << "nhap so luong day so : ";
		std::cin >> n;
	usg_t num;
	usg_t min, max;
	std::cin >> num;
	min = num, max = num;
	--n;
	while (n--)
	{
		std::cin >> num;
		max = (max > num) ? max : num;
		min = (min < num) ? min : num;
	}
	std::cout << "MAX : " << max << "\nMIN : " << min << '\n';
	return 0;
}
