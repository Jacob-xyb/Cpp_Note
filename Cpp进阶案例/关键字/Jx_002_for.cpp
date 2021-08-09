#include "../Jx_test.h"

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