#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		cout << "³­¼ö" << i + 1 << ": " << rand() % 100 << endl;
	}
}