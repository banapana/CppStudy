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
		cout << "����ID: " << AccountNum << endl;
		cout << "�� ��: " << CustomerName << endl;
		cout << "�� ��: " << Balance << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
} 

void AccountHandler::CreateAccount()
{
	int accountNum;
	char customerName[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accountNum;
	cout << "�� ��: ";
	cin >> customerName;
	cout << "�Աݾ�: ";
	cin >> balance;

	Accounts[AccountCount++] = new AccountInfo(accountNum, customerName, balance);
}

void AccountHandler::Deposit()
{
	int accountNum;
	int balance;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountNum;
	cout << "�Աݾ�: ";
	cin >> balance;

	for (int i = 0; i < AccountCount; i++)
	{
		if (Accounts[i]->GetAccountNum() == accountNum)
		{
			Accounts[i]->Deposit(balance);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}

	cout << "�߸��� ���� ID" << endl;
}

void AccountHandler::Withdraw()
{
	int accountNum;
	int balance;

	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> accountNum;
	cout << "��ݾ�: ";
	cin >> balance;

	for (int i = 0; i < AccountCount; i++)
	{
		if (Accounts[i]->GetAccountNum() == accountNum)
		{
			if (Accounts[i]->Withdraw(balance))
			{
				cout << "��ݿϷ�" << endl;
			}
			else
				cout << "�ܾ׺���" << endl;

			return;
		}
	}

	cout << "�߸��� ���� ID" << endl;
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

		cout << "����: ";
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