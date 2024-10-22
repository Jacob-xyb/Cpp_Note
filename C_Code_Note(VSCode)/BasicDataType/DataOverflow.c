/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-10-15 10:12:14
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-10-15 10:18:12
 * @Description: Life is struggle.
 */

#include <stdio.h>

void DoubleToInt();

int main() 
{
    DoubleToInt();

    return 0;
}

void DoubleToInt()
{
    int a = 89.556;   // 取整 89
    int b = 8.9556e1; // 取整 89

    printf("a = %d, b = %d\n", a, b);
}