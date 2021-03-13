#include <iostream>
#include<vector>
#include<string>

typedef std::string s;
typedef std::vector<std::string> vs;
typedef long long usg_t;
bool checkMap(vs& map, usg_t &H, usg_t &W);

int main()
{
    usg_t H, W;
    std::cin >> W >> H;
    vs map;
    for (usg_t i = 0; i < H; ++i)
    {
        s temp;
        std::cin >> temp;
        map.push_back(temp);
    }
    if (checkMap(map,H,W))
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
bool checkMap(vs& map,usg_t& H, usg_t& W)
{
    for (usg_t i = 0; i < H; ++i)
    {
        for (usg_t j = 0; j < W; ++j)
        {
            if (map.at(i).at(j) == 'Y')
            {
                if (i == (H - 1))
                {
                    return true;
                }
                if (((j - 1) >= 0) && (map.at(i).at(j - 1) != 'R') && (map.at(i + 1).at(j - 1) != 'R'))
                {
                    map.at(i + 1).at(j - 1) = 'Y';
                }
                if (((j + 1) <= (W-1)) && (map.at(i).at(j + 1) != 'R') && (map.at(i + 1).at(j + 1) != 'R'))
                {
                    map.at(i + 1).at(j + 1) = 'Y';
                }
                if (map.at(i + 1).at(j) != 'R')
                {
                    map.at(i + 1).at(j) = 'Y';
                }
            }
        }
    }
    return false;
}
