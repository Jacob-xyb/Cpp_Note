#include <stdio.h>

void Display_BuiltInType()
{
    printf("int-size:\t%d\n", sizeof(int));     // 4
    printf("float-size:\t%d\n", sizeof(float)); // 4
}

int main()
{
    Display_BuiltInType();
    return 0;
}