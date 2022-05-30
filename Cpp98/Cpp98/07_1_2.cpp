#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;

public:
	MyFriendInfo(char * _name, int _age)
		:age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	~MyFriendInfo()
	{
		delete[] name;
	}

	void ShowMyFriendInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;

public:
	MyFriendDetailInfo(char * _name, int _age, char * _addr, char * _phone)
		:MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		strcpy(addr, _addr);

		phone = new char[strlen(_phone) + 1];
		strcpy(phone, _phone);
	}

	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}

	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
};

void main()
{
	MyFriendDetailInfo myFriendDetailInfo("ȫ�浿", 14, "�����", "010-1234-5678");
	myFriendDetailInfo.ShowMyFriendDetailInfo();
}