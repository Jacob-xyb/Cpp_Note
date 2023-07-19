#include <iostream>
using namespace std;

/// @brief & 与运算，同1才为1
void Func_BitwiseAND()
{
    int x1 = 0b111;
    int x2 = 0b010;
    cout << (x1 & x2) << endl;  // 2; 010
}

/// @brief | 或运算，同0才为0
void Func_BitwiseOR()
{
    int x1 = 0b111;
    int x2 = 0b010;
    cout << (x1 | x2) << endl;  // 7; 0b111
}

/// @brief ^ 异或运算, 相同为0，不同为1
void Func_BitwiseXOR()
{
	int x = 1;	// 异或运算可以实现 0 和 1 的交替
	cout << (x ^ 1) << " " << (x ^ 0) << endl;  // 0 1
	x ^= 1;
	cout << x << endl;  // 0
}

int main()
{
    Func_BitwiseXOR();
    return 0;
}