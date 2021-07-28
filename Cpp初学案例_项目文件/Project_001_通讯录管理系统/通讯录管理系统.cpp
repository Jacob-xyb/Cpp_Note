// GB2312(936)
#include <iostream>
#include "..\function.h"
using namespace std;

// global const
#define MAX 1000		// 最大人数
// 显示菜单界面

// 打断点，清屏


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

 //结构体：人
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

// 共用函数
int isNull(struct AddressBooks* abs)
{
	if (abs->m_Size < 1)
	{	
		cout << "当前通讯录为空" << endl;
		return 0;
	}
	return 1;
}

// 打印联系人
void prtSinglePerson(Person abs[], int i)
{
	cout << "姓名：" << abs[i].m_Name << endl;
	cout << "性别：" <<
		(abs[i].m_Sex == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << abs[i].m_Age << "\t";
	cout << "电话" << abs[i].m_Phone << endl;
	cout << "地址" << abs[i].m_Addr << endl;
	cout << endl;
}

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
	if (! isNull(abs))
	{
	}
	else
	{
		cout << endl;
		for (int i = 0; i < abs->m_Size; i++)
		{
			prtSinglePerson(abs->personArray, i);
		}
	}

	// clear
	SleepAndClear();
}

// 3、删除联系人
int isExist(AddressBooks* abs, string name)
{
	 //判读联系人是否存在，返回联系人所在数组中的具体位置，不存在放回-1
	for (int i = 0; i < abs->m_Size; i++)
	{
	if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}

void deletePerson(AddressBooks* abs)
{	
	if (! isNull(abs))
	{
		// clear
		SleepAndClear();
		return;
	}
	cout << "请输入您想要删除的联系人" << endl;
	string name;
	cin >> name;
	// ret == -1 没查到
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		// 查询到后进行数组左移实现删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size --;
		cout << "删除成功" << endl;
	}
	// clear
	SleepAndClear();
}

// 4、查找联系人
void findPerson(struct AddressBooks* abs)
{
	// 先判断是否为空
	if (!isNull(abs))
	{
		SleepAndClear();
		return;
	}
	else
	{
		cout << "请输入您想查找的联系人姓名：" << endl;
		string name;
		cin >> name;
		// for 循环查找
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			cout << endl;
			prtSinglePerson(abs->personArray, ret);
		}
		else
		{
			cout << "联系人\"" << name << "\"不在通讯录中" << endl;
		}

		// cls
		SleepAndClear();
	}
}

// 5、修改联系人
void modifyPerson(AddressBooks* abs)
{	
	// 先判断是否为空
	if (!isNull(abs))
	{
		SleepAndClear();
		return;
	}
	// 找寻过程中判断是否存在
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
		system("cls");
	}
	// modify person
	else
	{
		system("cls");
		// 声明菜单变量
		string menuArr[] = {
			"1、修改联系人姓名",
			"2、修改联系人性别",
			"3、修改联系人年龄",
			"4、修改联系人电话",
			"5、修改联系人地址",
			"0、退出修改",
		};
		while (true)
		{	
			// 打印菜单
			for (int i = 0; i < 5; i++)
			{
				cout << "****  " << menuArr[i] << "  ****" << endl;
			}
			cout << "****  " << menuArr[5] << "        ****" << endl;
			// 打印需要修改的用户信息
			cout << "当前用户信息为：" << endl;
			cout << endl;
			prtSinglePerson(abs->personArray,ret);

			// 用户输入
			cout << "请输入修改项目：" << endl;
			int mSelect;
			cin >> mSelect;
			TypeInt(&mSelect);
			string tempS;
			int tempI;
			switch (mSelect)
			{
			case 1:
				cout << "请输入修改后姓名" << endl;
				cin >> tempS;
				abs->personArray[ret].m_Name = tempS;
				break;
			case 2:
				cout << "请输入修改后性别" << endl;
				while (true)	// 指定输入 1 or 2
				{
					cin >> tempI;
					TypeInt(&tempI);
					if (tempI == 1 || tempI == 2)
					{
						abs->personArray[ret].m_Sex = tempI;
						break;
					}
					cout << "性别输入有误，请重新输入：";
				}
				break;
			case 3:
				cout << "请输入修改后年龄" << endl;
				while (true)
				{
					cin >> tempI;
					TypeInt(&tempI);
					if (tempI >= 0)
					{
						abs->personArray[ret].m_Age = tempI;
						break;
					}
					else
					{
						cout << "请输入正确年龄：" << endl;
					}
				}
				break;
			case 4:
				cout << "请输入修改后电话" << endl;
				cin >> tempS;
				abs->personArray[ret].m_Phone = tempS;
				break;
			case 5:
				cout << "请输入修改后地址" << endl;
				cin >> tempS;
				abs->personArray[ret].m_Addr = tempS;
				break;
			case 0:
				system("cls");
				return;
			default:
				break;
			}
			system("cls");
		}
	}
}

// 6.清空联系人
void cleanPerson(AddressBooks* abs)
{
	cout << "当前通讯录共有：" << abs->m_Size << "人" << endl;
	cout << "请确认是否清空联系人(yes/no)" << endl;
	string choose;
	cin >> choose;
	if (choose == "yes")
	{
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "输入错误，未能成功清空联系人" << endl;
	}
	SleepAndClear();
}

int main()
{
	// 创建通讯录结构体变量
	struct AddressBooks abs;
	// 初始化通讯录中的当前人员个数
	abs.m_Size = 0;


	while (true)
	{
		showMenu();
		int select = 0;
		cin >> select;
		TypeInt(&select);

		switch (select)
		{
		case 1:     // "1、添加联系人",
			addPerson(&abs);    // 利用地址传递可以修饰实参
			break;
		case 2:     // "2、显示联系人",
			showPerson(&abs);
			break;
		case 3:     // "3、删除联系人",
			deletePerson(&abs);
			break;
		case 4:     // "4、查找联系人",
			findPerson(&abs);
			break;
		case 5:     // "5、修改联系人",
			modifyPerson(&abs);
			break;
		case 6:     // "6、清空联系人",
			cleanPerson(&abs);
			break;
		case 0:     // "0、退出通讯录",
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}
