#include <stdio.h>

void Func_printf_placeholder()
{
}

void Func_printf_format_minwidth()
{
    int a = 123456;
    printf("a = %1d\n", a); // 指定宽度不足时， 不会遮掩数字本身
    printf("a = %10d\n", a);

    printf("\n=== test fill with zero. ===\n");
    printf("a = %010dHHH\n", a);
    printf("a = %-10dHHH\n", a);
    printf("a = %-010dHHH\n", a);  // 在左对齐下，0填充失效
}

void Func_printf_format_sign()
{
    int a = 123;
    printf("a = %+d\n", a);
    printf("a = %+5d\n", a);
}

void Func_printf_format_alignment()
{
    int a = 123;
    printf("a = %-10dHHH\n", a);
}

void func_printf_format_limitDigits() {
	printf("%.2f\n", 1.2345); // 1.23

	// 限制位数只限制小数点后位数，对整数无效
	printf("%.2d\n", 12345); // 12345

	// 采用 * 代替限定值
	printf("%.*f\n", 2, 1.2345); // 1.23
	printf("%*.*f\n", 5, 2, 1.2345); // ' 1.23'
	printf("%+*.*f\n", 5, 2, 1.2345); // +1.23
}

int main(int argc, char const *argv[])
{
    // Func_printf_format_minwidth(); // 最小宽度
    // Func_printf_format_sign(); // 正负号
    // Func_printf_format_alignment(); // 对齐方式
    func_printf_format_limitDigits(); // 限制浮点数位数
    return 0;
}
