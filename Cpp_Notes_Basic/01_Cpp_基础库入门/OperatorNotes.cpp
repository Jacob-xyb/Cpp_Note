#include <iostream>
#include "OperatorNotes.h"
using namespace std;

#pragma region 三元运算符
void TernaryOperator::Func_Basic()
{
	int a = 0;
	int b = 7;
	(a > b ? a : b) = 99;

	printf("a = %d, b = %d\n", a, b);	// a = 0, b = 99
}
#pragma endregion

#pragma region 位运算
// & 与运算
void BitwiseOperator::Func_BitwiseAND()
{
}
// ~ 异或运算;相同为0，不同为1
void BitwiseOperator::Func_BitwiseXOR()
{
	int x = 1;	// 异或运算可以实现 0 和 1 的交替
	cout << (x ^ 1) << " " << (x ^ 0) << endl;
	x ^= 1;
	cout << x << endl;
}
// ~ 反运算
void BitwiseOperator::Func_BitwiseInverse()
{
	int x = 1;
	int y = ~x;	 // 1 取反是 -2
	cout << y << endl;
}
#pragma endregion

