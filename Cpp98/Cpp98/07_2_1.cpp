#include<iostream>

using namespace std;

class Rectangle
{
private:
	int x;
	int y;

public:
	Rectangle(int _x, int _y)
		:x(_x), y(_y)
	{

	}

	void ShowAreaInfo()
	{
		cout << "¸éÀû: " << x * y << endl;
	}

};

class Square : public Rectangle
{
public:
	Square(int _x)
		:Rectangle(_x, _x)
	{

	}
};

void main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
}
