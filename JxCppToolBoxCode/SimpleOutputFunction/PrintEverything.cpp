#include "SimpleOutputFunction.h"


//递归输出二进制函数 
void BinaryRecursion(int n)
{
	int a = n % 2;
	n >>= 1;
	if (n != 0)
	{
		BinaryRecursion(n);
	}
	std::cout << a;
}

