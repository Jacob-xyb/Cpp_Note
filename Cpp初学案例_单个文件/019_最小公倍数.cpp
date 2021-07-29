/*
encoding: GB2312(936)
*/

#include <iostream>
using namespace std;

void findCommonMultiple()
{
    int n1, n2, hcf, temp, lcm;

    cout << "输入两个数: ";
    cin >> n1 >> n2;

    hcf = n1;
    temp = n2;

    // 先算两个数的最大公因数
    while (hcf != temp)
    {
        if (hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    // 最小公倍数 = (两数相乘) / 最大公因数
    lcm = (n1 * n2) / hcf;

    cout << "LCM = " << lcm;
}


// 不推荐
void findCommonMultiple_N()
{
    int n1, n2, max;

    cout << "输入两个数: ";
    cin >> n1 >> n2;

    // 获取最大的数
    max = (n1 > n2) ? n1 : n2;

    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else
            ++max;
    } while (true);
}

int main()
{
    findCommonMultiple();
    cout << endl;

    system("pause");
    return 0;
}