#include <iostream>

using namespace std;

void main()
{
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		int value = 0;

		cout << i + 1 << "��° ���� �Է�: ";
		cin >> value;

		sum += value;
	}

	cout << "�հ�: " << sum << endl;
}