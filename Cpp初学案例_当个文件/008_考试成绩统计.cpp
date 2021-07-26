/*
案例：考试成绩统计 by 二维数组 
说明：有三名同学（张三，李四，王五），在一次考试中的成绩如下，分别输出三名同学的总成绩：
        语文    数学    英语
张三    100     100     100
李四    90      50      100
王五    60      70      80

改进：
1. 用string数组记录名字；
*/

#include <iostream>
#include <string>       // 导入 string，但是不写好像没报错
using namespace std;

int main()
{
    int grade[3][3] =
    {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };

    int sumG[3] = {};
    string names[3] = {"张三","李四","王五"};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumG[i] += grade[i][j];
        }

        cout << names[i] << "的总成绩为： " << sumG[i] << endl;
    }

    // cout << sizeof(names) << endl;
    // cout << sizeof(names[0]) << endl;

    return 0;

}