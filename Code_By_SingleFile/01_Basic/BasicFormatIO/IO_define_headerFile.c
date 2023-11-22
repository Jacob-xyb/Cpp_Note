#include <stdio.h>  // 整型限制
#include <limits.h> // 浮点型限制
#include <float.h>

void Example_CPrimerPlus_45();

int main(void)
{
    Example_CPrimerPlus_45();
    return 0;
}

/// @brief 展示C语言中定义的一些限制
void Example_CPrimerPlus_45()
{
    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system,\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float; %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
}