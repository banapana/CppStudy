#include <iostream>

using namespace std;

void main()
{
	char name[20] = { 0, };
	char phoneNum[20] = { 0, };

	cout << "이름 입력 : ";
	cin >> name;

	cout << "전화번호 입력 : ";
	cin >> phoneNum;

	cout << "이름 : " << name << ", 전화번호 : " << phoneNum << endl;
}