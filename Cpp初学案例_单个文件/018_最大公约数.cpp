/*
encoding: GB2312(936)
*/

#include <iostream>
using namespace std;

void findCommonDivisor_Jx()
{
	int div_a, div_b;
	cout << "请输入两个数：" << endl;
	cin >> div_a >> div_b;
	int temp = 0;
	temp = div_a > div_b ? div_b : div_a;
	for (int i = temp; i >= 1; i--)
	{
		if (div_a % i == 0 && div_b % i == 0)
		{
			cout << "最大公约数为：" << i << endl;
			break;
		}
	}
}

void findCommonDivisor_Runoob()
{
	int n1, n2;

	cout << "输入两个整数：" << endl;
	cin >> n1 >> n2;

	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}

	cout << "最大公约数为：" << n1 << endl;
}

int main()
{
	//findCommonDivisor_Jx();
	findCommonDivisor_Runoob();
	system("pause");
	return 0;
}