#include "JxPy.h"


void JxTool::BinaryRecursion(int n)
{
	int a = n % 2;
	n >>= 1;
	if (n != 0)
	{
		BinaryRecursion(n);
	}
	std::cout << a;
}