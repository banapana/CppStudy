#include <iostream>
#include <cstring>

using namespace std;

#define NAME_LEN 20

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

	AccountInfo(const AccountInfo& ref)
		: AccountNum(ref.AccountNum), Balance(ref.Balance)
	{
		CustomerName = new char[strlen(ref.CustomerName) + 1];
		strcpy(CustomerName, ref.CustomerName);
	}

	~AccountInfo()
	{
		delete[] CustomerName;
	}

	int GetAccountNum() const
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

class AccountHandler
{
private:
	AccountInfo *Accounts[100];
	int AccountCount;

public:
	AccountHandler();
	~AccountHandler();

	void ShowMenu() const;
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void AccountPrintAll() const;
};

AccountHandler::AccountHandler()
	:AccountCount(0)
{

}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < AccountCount; i++)
		delete Accounts[i];
}

void AccountHandler::ShowMenu() const
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

void AccountHandler::CreateAccount()
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

void AccountHandler::Deposit()
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

void AccountHandler::Withdraw()
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

void AccountHandler::AccountPrintAll() const
{
	for (int i = 0; i < AccountCount; i++)
	{
		Accounts[i]->ShowAccInfo();
		cout << endl;
	}
}


void main()
{
	AccountHandler accountHandler;
	int menuState;

	while (true)
	{
		accountHandler.ShowMenu();

		cout << "선택: ";
		cin >> menuState;
		cout << endl;

		switch (menuState)
		{
		case CREATE_ACCOUNT:
			accountHandler.CreateAccount();
			break;
		case DEPOSIT:
			accountHandler.Deposit();
			break;
		case WITHDRAW:
			accountHandler.Withdraw();
			break;
		case ACCOUNT_PRINT_ALL:
			accountHandler.AccountPrintAll();
			break;
		case EXIT:
			return;
		default:
			break;
		}
	}
}