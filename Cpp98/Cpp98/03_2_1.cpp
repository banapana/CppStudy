#include "03_2_1.h"
#include <iostream>

using namespace std;

void Calculator::Init()
{
	addCount = 0;
	DivCount = 0;
	MinCount = 0;
	MulCount = 0;
}

double Calculator::Add(double num1, double num2)
{
	addCount++;
	return num1 + num2;
}

double Calculator::Div(double num1, double num2)
{
	DivCount++;
	return num1 / num2;
}

double Calculator::Min(double num1, double num2)
{
	MinCount++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	MulCount++;
	return num1 * num2;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << addCount << " »¬¼À: " << MinCount << " °ö¼À: " << MulCount << " ³ª´°¼À: " << DivCount << endl;
}
