#include <iostream>
#include <cstring>

using namespace std;

void main()
{
	char str[20] = "123";

	int len = strlen(str);
	cout << "strlen: " << len << endl;

	strcat(str, "456");
	cout << "strcat: " << str << endl;

	strcpy(str, "789");
	cout << "strcpy: " << str << endl;

	int cmp = strcmp(str, "781");
	cout << "strcmp: " << cmp << endl;
}