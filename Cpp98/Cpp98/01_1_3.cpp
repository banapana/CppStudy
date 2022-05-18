#include <iostream>

using namespace std;

void main()
{
	int num = 0;

	cout << "구구단 숫자 입력 : ";
	cin >> num;

	cout << endl;

	for (int i = 0; i < 9; i++)
		cout << num << " X " << i + 1 << " = " << num * (i + 1) << endl;
}