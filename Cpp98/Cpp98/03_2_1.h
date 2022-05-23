#pragma once

class Calculator
{
private:
	int addCount;
	int DivCount;
	int MinCount;
	int MulCount;

public:
	void Init();
	double Add(double num1, double num2);
	double Div(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	void ShowOpCount();
};