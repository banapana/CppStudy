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
	AccountInfo* accountInfo = &Accounts[AccountCount];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accountInfo->AccountNum;
	cout << "이 름: ";
	cin >> accountInfo->CustomerName;
	cout << "입금액: ";
	cin >> accountInfo->Balance;

	AccountCount++;
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
		if (Accounts[i].AccountNum == accountNum)
		{
			Accounts[i].Balance += balance;
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
		if (Accounts[i].AccountNum == accountNum)
		{
			if (Accounts[i].Balance >= balance)
			{
				Accounts[i].Balance -= balance;
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
		AccountInfo* accountInfo = &Accounts[i];

		cout << "계좌ID: " << accountInfo->AccountNum << endl;
		cout << "이 름: " << accountInfo->CustomerName << endl;
		cout << "잔 액: " << accountInfo->Balance << endl;
		cout << endl;
	}
}
