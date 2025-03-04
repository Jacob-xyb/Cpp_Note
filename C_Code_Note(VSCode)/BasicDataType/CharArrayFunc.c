/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-02-13 16:48:34
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-04 14:23:52
 * @Description: Life is struggle.
 */

#include <stdio.h>

/// @brief 用于将格式化的数据写入字符串
void Func_sprintf();

/// @brief 用于检查sprintf缓冲区大小
void Func_sprintf_checkMemory();

/// @brief 用于复制字符串
void Func_strcpy();

/// @brief 用于将字符串拼接
void Func_strcat();

/// @brief 用于获取字符串长度
void Func_strlen();

/// @brief 用于比较字符串
void Func_strcmp();

/// @brief 用于比较字符串（忽略大小写）
void Func_strcasecmp();

/// @brief 用于比较字符串（忽略大小写，从右开始比较）
void Func_stricmp();

/// @brief 用于比较字符串（忽略大小写，从右开始比较，忽略空格）
void Func_strnicmp();

/// @brief 用于搜索字符串
void Func_strstr();

/// @brief 用于搜索字符串（忽略大小写）
void Func_strcasestr();

/// @brief 用于替换字符串
void Func_strreplace();

/// @brief 用于将字符串转换为数字
void Func_strtod();

/// @brief 用于将数字转换为字符串
void Func_itoa();

/// @brief 用于将字符串转换为数字
void Func_atof();

/// @brief 用于将数字转换为字符串
void Func_ftoa();

/// @brief 用于将字符串转换为大写
void Func_toupper();

/// @brief 用于将字符串转换为小写
void Func_tolower();

/// @brief 用于将字符串转换为大写
void Func_strupr();

/// @brief 用于将字符串转换为小写
void Func_strlwr();

/// @brief 用于将字符串转换为大写
void Func_strupcase();

/// @brief 用于将字符串转换为小写
void Func_strlcase();

/// @brief 用于将字符串转换为整数
void Func_atoi();

/// @brief 用于将字符串转换为长整数
void Func_atol();

int main()
{
	// Func_sprintf();
	Func_sprintf_checkMemory();
	Func_strcpy();
	return 0;
}

void Func_sprintf()
{
	puts("** sprintf function **");

	char buffer[50];
	sprintf(buffer, "Hello world!");
	puts(buffer); // Hello world!
	int num = 123;
	sprintf(buffer, "The number is %d", num);
	puts(buffer); // The number is 123
}

void Func_sprintf_checkMemory()
{
	puts("** sprintf function check memory **");
	// 如果写入的数据超过了缓冲区的大小，sprintf() 函数会返回一个非零值，并设置errno 值为 EOVERFLOW。
	// 为了避免这种情况，可以先检查缓冲区的大小，然后再调用 sprintf() 函数。

	char str[10];
	int rst = sprintf(str, "Hello world!");
	printf("Return size of buffer is %d.\n", rst);
	if (rst < 0)
	{
		printf("Error: buffer size is too small.\n", rst);
	}
	puts(str);

	// 传入的是指针，内存空间不足时，虽然可能不会报错，但是已经发生内存泄漏
}

void Func_strcpy()
{
	puts("** strcpy function **");
	
	char str1[20];
	char str2[] = "Hello world!";
	strcpy(str1, str2);
	puts(str1); // Hello world!
	char str3[] = "Jacob xyb!";
	strcpy(str1, str3);
	puts(str1); // Jacob xyb!

	char str_len[10];
	strcpy(str_len, "1234567890");
	puts(str_len);
	printf("memeory has been leaked.");
}
