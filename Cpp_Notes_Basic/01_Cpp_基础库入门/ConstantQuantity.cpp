#include "ConstantQuantity.h"
using namespace std;

void Constant_Const::Func_ConstAndPoint()
{
	//1.const修饰的常量不能被改变
	//2.const常量必须初始化
	
	//const int a;  //Error:常量必须初始化
	const int a = 0;

	//const 与 指针的关系
	int b = 0;
	const int* p1;	//p1是指向常量的指针变量; p1是变量，所以可以在声明时不初始化；
	p1 = &b;

	int* const p2 = &b; //p2是指向变量的指针常量;p2是常量，所以声明时必须初始化；
	int* const p3 = nullptr;  //用空指针初始化都可以
}

void Constant_Const::Func_ConstAndQuote()
{
	double a = 3.14;

	//此时 int 引用是不可行的
	//int& val1 = a;	//Error: 不能将 double 初始化为 int&

	//但是 const int& 是可以的
	const int& val2 = a;	//因为 const 必须引用一个合法空间，原理是 int temp = a; const int& val2 = temp;
	cout << val2 << endl;	// 3
}

//const_cast 常见用法
void Constant_Const::Func_ConstCast()
{
	const int val = 100;
	//int n = const_cast<int>(val);	// const_cast 中的类型必须是指针

	int* p = const_cast<int*>(&val);
	*p = 200;
	cout << "val=" << val << endl;	//Out:100;
	//const_cast并不能改变指针的常量性质，常用作于可以符合函数的传参条件。
}
