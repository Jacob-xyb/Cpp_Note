#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f;

    printf("%d, %d, %d, %d, %d, %d", a, b, c, d, e, f);  // 会产生垃圾值
    // 某一次运行结果: 0, 16, 0, 7684384, 0, 122

    return 0;
}
