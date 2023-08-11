#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int c_a = 0x61;
    printf("c_a = %c\n", c_a);

    printf("\\111 = \111\n");   // '\111' === 'I' === 74
    printf("\\x61 = \x61\n");   // '\x61' === 'a' === 97
    printf("%d", '\111' == 73); // 1
    return EXIT_SUCCESS;
}
