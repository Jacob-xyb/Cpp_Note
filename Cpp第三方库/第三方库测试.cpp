#include <iostream>
#include <time.h>
#include "第三方库测试.h"
using namespace std;


int main()
{
    srand(time(NULL)); /*根据当前时间设置“随机数种子”*/
    test();
    system("pause");
    return 0;
}