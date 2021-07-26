/*
案例：找寻水仙花数字 by (do ... while ...)
说明：水仙花数字：一个3位数，每个位上的数字的3次幂之和等于它本身。
规则：用do while 求出所有3位数中的水仙花数。
*/

#include <iostream>
using namespace std;

int main(){

    int num = 100;
	int sum = 0;
	do
	{
		int a = 0; int b = 0; int c = 0;
		a = num % 10;   // 获取个位数
        b = num / 10 % 10;  // 获取十位数
        c = num / 100;  // 获取百位数
		if (num == a*a*a + b*b*b + c*c*c)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);

    system("pause");

    return 0;

}
