#include "../Jx_进阶案例.h"

//float、double
void dataType001()
{
	//float、double默认只显示6位有效数字
	//	float最多有7位有效数字
	//	double最多有15位有效数字
	float a = 3.1415926124;
	cout << a << endl;
	double b = 3.1415926124;
	cout << b << endl;
	cout << "均只显示6位有效数字" << endl;
}

void scientific_notation001()
{
	float a = 3e3;
	cout << a << endl;
	float b = 3.1e10;	//超出数据类型有效数字之后会以科学计数法形式显示
	cout << b << endl;
	float c = 3.2e-5;
	cout << c << endl;
	float d = 3.2e-3;
	cout << d << endl;

	//超过有效位数的数看看是否能进行运算
	cout << endl;
	b += b;
	cout << b << endl;	//可以进行运算
}

//char
void dataType002()
{
	char ch1 = 'a';	//注意：字符一定要用单引号
	cout << sizeof(ch1) << endl;
	char ch2 = '好';
	cout << sizeof(ch2) << endl;	//中英文都只占一个字符
	ch2 = ' ';
	cout << sizeof(ch2) << endl;	//space也算作一个字符
	//很奇怪的是：1~4个space都只占一个字符，但是5个space却会报错
	//	输出看看1~4个space是否不一样，分别代表着什么
	cout << "1个space：" << ch1 << ch2 << ch1 << endl;
	ch2 = '  ';
	cout << "2个space：" << ch1 << ch2 << ch1 << endl;
	ch2 = '   ';
	cout << "3个space：" << ch1 << ch2 << ch1 << endl;
	ch2 = '    ';
	cout << "4个space：" << ch1 << ch2 << ch1 << endl;
	//	结果证明，1~4个space均只输出一个space
	//		更深层次的发现，不仅仅是space
	ch1 = 'aaaa';
	cout << "aaaa会输出什么：" << ch1 << endl;
	ch1 = 'abcd';
	cout << "abcd会输出什么：" << ch1 << endl;
	ch1 = 'abc1';
	cout << "abc1会输出什么：" << ch1 << endl;
	//		所以一个字符单引号内可以严格意义上是可以出现0<x<=4个字符的
	//		将这些字符的最后一个字符进行左赋值
	//		最后一次测试
	ch1 = 'abc ';
	cout << "abcspace会输出什么：" << ch1 << endl;
	//查看ASCII码
	cout << "查看ASCII码：" << (int)ch1 << endl;
}

//bool
void dataType003()
{
	bool flag = true;
	cout << flag << endl;	//true是1，bool是0

	if (flag == 1)	//结论是只能是1和true
	{
		cout << "判断时，flag可以为1" << endl;
		if (flag == true)
		{
			cout << "判断时,flag也可以为true" << endl;
		}
		if (flag == 100)
		{
			cout << "是否可以成为所有非0" << endl;
		}
	}

	cout << "请输入flag的值：" << endl;
	cin >> flag;	//数字除了0外都是真，除了数字外都是假
	cout << "输入后flag的值：" << flag << endl;
}