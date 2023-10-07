#include <stdio.h>

void int_printf_scale(void);

int main(int argc, char const *argv[])
{
    int_printf_scale();
    
    return 0;
}

void int_printf_scale()
{
    int x = 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
    
    // '#' 会显示进制的前缀 0x, 0,
}