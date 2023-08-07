#include <stdio.h>

void Func_printf(){
    int a = 666;
    printf("int = %d\n", a);
    printf("float = %f\n", a);
}

int main(int argc, char const *argv[])
{
    Func_printf();

    return 0;
}
