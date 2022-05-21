#include <iostream>

using namespace std;

int Boxvolume(int length, int width, int height);
int Boxvolume(int length, int width);
int Boxvolume(int length);

void main()
{
	cout << "[3, 3, 3] : " << Boxvolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << Boxvolume(5, 5) << endl;
	cout << "[7, D, D] : " << Boxvolume(7) << endl;
	// cout << "[D, D, D] : " << Boxvolume() << endl;
}

int Boxvolume(int length, int width, int height)
{
	return length * width * height;
}

int Boxvolume(int length, int width)
{
	return length * width * 1;
}

int Boxvolume(int length)
{
	return length * 1 * 1;
}