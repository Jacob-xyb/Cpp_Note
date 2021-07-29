/*
encoding: GB2312(936)
*/

#include <iostream>
using namespace std;

void swap(int a[], int b[], int len)
{
	for (int i = 0; i < len; i++)
	{
		a[i] = b[i];
	}
}

void yanghuiTriangleJx()
{

	cout << "请输入行数：" << endl;
	int row;
	cin >> row;

	int up[1000] = { 1,1 };
	int next[1000] = { 1 };

	for (int i = 1; i <= row; i++)		// 行数
	{
		int loop = row - i;
		while (loop>0)
		{
			cout << " ";
			loop--;
		}
		if (i > 2)
		{
			cout << 1 << " ";
			for (int j = 0; j < i-1; j++)
			{
				int temp = up[j] + up[j + 1];
				cout << temp << " ";
				next[j + 1] = temp;
			}
			swap(up, next, i);
		}
		else if (i == 1)
		{
			cout << 1;
		}
		else if (i==2)
		{
			cout << 1 << " " << 1;
		}
		cout << endl;		// 统一在此处转行
	}
}


// 自相关杨辉三角形
void runoob()
{
	int rows, coef = 1;

	cout << "Enter number of rows: ";
	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		for (int space = 1; space <= rows - i; space++)
			cout << "  ";

		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;

			cout << coef << "   ";
		}
		cout << endl;
	}
}

int main()
{
	yanghuiTriangleJx();
	//runoob();
	system("pause");
	return 0;
}