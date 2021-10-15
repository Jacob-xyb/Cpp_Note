#include <iostream>
#include "workerManager.h"

using namespace std;

#include "employee.h"
#include "manager.h"
#include "boss.h"

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

int main()
{
	WorkerManager wm;

	int choice = 0;		//存储用户的选项

	while (true)
	{
		//展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice;	//接受用户的选项

		switch (choice)
		{
		case 0:				//退出管理程序
			wm.ExitSystem();
			break;
		case 1:				//增加职工信息
			break;
		case 2:				//显示职工信息
			break;
		case 3:				//删除离职职工	
			break;
		case 4:				//修改职工信息
			break;
		case 5:				//查找职工信息
			break;
		case 6:				//按照编号排序
			break;
		case 7:				//清空所有文档
			break;
		default:
			system("cls");
			break;
		}
	}

	std::cout << "press [ENTER] to exit " << std::endl;
	std::cin.get();
	return 0;
}