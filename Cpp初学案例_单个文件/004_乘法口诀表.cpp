/*
案例：乘法口诀表 by 嵌套循环
说明：利用 for 嵌套循环，实现九九乘法口诀表。
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << "x" << i << "=" << i*j << "\t";
        }
        cout << endl;
    }

    system("pause");
    
    return 0;
}