#include "../Jx_进阶案例.h"

//函数中的值传递
//	函数的形参改变并不会影响形参
void func_transmit_001(int num1, int num2)
{
	cout << "函数中的num1: " << num1 << endl;
	cout << "函数中的num2: " << num2 << endl;
	num1++; num2++;
	cout << "函数中改变后的num1: " << num1 << endl;
	cout << "函数中改变后的num2: " << num2 << endl;
}


void func_transmit_001t()
{
	int a = 10, b = 20;
	cout << "函数外的实参a: " << a << endl;
	cout << "函数外的实参b: " << b << endl;
	func_transmit_001(a, b);
	cout << "函数执行后的实参a: " << a << endl;
	cout << "函数执行后的实参b: " << b << endl;
}