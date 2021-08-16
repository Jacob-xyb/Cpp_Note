#include "../Jx_进阶案例.h"

//常见的sizeof应用
void sizeof_type001()
{
	//sizeof()可以返回一个对象所占内存大小
	//	但是在这里我想用指针来实现sizeof()函数
	int a[5] = { 1,2,3,4,5 };
	cout << "sizeof()实现sizeof(a)：" << sizeof(a) << endl;
	int jx;		// 这将是我自主实现的结果
	////	--
	////	啪的一下打回原形，切记不要用十六进制进行加减
	//cout << "&a: " <<  & a << endl;
	//cout << "&a+1: " << & a + 1 << endl;
	//cout << "&a - (&a + 1): " << &a - (&a + 1) << endl;
	////	--
	//jx = int(&a + 1) - int(&a);
	// 其实就是对象指针：尾地址-首地址
	cout << "Jx实现sizeof(a)：" << int(&a + 1) - int(&a) << endl;

	cout << "sizeof()实现sizeof(a[0])：" << sizeof(a[0]) << endl;
	cout << "Jx实现sizeof(a[0])：" << int(a + 1) - int(a) << endl;

	//sizeof()还可以直接打印内置数据类型的内存占位
	//cout << sizeof(int) << endl;
	//cout << sizeof(float) << endl;
}

//查看当前系统下数据类型所占字节
void sizeof_view001()
{
	cout << "查看当前系统下数据类型所占字节" << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
	cout << "sizeof(double): " << sizeof(double) << endl;
	cout << "sizeof(char): " << sizeof(char) << endl;
	cout << "sizeof(bool): " << sizeof(bool) << endl;
}

