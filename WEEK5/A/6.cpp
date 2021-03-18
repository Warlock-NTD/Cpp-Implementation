#include<iostream>
#include<ctime>
#include<cstdlib>

typedef int usg_t;
static constexpr usg_t sizeArr{ 100 };
inline void bruteForceSearching(const usg_t& key, usg_t arr[])
{
	for (usg_t i = 0; i < sizeArr; ++i)
	{
		if (arr[i] == key) {
			std::cout <<"Brute Forced : " <<i;
			break;
		}
	}
}
inline void binarySearching(const usg_t& key, usg_t arr[])
{
	// because of array sorted ----------------------------
	usg_t bin{ sizeArr/2 };
	usg_t low{ 0 }, high{ sizeArr-1 };
	usg_t time{ 0 };
	while (time < sizeArr)
	{
		if (arr[bin] > key)
		{
			high = bin;
			bin = (high - low) / 2 + low;
		}
		else if (arr[bin] < key)
		{
			low = bin;
			bin = (high - low) / 2 + low;
		}
		else {
			std::cout << "BinSearch : " << bin << '\n';
			break;
		}
		++time;
	}
}
int main(usg_t argc, char* argv[])
{
	usg_t arr[sizeArr];
	for (usg_t i = 0; i < sizeArr; ++i)
		arr[i] = i;
	// usg_t key{ 0 };
	// usg_t key{99};
	// usg_t key{50};
	 srand(time(NULL));	usg_t key{ rand() % sizeArr };
	binarySearching(key, arr);
	bruteForceSearching(key, arr);
	return 0;
}

