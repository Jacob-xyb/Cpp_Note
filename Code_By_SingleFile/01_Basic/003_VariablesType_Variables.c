#include <stdio.h>

int number = 100;

void Variables_not_init();

int main(int argc, char const *argv[])
{
    Variables_not_init();

    int number = 99;
    printf("number=%d\n", number);   // 99; 局部变量与全局变量名字相同时，取近原则，局部变量优先
    printf("number=%d\n", ::number); // 100; :: 显示全局作用域

    return 0;
}

void Variables_not_init()
{
    printf("++ Variables_not_init ++\n");
    // 变量一定要初始化
    int a, b, c, d, e, f;

    printf("%d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f); // 会产生垃圾值
    // 某一次运行结果: 0, 16, 0, 7684384, 0, 122

    printf("++ Variables_not_init End ++\n\n");
}