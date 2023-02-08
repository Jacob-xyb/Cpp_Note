#include <stdio.h>
//#include "C_Basic_main.h"

#pragma region Point_简介
void func_Point_Intro() {
	// 一个指针指向的可能还是指针，这时就要用两个星号**表示。
	int** foo;
}
#pragma endregion

#pragma region Point_*
void func_Point_SignStar() {
	// *还可以取址
	int x = 10;
	int* p = &x;
	printf("取址后的结果: %d", *p + 1);
}

void func_Point_SignAnd() {
	// *还可以取址
	int x = 10;
	printf("x's address is %p\n", &x);
}
#pragma endregion

