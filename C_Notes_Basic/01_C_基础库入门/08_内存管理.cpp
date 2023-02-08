#include <stdio.h>
#include "C_Basic_main.h"

#include <stdlib.h>
#include <string.h>

#pragma region Memory_void指针
void func_Memory_voidPoint() {
	int x = 10;
	void* p = &x; // 整数指针转为 void 指针
	int* q2 = reinterpret_cast<int*>(p); // void 指针转为整数指针
	// or
	int* q1 = (int*)p;
}
#pragma endregion

#pragma region Memory_malloc
void func_Memory_malloc() {
	int* p = (int*)malloc(sizeof(int));
	// 如果直接对 p 分配会造成问题，所以要先确定已经分配成功
	memset(p, 0, sizeof(int));
	if (p != NULL) *p = 12;
	printf("%d\n", *p); // 12
	free(p);
}

void func_Memory_calloc() {
	int* p = (int*)calloc(10, sizeof(int));
	free(p);
}
#pragma endregion
