#include <iostream>
#include <stdio.h>

using namespace std;

void Func_s_print_string()
{
    string str1 = "hello world1";
    printf("%s\n", str1);       // 无法正确输出
    // string类型的对象并非单单只有字符串，其内还有许多用于操作的函数
    // string.c_str() 才会返回字符串的首地址
    printf("%s\n", str1.c_str());

    char str2[] = "hello world2";
    printf("%s\n", str2);
}

int main(int argc, char const *argv[])
{
    return 0;
}
