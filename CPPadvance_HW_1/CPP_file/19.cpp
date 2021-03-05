#include <iostream>
#include<cmath>

typedef int usg_t;

int main()
{
	usg_t x, y, z;
	std::cin >> x >> y >> z;
	usg_t max = std::max(std::max(x, y), z);
	usg_t min = std::min(std::min(x, y), z);
	bool b{ true };
	if (x == max && z == min)
		goto END;
	else if (x == min && z == max)
		goto END;
	else
		b = false;
END:
	std::cout << std::boolalpha << b << std::endl;
	system("pause");
}
