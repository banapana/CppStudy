#include <iostream>

using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

void main()
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(23, 45);	//�����ڴ� ����� �ʱ�ȭ �Ұ���
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;


}