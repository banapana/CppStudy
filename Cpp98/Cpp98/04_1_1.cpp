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
			cout << "잘못된 money 값 판매 실패";
			return 0;
		}

		int num = money / APPLE_PRISE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
			cout << "잘못된 money 값 구매 실패";
			return;
		}

		numOfApples += seller.SaleAplles(money);
		myMoney -= money;
	}

	void ShowSalesResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

void main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowSalesResult();
}