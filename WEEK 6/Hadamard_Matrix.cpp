#include<iostream>
#include<vector>
typedef int usg_t;
typedef unsigned char c;
typedef std::vector<c> row;
typedef std::vector<row> matrix;
const c black{ 233 }, white{ 254 }; // 254 // 240
inline matrix Hadamard(usg_t n);
inline matrix negative_Hadamard(matrix neg);
inline void combineHadamard(matrix & H1, matrix& H2);
int main(int argc, char* argv[])
{
	usg_t n;
	std::cin >> n;
	matrix hadamard;
	hadamard = Hadamard(n);
	for (auto i : hadamard) {
		for (auto j : i)
			std::cout << j << ' ';
		std::cout << std::endl;
	}
	return 0;
}
inline matrix Hadamard(usg_t n)
{
	if (n == 1)
	{
		return { {white,white},{white,black} };
	}
	else {
		matrix H{ Hadamard(n - 1) };
		matrix H1{ H };
		matrix H2{ H };
		matrix H3 = negative_Hadamard(H);
		combineHadamard(H, H1);
		combineHadamard(H2, H3);
		for (auto i : H2)
			H.push_back(i);
		return H;
	}
}
inline void combineHadamard(matrix&H1, matrix &H2)
{
	for (usg_t i = 0; i < H1.size(); ++i)
	{
		H1.at(i).insert(H1.at(i).end(), H2.at(i).begin(), H2.at(i).end());
	}
}
inline matrix negative_Hadamard(matrix neg)
{
	for (usg_t i = 0; i < neg.size(); ++i)
	{
		for (usg_t j = 0; j < neg.at(i).size(); ++j)
		{
			if (neg.at(i).at(j) == black)
				neg.at(i).at(j) = white;
			else
				neg.at(i).at(j) = black;
		}
	}
	return neg;
}
