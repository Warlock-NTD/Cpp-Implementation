#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#define MAX 200

typedef int usg_t;
struct Victim
{
	Victim(usg_t  num , usg_t & dur) : numb {num}, dura{dur}
	{}
	// Victim () = default;
	usg_t numb;
	usg_t dura;
};
inline void swap(Victim& V1, Victim& V2)
{
	Victim temp = V1;
	V1 = V2;
	V2 = temp;
}
void bbSort(std::vector <Victim> &list)
{
	bool needSort{ false };
	for (usg_t i = 0; ; ++i)
	{
		needSort = false;
		for (usg_t j = 0; j < (list.size() - 1 - i); ++j)
		{
			if (list[j].dura > list[j + 1].dura)
			{
				needSort = true;
				swap(list[j], list[j + 1]);
			}
		}
		if (!needSort)
			break;
	}
}
int main()
{
	srand(time(NULL));
	std::vector<Victim> list;
	usg_t n;
	std::cout << "How many Victim ?\n";
	std::cin >> n;
	std::cout << "Input " << n << " Victim's time to served\n";
	for (usg_t i = 0; i < n; ++i)
	{
		usg_t temp;
		// std::cin >> temp;
		temp = rand() % MAX;
		Victim TEMP (i + 1, temp);
		list.push_back(TEMP);
	}
	bbSort(list);
	std::cout << "The Progress order of minimize waiting time is :\n";
		for (auto i : list)
		{
			std::cout << "Victim number : " << i.numb << " has "<<i.dura<<" minutes served "<<'\n';
		}
	for (usg_t i = 1; i < n; ++i)
	{
		list.at(i).dura += list.at(i - 1).dura;
	}
	usg_t Sum{ 0 };
	for (usg_t i = 1; i < n; ++i)
	{
		Sum += list.at(i).dura;
	}
	std::cout << "Sum of all waiting time is : " << Sum << '\n';
	return 0;
}
