#include<iostream>
#include<vector>
#include<string>
#define SUCCESS 0
typedef long long usg_t;
typedef std::string s;
typedef std::vector<usg_t> v;
v Prepare(s& sub);
usg_t countFreq(s& sub, s& main, v Pre);
int main()
{
    s S;
    usg_t N, M;
    std::cin >> N >> M;
    std::cin >> S;
    while (M--)
    {
        usg_t a, b;
        std::cin >> a >> b;
        s sub;
        for (usg_t i = a; i <= b; ++i)
            sub.push_back(S.at(i - 1));
        //std::cout << sub << '\n';
        std::cout << countFreq(sub, S, Prepare(sub)) << std::endl;
    }
    return SUCCESS;
}
usg_t countFreq(s& sub, s& main, v Pre)
{
    usg_t L = main.size();
    usg_t C = sub.size();
    usg_t freq{ 0 };
    usg_t maxfreq{ 0 };
    usg_t i{ 0 };
    usg_t j{ 0 };
    bool consecutive{ false };
    while (i < L)
    {
        if (main.at(i) == sub.at(j))
        {
            ++i;
            ++j;
        }
        if (j == C)
        {
            consecutive = true;
            ++freq;
            j = Pre.at(j - 1);
            if (Pre.at(j) != 0)
                ++i;
            j = 0;
        }
        else if (i < L && main.at(i) != sub.at(j))
        {
            if (consecutive)
            {
                consecutive = false;
                maxfreq = (maxfreq > freq) ? maxfreq : freq;
                freq = 0;
            }
            if (j != 0)
                j = Pre.at(j - 1);
            else
                ++i;
        }
    }
    return (maxfreq > freq) ? maxfreq : freq;
}
v Prepare(s& sub)
{
    usg_t L = sub.size();
    usg_t i = 1;
    usg_t j = 0;
    v result;
    result.push_back(0);
    while (i < L)
    {
        if (sub.at(i) == sub.at(j))
        {
            ++i;
            ++j;
            result.push_back(j);
        }
        else
        {
            if (j != 0) {
                j = result.at(j - 1);
            }
            else
            {
                result.push_back(0);
                ++i;
            }
        }
    }
    return result;
}
