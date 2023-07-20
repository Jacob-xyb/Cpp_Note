#include <iostream>
#include <bitset>
using namespace std;

/// @brief & 与运算，同1才为1
void Func_BitwiseAND()
{
    int x1 = 0b111;
    int x2 = 0b010;
    cout << (x1 & x2) << endl; // 2; 010
}

/// @brief | 或运算，同0才为0
void Func_BitwiseOR()
{
    int x1 = 0b111;
    int x2 = 0b010;
    cout << (x1 | x2) << endl; // 7; 0b111
}

/// @brief ^ 异或运算, 相同为0，不同为1
void Func_BitwiseXOR()
{
    // 异或运算可以实现 0 和 1 的交替
    int x = 1;
    cout << (x ^ 1) << " " << (x ^ 0) << endl; // 0 1
    x ^= 1;
    cout << x << endl; // 0
}

/// @brief ~ 取反运算
void Func_BitwiseInverse()
{
    int x = 1;
    int y = ~x;
    cout << y << endl; // -2; 1 取反是 -2
}

/// @brief << 左移运算
void Func_BitwiseLeftShift()
{
    int x = 8;
    x <<= 1;
    cout << x << endl; // 16

    int x2 = -2;
    x2 <<= 1;
    cout << x2 << endl; // -4
}

/// @brief >> 右移运算
void Func_BitwiseRightShift()
{
    int x = 2;
    x >>= 1;
    cout << x << endl; // 1

    int x2 = -2;
    x2 >>= 1;
    cout << x2 << endl; // -1
    x2 >>= 1;
    cout << x2 << endl; // -1; 负数右补1，所以还是-1
}

int main()
{
    Func_BitwiseInverse();
    // Func_BitwiseRightShift();

    return 0;
}