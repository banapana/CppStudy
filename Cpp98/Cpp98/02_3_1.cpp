#include <iostream>

using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *pPoint = new Point;

	pPoint->xpos = p1.xpos + p2.xpos;
	pPoint->ypos = p1.ypos + p2.ypos;

	return *pPoint;
}

void main()
{
	Point *pPoint1 = new Point;
	Point *pPoint2 = new Point;

	pPoint1->xpos = 1;
	pPoint1->ypos = 2;

	pPoint2->xpos = 3;
	pPoint2->ypos = 4;

	Point &rPoint = PntAdder(*pPoint1, *pPoint2);

	cout << "rPoint x: " << rPoint.xpos << ", rPoint y: " << rPoint.ypos << endl;

	delete pPoint1;
	delete pPoint2;
	delete &rPoint;
}