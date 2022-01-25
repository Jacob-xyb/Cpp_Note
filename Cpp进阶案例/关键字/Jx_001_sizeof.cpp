#include "../Jx_进阶案例.h"

//常见的sizeof应用
void sizeof_type001()
{
	//sizeof()可以返回一个对象所占内存大小
	//	但是在这里我想用指针来实现sizeof()函数
	int a[5] = { 1,2,3,4,5 };
	std::cout << "sizeof()实现sizeof(a)：" << sizeof(a) << std::endl;
	int jx;		// 这将是我自主实现的结果
	//	--
	//	啪的一下打回原形，切记不要用十六进制进行加减
	std::cout << "a: " << a << std::endl;			// int类型指针
	std::cout << "a + 1: " << a + 1 << std::endl; 
	std::cout << "&a: " <<  &a << std::endl;		// 是一个数组指针
	std::cout << "&a+1: " << &a + 1 << std::endl;
	std::cout << "&a - (&a + 1): " << &a - (&a + 1) << std::endl;
	//	--
	//jx = int(&a + 1) - int(&a);
	// 其实就是对象指针：尾地址-首地址
	std::cout << "Jx实现sizeof(a)：" << int(&a + 1) - int(&a) << std::endl;

	std::cout << "sizeof()实现sizeof(a[0])：" << sizeof(a[0]) << std::endl;
	std::cout << "Jx实现sizeof(a[0])：" << int(a + 1) - int(a) << std::endl;

	//sizeof()还可以直接打印内置数据类型的内存占位
	//std::cout << sizeof(int) << std::endl;
	//std::cout << sizeof(float) << std::endl;
}

//查看当前系统下数据类型所占字节
void sizeof_view001()
{
	std::cout << "查看当前系统下数据类型所占字节" << std::endl;
	std::cout << "sizeof(int): " << sizeof(int) << std::endl;
	std::cout << "sizeof(float): " << sizeof(float) << std::endl;
	std::cout << "sizeof(double): " << sizeof(double) << std::endl;
	std::cout << "sizeof(char): " << sizeof(char) << std::endl;
	std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;
}

