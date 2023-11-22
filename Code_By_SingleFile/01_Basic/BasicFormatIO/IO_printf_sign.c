#include <stdio.h>

/// @brief -: 在%后紧跟-表示左对齐，前提是设置了默认宽度
void sign_test_leftAlign();

/// @brief +:有符号值显示正负号
void sign_test_showsign();

/// @brief space: 有符号值为正，前面显示一个空格；为负，前面显示负号
void sign_test_space();

/// @brief #:把结果转换为另一种形式
void sign_test_sharp();

/// @brief 0:多余空间用前导0填充；对于整数格式，如果出现-标记或指定精度，则忽略该标记。
void sign_test_zero();

int main(int argc, char const *argv[])
{
    sign_test_leftAlign();
    sign_test_showsign();
    sign_test_space();
    sign_test_sharp();
    sign_test_zero();
    return 0;
}

void sign_test_leftAlign()
{
    printf("++ sign_test_leftAlign ++\n");

    char content[] = "hello";
    printf("*%s*\n", content);
    printf("*%-s*\n", content);   // 在不设置宽度的情况下，输出无变化
    printf("*%10s*\n", content);  // 默认右对齐
    printf("*%-10s*\n", content); // 设置左对齐

    printf("++ sign_test_leftAlign END ++\n\n");
}

void sign_test_showsign()
{
    printf("++ sign_test_showsign ++\n");

    // 对%s无效
    char content[] = "hello";
    printf("%s\n", content);
    printf("%+s\n", content);

    // 对无符号值无效
    unsigned int u_int = 123;
    printf("%u\n", u_int);  // 123
    printf("%+u\n", u_int); // 123

    // 只对有符号转换符有效
    printf("%+d\n", u_int); // +123

    printf("++ sign_test_showsign END ++\n\n");
}

void sign_test_space()
{
    printf("++ sign_test_space ++\n");

    printf("*%d*\n", 123);
    printf("*% d*\n", 123);
    printf("*%   d*\n", 123); // 多个空格等效于一个空格
    printf("*% d*\n", -123);  // 为负，前面显示一个负号

    printf("++ sign_test_space END ++\n\n");
}

void sign_test_sharp()
{
    printf("++ sign_test_sharp ++\n");

    // 对于进制输出，则在输出前显示进制表示方式 0,0x 等
    printf("%%o(10):%o\n", 10);   // 12
    printf("%%#o(10):%#o\n", 10); // 012

    // 对于浮点格式，#保证了即使后面没有任何数字，也打印一个小数点
    printf("%%.f(10):%.f\n", 10.);   // 10
    printf("%%#.f(10):%#.f\n", 10.); // 10.

    printf("%%.g(10):%.g\n", 10.);   // 1e+001
    printf("%%#.g(10):%#.g\n", 10.); // 1.e+001

    printf("++ sign_test_sharp END ++\n\n");
}

void sign_test_zero()
{
    printf("++ sign_test_sharp ++\n");

    printf("%%05d(10):%05d\n", 10);   // 00010
    printf("%%05d(10):%05.3d\n", 10); //  010

    printf("++ sign_test_sharp END ++\n\n");
}
