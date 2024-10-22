/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-10-15 17:57:53
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-10-18 16:09:59
 * @Description: Life is struggle.
 */

#include <stdio.h>

void CharArray_Init();

int main()
{
    CharArray_Init();

    return 0;
}

void CharArray_Init()
{
    // char 数组初始化方式不同，长度不一样
    char str1[] = {'a', 'b', 'c'};       // 错误的初始化方式
    char str2[] = {'a', 'b', 'c', '\0'}; // 正确的初始化方式
    char str3[] = "abc";

    puts(str1);  // abc �a, 乱码，因为结尾没有 \0.
    puts(str2);
    puts(str3);

    printf("str1 length: %d, str2 length: %d, str3 length: %d\n", sizeof(str1), sizeof(str2), sizeof(str3));  // 3 4 4
}
