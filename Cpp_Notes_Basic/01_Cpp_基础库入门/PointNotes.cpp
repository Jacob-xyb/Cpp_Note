#include "PointNotes.h"
#include <iostream>

using namespace std;

void PointNotes::Func_PointDefine()
{
	int a = 10;
	int* p;

	// 让指针记录变量 a 的地址
	p = &a;
	cout << p << endl;

	// ++指针的使用
	// 可以通过解引用的方式来找到指针指向的内存	// *p
	cout << "p指向的内存内容为： " << *p << endl;
	// 通过 *p 可以访问和读写 内存内容
	*p = 1000;
	cout << "改写后，a的值变为了：" << a << endl;
	cout << "此时，*p的值变为了： " << *p << endl;
	cout << "但是p的值是没有变的为： " << p << endl;
}
