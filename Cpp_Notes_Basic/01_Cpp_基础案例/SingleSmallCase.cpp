#include "SingleSmallCase.h"
#include <iostream>

using namespace std;

void SingleSmallCase::NumberGuessingGame()
{
	srand((unsigned int)time(NULL));  // 根据时间生成一个随机数就是一个 真随机数，不然 rand()只会是一个 伪随机数。
	int num = rand() % 100 + 1;
	int times = 1;
	int ans = 0;

	while (true)
	{
		printf("第 %02d 次尝试", times++);
		cout << "输入猜测的数字(1~100)： " << endl;
		cin >> ans;

		if (ans == num)
		{
			cout << "恭喜你猜对了！" << endl;
			break;
		}
		else if (ans > num)
		{
			cout << "你猜大了..." << endl;
		}
		else
		{
			cout << "你猜小了..." << endl;
		}

		cout << endl;
	}

	char res = getchar();
}

void SingleSmallCase::DaffodilNumber()
{
	int num = 100;
	int sum = 0;
	do
	{
		int a = 0; int b = 0; int c = 0;
		a = num % 10;   // 获取个位数
		b = num / 10 % 10;  // 获取十位数
		c = num / 100;  // 获取百位数
		if (num == a * a * a + b * b * b + c * c * c)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);

	char res = getchar();
}

void SingleSmallCase::BubbleSort(int* arr, int num)
{
	for (int tms = num - 1; tms > 0; tms--)       // 每次排序的次数是从 总个数-1 ~ 1
	{
		for (int i = 0; i < tms; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
}
