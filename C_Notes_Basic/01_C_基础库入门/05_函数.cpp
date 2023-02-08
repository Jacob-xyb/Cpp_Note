#include <stdio.h>
#include "C_Basic_main.h"

#include <stdarg.h>

#pragma region func_可变参数
double average(int i, ...) {
    double total = 0;
    va_list ap;
    va_start(ap, i);
    for (int j = 1; j <= i; ++j) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / i;
}
#pragma endregion
