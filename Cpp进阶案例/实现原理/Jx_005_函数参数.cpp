#include "../Jx_进阶案例.h"

/*函数中的值传递*/
//函数的形参改变并不会影响实参
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

/*函数参数*/
//默认参数
int func_DefaultParam_001(int a = 10, int b = 20)
{
	return a + b;
}
void func_DefaultParam_001t()
{
	//如果传入数据就用传入的数据，否则就用默认值
	cout << func_DefaultParam_001()			<< endl;	//30
	cout << func_DefaultParam_001(30, 40)	<< endl;	//70
	cout << func_DefaultParam_001(80)		<< endl;	//100
}
//默认参数的声明和实现
int func_DefaultParam_002(int a = 10, int b = 20);
int func_DefaultParam_002(int a, int b)
{
	return a + b;
}
void func_DefaultParam_002t()
{	
	//函数声明中有默认参数，定义就不能有，反之亦然
	cout << func_DefaultParam_002() << endl;	//30
	//error C2572: “func_DefaultParam_002”: 重定义默认参数 : 参数 1s
}
//占位参数
void PlaceholderParameters_001(int)
{
	cout << "this is a func" << endl;
}
void PlaceholderParameters_001t()
{
	//PlaceholderParameters_001();
	/*error C2660 : “PlaceholderParameters_001”: 函数不接受 0 个参数*/
	//占位参数必须有输入项
	PlaceholderParameters_001(1);
	// 占位参数还可以用默认参数，此时可以不用传参
}