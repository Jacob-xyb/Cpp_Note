#include <iostream>
#include <time.h>
#include "第三方库测试.h"
using namespace std;


int main()
{
	for (int i = 0; i < 4; i++)
	{
		double step = bool(i != 0) * pow(10, -i) * 1e-2;
		cout << step << endl;
	}
    srand(time(NULL)); /*根据当前时间设置“随机数种子”*/
    //test_Jx();
    system("pause");
    return 0;
}