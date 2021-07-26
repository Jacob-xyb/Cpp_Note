/*
案例：数组元素逆置 
说明：给一个数组逆置，并依次输出。
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};

    int rearr[5] = {};

    for (int idx = 0; idx < 5; idx++)
    {
        rearr[4-idx] = arr[idx];
        
    }

    for (int i = 0; i < 5; i++)
    {
        cout << rearr[i] << ",";
    }
    
    return 0;
}