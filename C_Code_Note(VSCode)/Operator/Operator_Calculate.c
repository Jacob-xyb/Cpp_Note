/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-02-11 11:20:32
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-02-12 15:05:42
 * @Description: Life is struggle.
 */

#include <stdio.h>

void operator_calculate_modulusOperations();
/// @brief 自增自减运算符
void operator_calculate_autoOperations();
/// @brief 逗号运算符
void operator_calculate_commaOperations();

int main()
{
    operator_calculate_modulusOperations();
    operator_calculate_autoOperations();
    operator_calculate_commaOperations();
    return 0;
}

void operator_calculate_modulusOperations()
{
    // 负数求模的规则是，结果的正负号由第一个运算数的正负号决定。
    printf("%d %% %d = %d\n", 11, -5, 11 % -5);     // 11 % -5 = 1
    printf("%d %% %d = %d\n", -11, -5, -11 % -5);   // -11 % -5 = -1
    printf("%d %% %d = %d\n", -11, 5, -11 % 5);     // -11 % 5 = -1
}

void operator_calculate_autoOperations()
{
    int a = 10;
    int b;

    b = (a++ + 10);
    printf("a = %d, b = %d\n", a, b);   // a = 11, b = 20

    b = (++a + 10);
    printf("a = %d, b = %d\n", a, b);   // a = 12, b = 22
}

void operator_calculate_commaOperations()
{
    printf("** 逗号运算符 **\n");

    int a;
    a = (1, 2, 3);
    printf("a = %d\n", a);   // a = 3
}
