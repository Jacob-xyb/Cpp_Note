#include <stdio.h>
#include <stdbool.h>
//#include "C_Basic_main.h"

#pragma region DataType_Char
void func_DataType_Char() {
	// char 类型就是一个字节的整数来存储
	char c;
	c = 65;
	printf("%c", c);  // A
	c = 'A';
	printf("%d\n", c);  // 65

	// 还可以作加法运算
	printf("%d\n", c + c); // 130
}
// 字符的其他表示方法
void func_DataType_Char_OtherRepresentation() {
	// 转义写法还能使用八进制和十六进制表示一个字符。
	char x;
	x = 'B';
	x = 66;
	x = '\102'; // 八进制
	x = '\x42'; // 十六进制
	printf("%c\n", x);
}
#pragma endregion

#pragma region DataType_Int
void func_DataType_Int() {
	/*16位：-32,768 到 32,767。
	  32位：-2,147,483,648 到 2,147,483,647。
	  64位：-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807。	*/
	int a;

	// signed，unsigned
	// signed int 等同于 int
	// unsigned 有一个好处, 同样长度的内存能够表示的最大整数值，增大了一倍
	unsigned int b;
}
// 整数的子类型
void func_DataType_Int_Subtype() {
	/*short int（简写为short）：占用空间不多于int，一般占用2个字节（整数范围为-32768～32767)。
	  long int（简写为long）：占用空间不少于int，至少为4个字节。
	  long long int（简写为long long）：占用空间多于long，至少为8个字节。*/

	  // C 语言允许省略int，所以变量声明语句也可以写成下面这样。
	short a;
	unsigned long b;
}
// 整数的极限值
void func_DataType_Int_Limit() {
	// 有时候需要查看，当前系统不同整数类型的最大值和最小值，C 语言的头文件 limits.h 提供了相应的常量
	/*为了代码的可移植性，需要知道某种整数类型的极限值时，应该尽量使用这些常量。
	SCHAR_MIN，SCHAR_MAX：signed char 的最小值和最大值。
	SHRT_MIN，SHRT_MAX：short 的最小值和最大值。
	INT_MIN，INT_MAX：int 的最小值和最大值。
	LONG_MIN，LONG_MAX：long 的最小值和最大值。
	LLONG_MIN，LLONG_MAX：long long 的最小值和最大值。
	UCHAR_MAX：unsigned char 的最大值。
	USHRT_MAX：unsigned short 的最大值。
	UINT_MAX：unsigned int 的最大值。
	ULONG_MAX：unsigned long 的最大值。
	ULLONG_MAX：unsigned long long 的最大值。*/
}
// 进制
void func_DataType_Int_NumberSystems() {
	int x;
	// 八进制使用0作为前缀，比如017、0377。
	x = 012;
	printf("%d\n", x);  // 10

	// 十六进制使用0x或0X作为前缀，比如0xf、0X10
	x = 0xf;
	printf("%d\n", x);  // 15

	// 有些编译器使用0b前缀，表示二进制数，但不是标准。
	x = 0b1010;
	printf("%d\n", x);  // 10

	/*printf()的进制相关占位符如下。
	%d：十进制整数。
	%o：八进制整数。
	%x：十六进制整数。
	%#o：显示前缀0的八进制整数。
	%#x：显示前缀0x的十六进制整数。
	%#X：显示前缀0X的十六进制整数。*/
	x = 100;
	printf("dec = %d\n", x); // 100
	printf("octal = %o\n", x); // 144
	printf("hex = %x\n", x); // 64
	printf("octal = %#o\n", x); // 0144
	printf("hex = %#x\n", x); // 0x64
	printf("hex = %#X\n", x); // 0X64
}
#pragma endregion

#pragma region DataType_Float
void func_DataType_Float() {
	// 所谓“浮点数”就是使用 m * be 的形式，存储一个数值，m是小数部分，b是基数（通常是2），e是指数部分。
	// float类型占用4个字节（32位），其中8位存放指数的值和符号，剩下24位存放小数的值和符号。
	// float类型至少能够提供（十进制的）6位有效数字，指数部分的范围为（十进制的）-37到37，即数值范围为10-37到1037。
	float f;
	f = 10.5;
	double d = 10.18;

	// double：占用8个字节（64位），至少提供13位有效数字。
	// long double：通常占用16个字节。
}
// 浮点数其他表示方法
void func_DataType_Float_OtherRepresentation() {
	float f;
	f = .5;
	printf("%f\n", f);
	f = .5e3;
	printf("%f\n", f);
}
#pragma endregion

#pragma region DataType_Bool
void func_DataType_Bool() {
	// 头文件stdbool.h定义了另一个类型别名bool，并且定义了true代表1、false代表0。只要加载这个头文件，就可以使用这几个关键字
	bool flag = true;
}
#pragma endregion

#pragma region DataType_Literals
void func_DataType_Literals() {
	int x;
	x = 1;
	printf("%zu", sizeof(x));  // 4
	x = 1L;
	printf("%zu", sizeof(x));  // 4
	// Tips：虽然字面量声明的long int，但是存储时还是按变量类型存储。
}
#pragma endregion

#pragma region DataType_Overflow
void func_DataType_Overflow() {
	unsigned char x = 255;
	x = x + 1;
	printf("%d\n", x); // 0
}
#pragma endregion

#pragma region DataType_sizeof
void func_DataType_sizeof() {
	// 参数为数据类型
	int x = sizeof(int);
	// 参数为变量
	int i;
	sizeof(i);
	// 参数为数值
	sizeof(3.14);
}
#pragma endregion

#pragma region DataType_AutoConversion
// 赋值运算发生的自动转换
void func_DataType_AutoConversion_Assignment() {
	// 1.浮点数赋值给整数变量
	// ++ 浮点数赋予整数变量时，C 语言直接丢弃小数部分，而不是四舍五入。
	int x1 = 3.14;
	printf("%d\n", x1); // 3
}
// 混合类型的运算
void func_DataType_AutoConversion_MixedCalculation() {
	// signed 和 unsigned 比较时，会将 signed 转换为 unsigned
	int a = -5;
	unsigned b = 4;
	if (a < b)
	{
		printf("a < b");
	}
	else
	{
		printf("a >= b"); // 会输出这条
	}
}
#pragma endregion
