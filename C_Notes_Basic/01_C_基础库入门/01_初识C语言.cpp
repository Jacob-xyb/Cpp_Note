#include <stdio.h>
//#include "C_Basic_main.h"


#pragma region hello_world
void hello_world() {
	printf("hello world");
}
#pragma endregion

#pragma region printf
void func_printf_placeholder() {
	printf("%s says it is %i o'clock\n", "Ben", 21);
}
// 输出宽度
void func_printf_width() {
	// 默认右对齐，空格填充
	printf("%5d\n", 123);  // '  123'
	// 左对齐
	printf("%-5d\n", 123); // '123  '

	printf("%12f\n", 123.45);  // '  123.450000'
	printf("%6f\n", 123.45);  // '123.450000'

	// 总是显示正负号
	printf("%+d\n", 12); // 输出 +12
	printf("%+d\n", -12); // 输出 -12
}

void func_printf_width_test() {
	// 显示正负号和左对齐先后顺序可以互换
	printf("%+-5d\n", 123); // '+123  '
	printf("%-+5d\n", 123); // '+123  '
}
// 输出限制位数(数字)
void func_printf_limit_digits() {
	printf("%.2f\n", 1.2345); // 1.23

	// 限制位数只限制小数点后位数，对整数无效
	printf("%.2d\n", 12345); // 12345

	// 采用 * 代替限定值
	printf("%.*f\n", 2, 1.2345); // 1.23
	printf("%*.*f\n", 5, 2, 1.2345); // ' 1.23'
	printf("%+*.*f\n", 5, 2, 1.2345); // +1.23
}
// 输出限制长度(字符串)
void func_printf_limit_string() {
	// 小于字符串长度时，会截取输出
	printf("%.5s\n", "hello world");	// hello
}

// 进制数的输出
void func_printf_BaseNumber() {
	int num = 100;

	//十进制 输出 %d %u %ld %lu
	printf("十进制：num=%d\n", num);//100
	//八进制 输出 %o 以0开头
	printf("八进制：num=%o\n", num);//144
	//十六进制 输出 %x 以0x开头
	printf("十六进制：num=%x\n", num);//64

	// %后追加# 可以显示输出对应进制标志符
	printf("八进制：num=%#o\n", num);//0144
	printf("十六进制：num=%#x\n", num);//0x64

	//不同进制 仅仅是数据的表现形式 不会修改数据本身
}
#pragma endregion

#pragma region 运算符

void func_calculate_sign() {
	int a;
	a = 1;
	printf("%d\n", a++);  // 1
	a = 1;
	printf("%d\n", ++a);  // 2
}

void func_digital_calculate_sign() {
	printf("%d\n", ~1);
}

void func_digital_calculate_sign_JudgeRightShiftOperator() {
	char data = 0x80;
	printf("data:%d\n", data);
	if ((data >> 2) == (char)0x20)
	{
		printf("逻辑右移");
	}
	else if ((data >> 2) == (char)0xe0)
	{
		printf("算术右移");
	}
	else {
		printf("%d", (data >> 2));
	}
}

void func_comma_calculate_sign() {
	int x;
	x = 1, 2, 3;
	// = 比 , 有更高的优先级，所以 x=1
	printf("%d\n", x);  // 1

	// 但是整个语句的返回值为最后一个表达式的值
	int y;
	y = (x = 1, 2, 3);
	printf("%d\n", y);  // 3
}

#pragma endregion

