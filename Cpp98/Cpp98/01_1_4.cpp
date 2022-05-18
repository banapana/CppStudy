#include <iostream>

using namespace std;

void main()
{
	int basicSalary = 50;
	float salesRate = 0.12f;

	while (true)
	{
		int salePrice = 0;

		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> salePrice;

		if (salePrice == -1) return;

		cout << "이번 달 급여: " << basicSalary + salePrice * salesRate << "만원" << endl;
	}
}