/*
案例：五只小猪称体重 by 数组
说明：给一个数组记录五只小猪的体重，找出并打印最重的小猪体重。
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {300,350,200,400,250};

    int idx = 0;

    for (int i = 0; i < 5; i++)
    {
        if (arr[idx] < arr[i])
        {
            idx = i;
        }
        
    }

    cout << "第" << idx+1 << "只小猪最重，有" << arr[idx] << "kg" << endl;

    return 0; 
    
}