#include <stdio.h>

void ScaleNumber_BasicShow()
{
    // 以数字 28 为例；
    int xDec = 28;      // 十进制
    int xHex = 0x1c;    // 十六进制 0x
    int xOct = 034;     // 八进制 0
    int xBin = 0b11100; // 二进制 0b
    // Tips: 不是所有的C语言都有二进制表示法

    printf("Dec=%d, xHex=%d, Oct=%d, Bin=%d\n", xDec, xHex, xOct, xBin);
}

int main(int argc, char const *argv[])
{
    ScaleNumber_BasicShow();
    return 0;
}
