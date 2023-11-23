#include <stdio.h>

// 字符串常量初始化
// 这种方式会自动将字符串常量中的每个字符赋值给数组中的每个元素。
// 注意：在使用字符串常量初始化时，数组的大小必须大于等于字符串的长度加1，因为字符串常量中还包含了一个'\0'字符。
void CharInit1()
{
    char arr[] = "Hello World1";
    printf("%s, sizeof=%d\n", arr, sizeof(arr));  // 13

    // 指定了长度的情况下，也可以用字面值赋值
    char arr2[20] = "Hello World2";
    printf("%s, sizeof=%d\n", arr2, sizeof(arr2));  // 13

    // arr = arr2;
    // error: incompatible types in assignment of 'char [20]' to 'char [13]'
}

// 字符数组初始化
// 这种方式需要手动指定每个元素的值，最后一个元素必须是'\0'，表示字符串的结束。
void CharInit2()
{
    char arr[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '2', '\0'};
    printf("%s, sizeof=%d\n", arr, sizeof(arr));  // 13
}

// 部分初始化
// 这种方式只初始化了部分元素，未初始化的元素会被自动赋值为0。
void CharInit3()
{
    char arr[13] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '3'};
    printf("%s, sizeof=%d\n", arr, sizeof(arr));  // 13
}

// 全部初始化
// 这种方式会将数组中的所有元素都赋值为0。
void CharInit4()
{
    char arr[13] = {0};
    printf("%s, sizeof=%d\n", arr, sizeof(arr));  // 13
}

int main(int argc, char const *argv[])
{
    CharInit1();
    CharInit2();
    CharInit3();
    CharInit4();
    return 0;
}
