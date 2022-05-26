#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void PrintCompPos(int comPos)
	{
		switch (comPos)
		{
		case CLERK: cout << "���" << endl; break;
		case SENIOR: cout << "����" << endl; break;
		case ASSIST: cout << "�븮" << endl; break;
		case MANAGER: cout << "����" << endl; break;
		default:
			break;
		}
	}
}

class NameCard
{
private:
	char * name;
	char * officeName;
	char * phoneNumber;
	int compPos;

public:
	NameCard(char * _name, char * _officeName, char * _phoneNumber, int _compPos)
		:compPos(_compPos)
	{
		name = new char[strlen(_name) + 1];
		officeName = new char[strlen(_officeName) + 1];
		phoneNumber = new char[strlen(_phoneNumber) + 1];

		strcpy(name, _name);
		strcpy(officeName, _officeName);
		strcpy(phoneNumber, _phoneNumber);
	}

	~NameCard()
	{
		delete[] name;
		delete[] officeName;
		delete[] phoneNumber;
	}

	void ShowNameCardInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << officeName << endl;
		cout << "��ȭ��ȣ: " << phoneNumber << endl;
		cout << "����: "; COMP_POS::PrintCompPos(compPos);
		cout << endl;
	}
};

void main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}