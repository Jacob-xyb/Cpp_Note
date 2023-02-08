#include <stdio.h>
//#include "C_Basic_main.h"

#include <string.h>

#pragma region Array_简介
void func_Array_Intro() {
	// 声明数组时，必须给出数组的大小
	int scores[100];

	// 越界访问 编译器会报错
	//scores[100] = 123;

	// 数组也可以在声明时，使用大括号，同时对每一个成员赋值。
	int a[5] = { 22, 37, 3490, 18, 95 };
}
#pragma endregion

#pragma region Array_数组长度
void func_Array_Length() {
	int x[12];
	printf("%zu\n", sizeof(x));     // 48
	printf("%zu\n", sizeof(int));	// 4
	printf("%zu\n", sizeof(x) / sizeof(int)); // 12
}
#pragma endregion

#pragma region Array_多维数组
void func_Array_MultiArrays() {
	int a[2][5] = {
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9}
	};
}
#pragma endregion

#pragma region Array_数组地址
void func_Array_point() {
	int a[5] = { 11, 22, 33, 44, 55 };
	int* p;
	p = &a[0];
	printf("%d\n", *p);  // Prints "11"

	int b[3] = { 1, 2, 3 };
	printf("%d\n", *b); // 1
}
#pragma endregion

#pragma region Array_Copy
void func_Array_Copy() {
	int* a;
	int b[3] = { 1, 2, 3 };
	a = b;
	printf("%d\n", *a); // 1
	printf("%zu\n", sizeof(a)); // 8

	// memcpy 替换 for 循环赋值更为高效
	int c[3];
	memcpy(c, b, sizeof(b));
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", c[i]);
	}
}
#pragma endregion

#pragma region Array_FuncParam

#pragma endregion



