#include "Transfer.h"

void Call_TypeChar() {
	char ch = 'a';		// 声明方式
	std::cout << "字符型内存中存储的是对应的ASCII码: a-" << int('a') << std::endl;	// 97
	std::cout << "字符型内存中存储的是对应的ASCII码: A-" << int('A') << std::endl;	// 65
}

void Func_CharStar(char* ch) {
	std::cout << ch << std::endl;
}

void Call_CharStar() {
	char ch[] = "hello";
	std::cout << ch << std::endl;
	Func_CharStar(ch);		// ch 是 char 数组的指针
}

void Research_CharArray() {
	char s1[] = "hello world";
	s1[0] = 'H';
	std::cout << s1 << std::endl;		// 能够正常打印，因为 s1 是数组

	const char* s2 = "hello world";
	//s2[0] = 'H';		// 报错，因为 s2 是一个指针指向了字符串的第一个字符所在地址
}

void Research_CharArray1() {
	const char* str1 = "abcd1234";
	char str2[] = "abcd1234";
	printf("%u  %u\n", strlen(str1), strlen(str2));

	const char* str3 = "abcd1234";
	char str4[] = "abcd1234";
	printf("%p  %p\n", str1, str3);		// 00007FF699FD2268  00007FF699FD2268
	printf("%p  %p\n", str2, str4);		// 0000006F96D6FCE0  0000006F96D6FCF0

	strncpy_s(str2, str4, 4);		// 将 str4 的前 4 个字符复制到 str2
	printf("%s\n%s\n", str2, str4);		// 可修改，但是 char* 不可修改
}


