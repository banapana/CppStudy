#include <iostream>

using namespace std;

void main()
{
	char name[20] = { 0, };
	char phoneNum[20] = { 0, };

	cout << "�̸� �Է� : ";
	cin >> name;

	cout << "��ȭ��ȣ �Է� : ";
	cin >> phoneNum;

	cout << "�̸� : " << name << ", ��ȭ��ȣ : " << phoneNum << endl;
}