// GB2312(936)
#include <iostream>
//#include "function.h"
using namespace std;

// global const
#define MAX 1000		// 最大人数
// 显示菜单界面

// int 类型输入判断
void TypeInt(int* val)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "输入错误，请输入一个整数：";
		cin >> *val;
	}
}

// sd

// 打断点，清屏
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

void printStart(int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "*";
	}
}

void showMenu()
{
	// 声明变量
	string menuArr[] = {
		"1、添加联系人",
		"2、显示联系人",
		"3、删除联系人",
		"4、查找联系人",
		"5、修改联系人",
		"6、清空联系人",
		"0、退出通讯录",
	};

	// main
	printStart(5 * 2 + 2 * 2 + 1 + 2 * 6);
	cout << endl;
	for (int i = 0; i < 7; i++)
	{
		printStart(5);
		cout << "  " << menuArr[i] << "  ";
		printStart(5);
		cout << endl;
	}
	printStart(5 * 2 + 2 * 2 + 1 + 2 * 6);
	cout << endl;
}

// 结构体：人
struct Person
{
	// 姓名；性别；年龄；电话；地址
	string m_Name;
	int m_Sex;      // 性别 1男 2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};


struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;     // 通讯录中人员个数
};

// 1、添加联系人
void addPerson(struct AddressBooks* abs)
{
	// 判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		// 添加具体联系人
		// add 姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		// add 性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			TypeInt(&sex);
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "性别输入有误，请重新输入：";
		}
		// add age
		int age;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			TypeInt(&age);
			if (age >= 0)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "请输入正确年龄：" << endl;
			}
		}

		// add phone
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		// add address
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		// update adressBook
		abs->m_Size++;
		cout << "添加成功" << endl;

		// clear
		SleepAndClear();
	}
}

// 2、显示联系人
void showPerson(struct AddressBooks* abs)
{
	// 先判断通讯录人数
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << endl;
			cout << "性别：" <<
				(abs->personArray[i].m_Age == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话" << abs->personArray[i].m_Phone << endl;
			cout << "地址" << abs->personArray[i].m_Addr << endl;
		}
	}

	// clear
	SleepAndClear();
}

int main()
{
	// 创建通讯录结构体变量
	struct AddressBooks abs;
	// 初始化通讯录中的当前人员个数
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:     // "1、添加联系人",
			addPerson(&abs);    // 利用地址传递可以修饰实参
			break;
		case 2:     // "2、显示联系人",
			showPerson(&abs);
			break;
		case 3:     // "3、删除联系人",
			break;
		case 4:     // "4、查找联系人",
			break;
		case 5:     // "5、修改联系人",
			break;
		case 6:     // "6、清空联系人",
			break;
		case 0:     // "0、退出通讯录",
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

		cout << endl;
	}

	return 0;
}
