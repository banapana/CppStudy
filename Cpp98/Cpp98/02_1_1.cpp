#include <iostream>

using namespace std;

void IncreaseValue(int& var)
{
	var++;
}

void ChangeValueSign(int& var)
{
	var *= -1;
}

void main()
{
	int var = 1;

	cout << "IncreaseValue Before: " << var << endl;
	IncreaseValue(var);
	cout << "IncreaseValue After: " << var << endl;

	cout << "ChangeValueSign Before: " << var << endl;
	ChangeValueSign(var);
	cout << "ChangeValueSign After: " << var << endl;
}