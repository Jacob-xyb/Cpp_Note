#include <stdio.h>
#include "C_Basic_main.h"

#include <string.h>

#pragma region String_简介
void func_String_Intro() {
	char s[] = "Hello, world!";
	const char* sp = "Hello, world!";
}
#pragma endregion

#pragma region String_声明
void func_String_Statement() {
	char s[50] = "Hello, world!";
	strcpy_s(s, "替换字符串数组成功");
	printf("%s", s);
}
#pragma endregion

#pragma region String_操作
// 返回字符串的字节长度
void func_String_strlen() {
	const char* str = "hello";
	int len = strlen(str); // 5
}
// 字符串的复制
void func_String_strcpy() {
	const char* s1 = "man";
	char s2[40] = "Be the best that you can be.";
	char* ps;
	ps = strcpy(s2 + 7, s1);
	puts(s2);
	puts(ps);
}
// 字符串的拼接
void func_String_strncat() {
	char s1[10] = "Monday";
	char s2[8] = "Tuesday";
	strncat(s1, s2, 3);
	puts(s1); // "MondayTue"
}
#pragma endregion


