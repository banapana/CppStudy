#include <iostream>

using namespace std;

void main()
{
	int basicSalary = 50;
	float salesRate = 0.12f;

	while (true)
	{
		int salePrice = 0;

		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> salePrice;

		if (salePrice == -1) return;

		cout << "�̹� �� �޿�: " << basicSalary + salePrice * salesRate << "����" << endl;
	}
}