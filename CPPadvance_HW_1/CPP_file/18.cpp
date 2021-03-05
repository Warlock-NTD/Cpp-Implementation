#include <iostream>
#include<cmath>

typedef double usg_t;

class Point 
{
private:
	usg_t x, y;
public:
	Point (usg_t & xValue, usg_t & yValue) : x{ xValue }, y{ yValue }
	{}
	usg_t getx () {	return x; }
	usg_t gety () { return y; }
	~Point()
	{}
};
class Line
{
private:
	usg_t length;
public :
	Line (Point & P1 , Point & P2) 
		: length {sqrt(pow((P1.getx() - P2.getx()),2) + pow((P1.gety() - P2.gety()),2))}
	{}
	usg_t getLength() { return length; }
	~Line()
	{}
};
int main()
{
	usg_t x1, x2, y1, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	Point P1(x1,y1);
	Point P2(x2, y2);
	Line E(P1, P2);
	std::cout << E.getLength() << std::endl;
	system("pause");
}
