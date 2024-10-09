/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-06-24 16:46:36
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-06-25 11:24:55
 * @Description: Life is struggle.
 */



#include <stdio.h>

void print_placeholder();
void print_sbuString();

int main(int argc, char const *argv[])
{
    print_placeholder();
    return 0;
}

void print_placeholder()
{
    char* str = "Hello, World!";
    printf("%s\n", str);

    int num = 1018;
    // 输出十进制整数
    printf("The decimal number is %d\n", num);      // 1018
    // 输出八进制整数
    printf("The octal number is %o\n", num);        // 1772
    // 输出十六进制整数
    printf("The hex number is %x\n", num);          // 3fa
    // %后追加# 可以显示输出对应进制标志符
    printf("The octal number is %#o\n", num);       // 01772
    printf("The hex number is %#x\n", num);         // 0x3fa
}

void print_sbuString()
{
    // 缺点在于并不能以变量的形式来输出指定的长度
    // 用途：简单的只显示前n个字符。
    printf("%.5s\n", "hello world"); // hello
}
