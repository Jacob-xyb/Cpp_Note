#include <iostream>

using namespace std;

void CharInitError()
{
    string str1 = "Hello World";
    // char chars1[] = str1;  // string 是变量，不能用于初始化 char[]
    // char chars1[] = str1.c_str();  // char* 不能对 char[] 赋值

    char charHello[] = "Hello World";
    // char chars1[] = charHello;   // char* 不能对 char[] 赋值
}

int main(int argc, char const *argv[])
{
    return 0;
}
