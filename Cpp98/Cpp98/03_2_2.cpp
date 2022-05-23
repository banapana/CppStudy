#include "03_2_2.h"
#include <cstring>
#include <iostream>

using namespace std;

void Printer::SetString(const char* str)
{
	strcpy(this->str, str);
}

void Printer::ShowString()
{
	cout << str << endl;
}