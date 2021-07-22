/*
案例：冒泡排序
说明：给一个数组，冒泡排序并依次输出。
流程：
1.比较相邻的元素。如果第一个比第二个大，就交换他们两个；
2.对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值；
3.重复以上的步骤，每次比较次数-1，直到不需要比较。
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {4,2,8,0,5,7,1,3,9};

    for (int tms = 8; tms > 0; tms--)       // 每次排序的次数是从 总个数-1 ~ 1
    {
        for (int i = 0; i < tms; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
            
        }
        
    }
        
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}