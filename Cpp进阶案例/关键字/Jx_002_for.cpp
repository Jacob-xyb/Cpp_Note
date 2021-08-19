#include "../Jx_进阶案例.h"

//研究一下for循环中的变量
void variable_in_for001()
{
	//和python不同，C++ for 中的变量，在循环结束时会被释放掉
	for (int i = 0; i < 3; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	//cout << i << endl;	//error:未定义标识符"i"

	//但是如果传入的是一个实参呢？
	int idx = 0;
	for (idx; idx < 3; idx++)	//传入实参时这样写比较规范
	//for (idx = -1; idx < 3; idx++)	//也可以重新赋值
	//for (; idx < 3; idx++)	//当然不写也不会报错
	//for (idx; idx < 3; idx += 2)	// 也可以改变步长
	{
		cout << idx << " ";
	}
	cout << endl;
	cout << idx << endl;	//3
	//	所以传入一个实参idx时，idx时会实时改变，并且不会被释放
}

//for循环中重新声明变量的问题
//	第一种情况，不在循环内(不能重定义)
void variable_in_for002()
{
	int a;
	a = 3;
	cout << a << endl;
	//int a;	//重新定义就会出错	//error C2086: “int a”: 重定义
	a = 4;
	cout << a << endl;
}
//	第二种情况，在循环内外(可以重定义)
void variable_in_for003()
{
	int a;
	a = 10;
	cout << a << endl;
	for (int i = 0; i < 5; i++)
	{
		int a;
		a = i + 1;
		cout << a << " ";
	}
	cout << endl << a << endl;	//你会发现 a 又变成了10

	//猜测for循环每次循环都会释放掉循环内创建的变量
	cout << "测试变量的变化" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "外围空间中的a：" << a << " ";
		int a;
		a = i + 1;
		cout << "for循环空间中的a：" << a << endl;
	}
	//	很神奇，就好像for循环空间中没有a变量就会去上一层寻找，如果有就会优先调用本层的变量
}
//	第三种情况，肯定可以重定义
//		但是，测试一下变量是否会被释放掉(答案是被释放掉了)
void variable_in_for004()
{
	for (int i = 0; i < 5; i++)
	{
		int a;
		a = i + 1;
		cout << "for循环空间中的a：" << a << endl;
	}
	//cout << "外围空间中的a：" << a << " ";	//error C2065: “a”: 未声明的标识符
}

//研究 for + while 循环时变量的变化
void variable_in_for005()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "while循环前的i：" << i << endl;
		while (i<5)
		{
			i++;
		}
		cout << "while循环后的i：" << i << endl;
	}
	//结论：while循环是可以直接改变for循环的变量的
}
