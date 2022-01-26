#include <stdio.h>
#include <iostream>
#include "../Proj/BookNotes_Head.h"
using namespace std;

void heima_cpp_heap_area()
{
    int* p = new int(10);       //new 返回的是该类型的指针
    int* arr = new int[10];     //10代表数组有10个元素，返回数组的首地址
    delete[] arr;               //手动释放数组
    cout << p << endl;
}

void CSDN_douhaoyunsuanfu()
{
    int a = 1;
    int b = 2;
    int c = (a, b++, a += b);
    cout << c << endl;
}