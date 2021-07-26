#include "function.h"

void printStart(int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "*";
    }   
}

// int 类型输入判断
void TypeInt(int* val)
{
	while (cin.fail())
	{
		cin.clear();		// 错误位重置，这句话一定要写的
		cin.ignore();
		cout << "输入错误，请输入一个整数：";
		cin >> *val;
	}
}

void SleepAndClear()
{
	// clear
	// windows
	system("pause");
	system("cls");

	// mac
	// cout << "please press any key to continue...";
	// string PAUSE;
	// cin >> PAUSE;
	// system("clear");
}