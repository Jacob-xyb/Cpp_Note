/*
案例：结构体案例02 
说明：设计一个英雄的结构体，包括成员姓名，年龄，性别；
    创建结构体数组，数组中存放5名英雄。
    通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
    无名英雄信息如下：
    {"刘备", 23, "男"},
    {"关羽", 22, "男"},
    {"张飞", 20, "男"},
    {"赵云", 21, "男"},
    {"貂蝉", 19, "女"},
*/

#include <iostream>
// #include <ctime>  // 导入时间模块

using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};

void bubbleSort(struct Hero arr[], int len)     // 第三种声明方式，感觉是最好的
{
    for (int i = 1; i < len; i++)        // 外层 i 是冒泡的次数
    {
        for (int j = 0; j < len-i; j++)
        {
            if (arr[j].age > arr[j+1].age)
            {
                struct Hero temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }           
        }        
    }
}

void printInfo(struct Hero arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "英雄：" << arr[i].name << "\t"
             << "年龄：" << arr[i].age  << "\t"
             << "性别：" << arr[i].gender  << "\n";
    }
    
}

int main()
{
    struct Hero sGArr[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };

    int len = sizeof(sGArr)/sizeof(sGArr[0]);

    bubbleSort(sGArr, len);

    printInfo(sGArr, len);

}