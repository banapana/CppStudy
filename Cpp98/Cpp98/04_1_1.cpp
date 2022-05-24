#include <iostream>

using namespace std;

class FruitSeller
{
private:
	int APPLE_PRISE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRISE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleAplles(int money)
	{
		if (money < 0)
		{
			cout << "�߸��� money �� �Ǹ� ����";
			return 0;
		}

		int num = money / APPLE_PRISE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << "�߸��� money �� ���� ����";
			return;
		}

		numOfApples += seller.SaleAplles(money);
		myMoney -= money;
	}

	void ShowSalesResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

void main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowSalesResult();
}