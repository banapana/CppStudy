#include <iostream>

using namespace std;

void main()
{
	int num = 0;

	cout << "������ ���� �Է� : ";
	cin >> num;

	cout << endl;

	for (int i = 0; i < 9; i++)
		cout << num << " X " << i + 1 << " = " << num * (i + 1) << endl;
}