#include <iostream>
#include<cstdlib>

typedef int usg_t;

inline void classifyNumber(const usg_t& n);
inline void readMillion(const usg_t& n);
inline void readThousand(const usg_t& n);
inline void readHundred(const usg_t& n);
inline void readDozen(const usg_t& n);
inline void readDigit(const usg_t & n); 
int main()
{
	usg_t N;
	std::cin >> N;
	classifyNumber(N);
	system("pause");
}
inline void classifyNumber(const usg_t& n)
{
	usg_t nC{ n };
	if (n < 0)
		std::cout << "Negative"<<' ';
	nC = abs(n);
	if (nC < 10)
		readDigit(nC);
	else if ((nC <= 99) && (nC >= 10))
		readDozen(nC);
	else if ((nC <= 999) && (nC >= 100))
		readHundred(nC);
	else if ((nC <= 999999) && (nC >= 1000))
		readThousand(nC);
	else if ((nC <= 999999999) && (nC >= 1000000))
		readMillion(nC);
	std::cout << std::endl;
}
inline void readMillion(const usg_t& n)
{
	usg_t nC = n % 1000000000;
	usg_t nC1 = nC / 1000000;
	if (nC1 < 10)
		readDigit(nC1);
	else if ((nC1 <= 99) && (nC1 >= 10))
		readDozen(nC1);
	else if ((nC1 <= 999) && (nC1 >= 100))
		readHundred(nC1);
	else if ((nC1 <= 999999) && (nC1 >= 1000))
		readThousand(nC1);
	std::cout << "Million" << ' ';
	if (nC % 1000000 != 0)
	{
		nC %= 1000000;
		if (nC < 10)
		{
			std::cout << "and" << " ";
			readDigit(nC);
		}
		else if ((nC <= 99) && (nC >= 10))
		{
			std::cout << "and" << " ";
				readDozen(nC);
		}
		else if ((nC <= 999) && (nC >= 100))
		{
			std::cout << "and" << " ";
			readHundred(nC);
		}
		else if ((nC <= 999999) && (nC >= 1000))
		{
			std::cout << "and" << " ";
			readThousand(nC);
		}
	}
}
inline void readThousand(const usg_t& n)
{
	usg_t nC = n % 1000000;
	usg_t nC1 = nC / 1000;
	if (nC1 < 10)
		readDigit(nC1);
	else if ((nC1 <= 99) && (nC1 >= 10))
		readDozen(nC1);
	else if ((nC1 <= 999) && (nC1 >= 100))
		readHundred(nC1);
	std::cout << "Thousand" << ' ';
	if (nC % 1000 != 0)
	{
		nC %= 1000;
		if (nC < 10)
		{
			std::cout << "and" << " ";
			readDigit(nC);
		}
		else if ((nC <= 99) && (nC >= 10))
		{
			std::cout << "and" << " ";
			readDozen(nC);
		}
		else if ((nC <= 999) && (nC >= 100))
			readHundred(nC);
	}
}
inline void readHundred(const usg_t& n)
{
	if (n > 999)
		std::cout << "and" << ' ';
	usg_t nC = n % 1000;
	usg_t nC1 = nC / 100;
	if (nC1 < 10)
		readDigit(nC1);
	else if ((nC1 <= 99) && (nC1 >= 10))
		readDozen(nC1);
	std::cout << "Hundred" << ' ';
	if (nC % 100 != 0)
	{
		nC %= 100;
		if (nC < 10)
		{
			std::cout << "and" << " ";
			readDigit(nC);
		}
		else if ((nC <= 99) && (nC >= 10))
		{
			std::cout << "and" << " ";
			readDozen(nC);
		}
	}
}
inline void readDozen(const usg_t& n)
{
	usg_t nC = n % 100;
	
		switch (nC)
		{
		case 10:
			std::cout << "Ten" << ' ';
			break;
		case 11:
			std::cout << "Eleven" << ' ';
			break;
		case 12:
			std::cout << "Twelve" << ' ';
			break;
		case 13:
			std::cout << "Thirteen" << ' ';
			break;
		case 14:
			std::cout << "Fourteen" << ' ';
			break;
		case 15:
			std::cout << "Fifteen" << ' ';
			break;
		case 16:
			std::cout << "Sixteen" << ' ';
			break;
		case 17:
			std::cout << "Seventeen" << ' ';
			break;
		case 18:
			std::cout << "Eighteen" << ' ';
			break;
		case 19:
			std::cout << "Nineteen" << ' ';
			break;
		case 20:
			std::cout << "Twenty" << ' ';
			break;
		case 30:
			std::cout << "Thirty" << ' ';
			break;
		case 40:
			std::cout << "Forty" << ' ';
			break;
		case 50:
			std::cout << "Fifty" << ' ';
			break;
		case 60:
			std::cout << "Sixty" << ' ';
			break;
		case 70:
			std::cout << "Seventy" << ' ';
			break;
		case 80:
			std::cout << "Eighty" << ' ';
			break;
		case 90:
			std::cout << "Ninety" << ' ';
			break;
		default:
		{
			usg_t doz = nC - (nC % 10);
			switch (doz)
			{
			case 20:
				std::cout << "Twenty" << ' ';
				break;
			case 30:
				std::cout << "Thirty" << ' ';
				break;
			case 40:
				std::cout << "Forty" << ' ';
				break;
			case 50:
				std::cout << "Fifty" << ' ';
				break;
			case 60:
				std::cout << "Sixty" << ' ';
				break;
			case 70:
				std::cout << "Seventy" << ' ';
				break;
			case 80:
				std::cout << "Eighty" << ' ';
				break;
			case 90:
				std::cout << "Ninety" << ' ';
				break;
			}
			readDigit(nC);
			break;
		}
	}
}
inline void readDigit(const usg_t &n)
{
	usg_t nC = n %  10;
	switch (nC)
	{
	case 0:
		if (n<10)
		{
			std::cout << "Zero" << ' ';
		}
		break;
	case 1:
		std::cout << "One" << ' ';
		break;
	case 2:
		std::cout << "Two" << ' ';
		break;
	case 3:
		std::cout << "Three" << ' ';
		break;
	case 4:
		std::cout << "Four" << ' ';
		break;
	case 5:
		std::cout << "Five" << ' ';
		break;
	case 6:
		std::cout << "Six" << ' ';
		break;
	case 7:
		std::cout << "Seven" << ' ';
		break;
	case 8:
		std::cout << "Eight" << ' ';
		break;
	case 9:
		std::cout << "Nine" << ' ';
		break;
	}
}
