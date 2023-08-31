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

int main(int argc, char const *argv[])
{
    scanf_test_n();
    return 0;
}
