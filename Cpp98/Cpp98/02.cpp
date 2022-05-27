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

AccountInfo *Accounts[100];
int AccountCount = 0;

void main()
{
	while (true)
	{
		int menuState;

		ShowMenu();

		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << endl;
}

void CreateAccount()
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

void Deposit()
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

void Withdraw()
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

void AccountPrintAll()
{
	for (int i = 0; i < AccountCount; i++)
	{
		Accounts[i]->ShowAccInfo();
		cout << endl;
	}
}
