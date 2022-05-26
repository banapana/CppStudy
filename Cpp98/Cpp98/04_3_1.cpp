#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y)
		: xpos(x), ypos(y)
	{
	}

	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point point;
	int radius;

public:
	Circle(int x, int y, int rd)
		:point(x,y), radius(rd)
	{
	}

	void ShowCircleInfo() const
	{
		cout << "radius: " << radius << endl;
		point.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle cir1;
	Circle cir2;

public:
	Ring(int x1, int y1, int rd1, int x2, int y2, int rd2)
		:cir1(x1, y1, rd1), cir2(x2, y2, rd2)
	{
	};

	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		cir1.ShowCircleInfo();

		cout << "Outter Circle Info..." << endl;
		cir2.ShowCircleInfo();
	}
};

void main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
}