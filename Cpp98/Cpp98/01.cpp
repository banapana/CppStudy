#include <iostream>

using namespace std;

#define NAME_LEN 20

void ShowMenu();
void CreateAccount();
void Deposit();
void Withdraw();
void AccountPrintAll();

struct AccountInfo
{
	int AccountNum;
	char CustomerName[NAME_LEN];
	int Balance;
};

enum MENU_STATE
{
	CREATE_ACCOUNT = 1,
	DEPOSIT,
	WITHDRAW,
	ACCOUNT_PRINT_ALL,
	EXIT
};

AccountInfo Accounts[100];
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
	AccountInfo* accountInfo = &Accounts[AccountCount];

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accountInfo->AccountNum;
	cout << "�� ��: ";
	cin >> accountInfo->CustomerName;
	cout << "�Աݾ�: ";
	cin >> accountInfo->Balance;

	AccountCount++;
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
		if (Accounts[i].AccountNum == accountNum)
		{
			Accounts[i].Balance += balance;
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
		if (Accounts[i].AccountNum == accountNum)
		{
			if (Accounts[i].Balance >= balance)
			{
				Accounts[i].Balance -= balance;
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
		AccountInfo* accountInfo = &Accounts[i];

		cout << "����ID: " << accountInfo->AccountNum << endl;
		cout << "�� ��: " << accountInfo->CustomerName << endl;
		cout << "�� ��: " << accountInfo->Balance << endl;
		cout << endl;
	}
}
