#include <stdio.h>
#include <float.h>

void print_float_info();

int main(int argc, char const *argv[])
{
    print_float_info();
    return 0;
}

void print_float_info()
{
    printf("float save bits : %lu \n", sizeof(float));
    printf("double save bits : %lu \n", sizeof(double));
    printf("long double save bits : %lu \n", sizeof(long double));

    printf("float min value: %e\n", FLT_MIN);
    printf("float max value: %e\n", FLT_MAX);
    printf("double min value: %e\n", DBL_MIN);
    printf("double max value: %e\n", DBL_MAX);
    printf("long double min value: %Le\n", LDBL_MIN);
    printf("long double max value: %Le\n", LDBL_MAX);
}
