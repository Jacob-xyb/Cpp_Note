/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-10-12 14:38:32
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-10-12 18:41:40
 * @Description: Life is struggle.
 */
#include <stdio.h>

void system_character_constant();

int main() 
{
    system_character_constant();

    return 0;
}

void system_character_constant()
{
    char c1 = 'a';      // 97

    // 八进制
    char c2 = '\141';   // 97 = 0o141

    // 十六进制
    char c3 = '\x61';   // 97 = 0x61

    printf("'a' = %c, '\\141' = %c\n", c1, c2);
    printf("'a' = %c, '\\141' = %c\n", c1, c3);
}