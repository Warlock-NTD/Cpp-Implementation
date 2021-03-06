#include <iostream>

typedef int usg_t;

inline bool checkSquare(const usg_t& x)
{
	usg_t compare = x / static_cast<int>(sqrt(x));
	if (compare == sqrt(x))
		return true;
	else
		return false;
}
bool checkPrime(const usg_t& x)
{
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
bool checkPerfect(const usg_t & x)
{
    usg_t sum{ 1 };
    for (usg_t i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (i * i != x)
                sum = sum + i + x / i;
            else
                sum = sum + i;
        }
    }
    if (sum == x && x != 1)
        return true;
    return false;
}
int main()
{
	usg_t N;
	std::cin >> N;
    usg_t e{ 2 };
    std::cout << "Square Number :\n";
    while (e <= N)
    {
        if (checkSquare(e))
            std::cout << e << '\n';
        ++e;
    }
    e = 2;
    std::cout << "Prime Number :\n";
    while (e <= N)
    {
        if (checkPrime(e))
            std::cout << e << '\n';
        ++e;
    }
    e = 2;
    std::cout << "Perfect Number :\n";
    while (e <= N)
    {
        if (checkPerfect(e))
            std::cout << e << '\n';
        ++e;
    }
	return 0;
}
