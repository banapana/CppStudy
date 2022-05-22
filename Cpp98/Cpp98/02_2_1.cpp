#include <iostream>

using namespace std;

void main()
{
	const int num = 12;
	const int *ptr = &num;
	const int *(&ptrRef) = ptr;

	cout << "ptr: " << *ptr << endl;
	cout << "ptrRef: " << *ptrRef << endl;
}