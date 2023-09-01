#include <stdio.h>

void scanf_test_n()
{
    char arr1[40], arr2[40];
    scanf("%s", arr1);
    scanf("%s", arr2);
    printf("arr1=%s,arr2=%s\n", arr1, arr2);

    char ch1;
    getchar(); // 如果没有此函数 则 ch直接被赋值 '\n'
    scanf("%c", &ch1);
    printf("ch1=%c", ch1);
    return;
}

void scanf_test_space()
{
    int a, b, c;
    // - 多次输入不能连着写 Error: %d%d%d
    // - %d %d; 则输入时应该以空格区分
    scanf("%d %d %d", &a, &b, &c);
    printf("%d,%d,%d", a, b, c);

    int x1;
    scanf("%d", x1);  // 输入 '11 22' 会报错，无法解析
    printf("%d", x1);
}

// 带空格的字符串
void scanf_test_space2()
{
    // scanf 原生函数不能接收带有空格的字符串
    char s1[64], s2[64];
    scanf("%s", s1);   // 输入 'h1 h2', s1 会接收到 'h1'
    scanf("%s", s2);   // s2 会直接读取缓存区的 'h2'
    printf("%s and %s", s1, s2);
}

int main(int argc, char const *argv[])
{
    // scanf_test_n();
    // scanf_test_space();
    scanf_test_space2();
    return 0;
}
