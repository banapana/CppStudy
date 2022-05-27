#include <iostream>
#include <cstring>

using namespace std;

#define NAME_LEN 20

void ShowMenu();
void CreateAccount();
void Deposit();
void Withdraw();
void AccountPrintAll();

class AccountInfo
{
private:
	int AccountNum;
	char * CustomerName;
	int Balance;

public:
	AccountInfo(int accountNum, char * customerName, int balance)
		: AccountNum(accountNum), Balance(balance)
	{
		CustomerName = new char[strlen(customerName) + 1];
		strcpy(CustomerName, customerName);
	}

	~AccountInfo()
	{
		delete[] CustomerName;
	}

	int GetAccountNum()
	{
		return AccountNum;
	}

	void Deposit(int money)
	{
		Balance += money;
	}

	int Withdraw(int money)
	{
		if (Balance < money)
			return 0;

		Balance -= money;

		return money;
	}

	void ShowAccInfo() const
	{
		cout << "계좌ID: " << AccountNum << endl;
		cout << "이 름: " << CustomerName << endl;
		cout << "잔 액: " << Balance << endl;
	}

};

enum MENU_STATE
{
	CREATE_ACCOUNT = 1,
	DEPOSIT,
	WITHDRAW,
	ACCOUNT_PRINT_ALL,
	EXIT
};

AccountInfo *Accounts[100];
int AccountCount = 0;

void main()
{
	while (true)
	{
		int menuState;

		ShowMenu();

		cout << "선택: ";
		cin >> menuState;
		cout << endl;

		switch (menuState)
		{
		case CREATE_ACCOUNT:
			CreateAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case ACCOUNT_PRINT_ALL:
			AccountPrintAll();
			break;
		case EXIT:
			for (int i = 0; i < AccountCount; i++)
				delete Accounts[i];
			return;
		default:
			break;
		}
	}
}

void ShowMenu()
{
	cout << endl;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << endl;
}

void CreateAccount()
{
	int accountNum;
	char customerName[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;
	cout << "이 름: ";
	cin >> customerName;
	cout << "입금액: ";
	cin >> balance;

	Accounts[AccountCount++] = new AccountInfo(accountNum, customerName, balance);
}

void Deposit()
{
	int accountNum;
	int balance;

	cout << "[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;
	cout << "입금액: ";
	cin >> balance;

	for (int i = 0; i < AccountCount; i++)
	{
		if (Accounts[i]->GetAccountNum() == accountNum)
		{
			Accounts[i]->Deposit(balance);
			cout << "입금완료" << endl;
			return;
		}
	}

	cout << "잘못된 계좌 ID" << endl;
}

void Withdraw()
{
	int accountNum;
	int balance;

	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> accountNum;
	cout << "출금액: ";
	cin >> balance;

	for (int i = 0; i < AccountCount; i++)
	{
		if (Accounts[i]->GetAccountNum() == accountNum)
		{
			if (Accounts[i]->Withdraw(balance))
			{
				cout << "출금완료" << endl;
			}
			else
				cout << "잔액부족" << endl;

			return;
		}
	}

	cout << "잘못된 계좌 ID" << endl;
}

void AccountPrintAll()
{
	for (int i = 0; i < AccountCount; i++)
	{
		Accounts[i]->ShowAccInfo();
		cout << endl;
	}
}
