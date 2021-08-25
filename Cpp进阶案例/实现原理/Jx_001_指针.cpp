#include "../Jx_进阶案例.h"


//指针定义
void pointer_Jx001()
{
	//1.定义一个指针
	int a = 10;
	// 指针定义语法： 数据类型 * 指针变量名；
	int* p;	//整型指针，表明指针指向的数据类型是整型
	// 让指针记录变量 a 的地址
	p = &a;
	cout << "a的地址为： " << &a << endl;
	cout << "指针p的值为： " << p << endl;
	cout << "指针p的地址为： " << &p << endl;	//指针也需要占内存空间
	cout << endl;

	// 2.使用指针
	// 可以通过解引用的方式来找到指针指向的内存	// *p
	cout << "p指向的内存内容为： " << *p << endl;
	// 通过 *p 可以访问和读写 内存内容
	*p = 1000;
	cout << "改写后，a的值变为了：" << a << endl;
	cout << "此时，*p的值变为了： " << *p << endl;
	cout << "但是p的值是没有变的为： " << p << endl;
	cout << "同时，p的内存地址&p也没有变： " << &p << endl;
}

//指针所占内存空间
void pointer_Jx002()
{
	//无论什么数据类型的指针
	//	32位操作系统：4字节
	//	64位操作系统：8字节
	cout << "sizeof(int*): " << sizeof(int*) << endl;		//4bit(x64)
	cout << "sizeof(long*): " << sizeof(long*) << endl;		//4bit(x64)
	cout << "sizeof(float*): " << sizeof(float*) << endl;	//4bit(x64)
	cout << "sizeof(double*): " << sizeof(double*) << endl;	//8bit(x64)
}


/*
(int)a：强制类型转换，a为浮点数等对象
(int&)a：将a对象的内容看成int，并不会对内存做更改
(int*)a：强制转换成int类型指针，a为指针
*/

// 数组中的指针：对象指针和元素指针
void array_index_001()
{
	int b[] = { 1,2,3,4,5 };
	cout << "查看一下array的内存地址：" << &b << endl;
	// 但是b也是可以创建array的地址的
	cout << "直接用数组变量名查看地址：" << b << endl;
	
	// 但是这两个指针是有区别的
	//	&b 是对象 b 这整个对象的（起始）地址；
	//	b 是对象 b 中第一个元素的地址；
	//	如何验证：分别将两个地址+1，既可以看出区别
	cout << "对象指针+1结果：" << &b + 1 << endl;
	cout << "元素指针+1结果：" << b + 1 << endl;
	//	一个相差 20 一个相差 4,；因此对元素取址，多用数组变量名
	//	加深理解，其实变量名b 相当于 &b[0]
	cout << "验证&b[0]+1：" << &b[0] + 1 << endl;
	cout << "---" << endl;
	//	换成整数看更为直观
	cout << "换成整数看更为直观" << endl;
	cout << "查看一下array的内存地址：" << int(b) << endl;
	cout << "对象指针+1结果：" << int(&b + 1) << endl;
	cout << "元素指针+1结果：" << int(b + 1) << endl;
	cout << "验证&b[0]+1：" << int(&b[0] + 1) << endl;
}

// 数组中的指针：剖析数组索引
void array_index_002()
{
	int a[] = { 1,2,3,4,5 };
	// 分别看看输出：a、a[0]、a+1、a[1]
	cout << "a: " << a << endl;
	//cout << "a[0]: " << a[0] << endl;
	cout << "a+1: " << a+1 << endl;
	//cout << "a[1]: " << a[1] << endl;
	// 可以得出怎样的结论呢？
	//	数组名就是一个指针，a 和 a+1 均输出的是元素的地址
	//	我们换一个方式来输出同样的内容
	cout << "---" << endl;
	cout << "使用纯指针来输出同样的结果" << endl;
	cout << "a: " << a << endl;
	cout << "*a: " << *a << endl;
	cout << "a+1: " << a + 1 << endl;
	cout << "*(a+1): " << *(a+1) << endl;
	//由此可见：a[num] 其实就是 *(a+num)	// 指针偏移后取索引
	//			a[0] 其实就是 *(a+0) 也就是 *a
	//	python中a[-1]就是最后一个数，可以负数索引，C++中可以吗？
	//cout << "---" << endl;
	//cout << "看看负索引是个啥 a[-1]: " << a[-1] << endl;
	////	看来是未初始化的空间：-858993460
	////	虽然能运行，但是编译器已经把我给“绿了”，所以弄懂就OK了
	
	// 试验一下别的方式释放指针
	cout << "double方式释放int指针：" << *(double*)a << endl;
}


//探索一下计算机内存实现原理 
//	float
void float_index_001()
{
	float jx = -3.75;
	cout << "&jx: " << &jx << endl;	//005AFDA4
	// 将 005AFDA4 输入计算器
	// 结果为 101 1010 1111 1101 1010 0100
	// 每次地址都在变，并且依靠float解读这个内存并不是"-3.75"
	//	废话每次都在变肯定不是"-3.75"啦，&jx 只是指向 jx 对象

	//如何获取"-3.75"这个对象呢？
	cout << (int&)jx << endl;	//-1066401792
	// 将 -1066401792 输入计算器
	// 结果为 1100 0000 0111 0000 0000 0000 0000 0000

	jx = int(jx);
	cout << "换成整形后地址会改变吗：" << &jx << endl;
	//	`int(jx)`对其进行转换并没有改变 jx 的首地址，可能是由于 `sizeof(int) == sizeof(float)
}


