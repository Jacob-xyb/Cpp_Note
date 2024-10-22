/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-10-15 15:23:05
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-10-15 15:43:23
 * @Description: Life is struggle.
 */
#include <stdio.h>

int SystemInteger_Expression();
void ScaleNumber_BasicShow();

int main()
{
    SystemInteger_Expression();
    ScaleNumber_BasicShow();
    return 0;
}

/// @brief 进制数的表达
/// @return
int SystemInteger_Expression()
{
    int val_dec = 11;
    int hex_val = 0x11;
    int oct_val = 011;

    printf("11 is %d\n", val_dec);
    printf("0x11 is %d\n", hex_val);
    printf("011 is %d\n", oct_val);

    printf("11 in decimal is %d\n", val_dec);
    printf("11 in hexadecimal is %x\n", val_dec);
    printf("11 in octal is %o\n", val_dec);
}


void ScaleNumber_BasicShow()
{
    // 以数字 28 为例；
    int xDec = 28;      // 十进制
    int xHex = 0x1c;    // 十六进制 0x 或 0X
    int xOct = 034;     // 八进制 0
    int xBin = 0b11100; // 二进制 0b
    // Tips: 不是所有的C语言都有二进制表示法

    printf("Dec=%d, xHex=%d, Oct=%d, Bin=%d", xDec, xHex, xOct, xBin);
}