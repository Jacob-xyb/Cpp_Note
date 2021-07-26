/*
案例：冒泡排序 by 指针 
说明：封装一个函数，利用冒泡排序，实现对整型数组的升序排序，不返回直接对原数组排序。
*/

#include <iostream>

using namespace std;

// void bubbleSort(int * arr, int len)      // 第一种声明方式
// void bubbleSort(int arr[10], int len)        // 第二种声明方式，已定义数组的大小，貌似没有意义
void bubbleSort(int arr[], int len)     // 第三种声明方式，感觉是最好的
{
    for (int i = 1; i < len; i++)        // 外层 i 是冒泡的次数
    {
        for (int j = 0; j < len-i; j++)
        {
            // 纯粹用指针的写法
            // if (*(arr+j) > *(arr+j+1))
            // {
            //     int temp = *(arr+j);
            //     *(arr+j) = *(arr+j+1);
            //     *(arr+j+1) = temp;
            // }

            // 数组的首地址已经传进来了
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }           
        }        
    }
}

int main()
{
    int arr[10] = {4,3,6,9,1,2,10,8,5,7};
    int len = sizeof(arr)/sizeof(arr[0]);


    bubbleSort(arr, len);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}