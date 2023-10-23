#include <stdio.h>

void scanf_error_format()
{
    int a;
    printf("please input:");
    scanf("%d", &a);
    printf("result = %d\n", a);

    // 没有被scanf接收的字符，仍然存储在缓存区，等待下次被调用。
    char str[20];
    scanf("%s", str);
    printf("%s", str);

    // 1.1 => 1
    // 2d => 2
}

int main(int argc, char const *argv[])
{
    scanf_error_format();
    return 0;
}
