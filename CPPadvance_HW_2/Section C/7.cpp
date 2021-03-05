#include <iostream>
#include<cstdlib>

typedef int usg_t;

int main() {
    usg_t compare;
    usg_t temp;
    std::cin >> temp;
    compare = temp;
    std::cout << temp << ' ';
    while (temp + abs(temp))
    {
        std::cin >> temp;
        if (temp == compare)
            continue;
        else
        {
            compare = temp;
            std::cout << temp<<' ';
        }
    }
    std::cout << std::endl;
    system("pause");
}
