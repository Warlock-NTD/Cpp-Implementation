#include<iostream>

typedef long usg_t;

int main()
{
    char x, y, z;
    usg_t dup{ 0 }, dupc{ 0 }, tria{ 0 }, dis{ 0 };
    // dup count for X...XX // tria count for XOX // dis count for XO .
    x = getchar(); y = getchar(); z = getchar();
    if ((x < 'a' || x > 'z') || (y < 'a' || y > 'z'))
        std::cout << 0, exit(0);
    else if (z < 'a' || z > 'z')
            std::cout << 1, exit(0);
    if (x == y)
    {
        if (x == z)
            dis ++, dup++, ++dupc;
        else dup++, dis += 2;
    }
    else {
        if (x == z)
            dis += 3, tria++;
        else if (y == z)
            dis += 2, dup++, dupc++;
        else
            dis += 3;
    }
    while (true)
    {
        x = y, y = z;
        z = getchar();
        if (z < 'a' || z > 'z')
            break;
        if (x == y) 
        {
            if (x != z)
                ++dis;
        }
        else 
        {
            if  (x != z) 
            {
                if (y == z)
                    ++dup;
                else
                    ++dis;
            }
            else
                dis++, tria++;
        }
    }
    std::cout << ((dis * (dis - 1) / 2) + dup - tria) << std::endl;
    return 0;
}
