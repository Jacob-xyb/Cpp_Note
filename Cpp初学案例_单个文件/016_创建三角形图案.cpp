#include <iostream>
using namespace std;

void drawTriangle01()
{
	int rows;

	cout << "输入行数: ";
	cin >> rows;

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void drawTriangle02()
{
	char input, alphabet = 'A';

	cout << "输入最后一个大写字母: ";
	cin >> input;

	for (int i = 1; i <= (input - 'A' + 1); ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << alphabet << " ";
		}
		++alphabet;

		cout << endl;
	}
}

void drawTriangle03()
{
	int rows;

	cout << "输入行数: ";
	cin >> rows;

	for (int i = rows; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << j << " ";
		}
		cout << endl;
	}

}

void drawTriangle04()
{
	int space, rows;

	cout << "输入行数: ";
	cin >> rows;

	for (int i = 1, k = 0; i <= rows; ++i, k = 0)
	{
		for (space = 1; space <= rows - i; ++space)
		{
			cout << "  ";
		}

		while (k != 2 * i - 1)		// * 的个数
		{
			cout << "* ";
			++k;
		}
		cout << endl;
	}
}

int main()
{
	drawTriangle03();

	system("pause");
	return 0;
}