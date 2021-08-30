#include "../Jx_进阶案例.h"

//结构体属于用户 自定义的数据类型，允许用户存储不同的数据类型

//定义 结构体
struct Student
{
	//struct 结构体名 { 结构体成员列表 } object_names；
	//`object_names` 是变量的名称，理论上可以省略
	// 
	//成员列表
	string m_Name;
	int m_Age;
	int m_Score;
	string m_Hobby;
};

//创建具体结构体对象
void struct_Jx001()
{
	// 第一种：struct Student s1
	// 第二种：struct Student s2 = {...}
	// 第三种：在创建结构体时就创建一个结构体变量

	//第一种：struct Student s1
	Student s1;
	s1.m_Name = "张三";
	s1.m_Age = 18;
	s1.m_Score = 0;

	//第二种：struct Student s2 = {...}
	Student s2 = { "李四", 20, 10 };	//不是很推荐
	
	//第三种：在创建结构体时就创建一个结构体变量
	//	假设s3已经被创建了，可以直接 s3 = {...};

	//研究一下能否被重置
	s2 = { "王五", 24, 60 };	//具体对象可以被重置
	s2 = { "赵六" };	//只重置一个变量呢？
	cout << s2.m_Name << " " << s2.m_Age << " " << s2.m_Score << " " << s2.m_Hobby << endl;	//赵六 0 0 NULL
	s2 = {};	//还可以重置为空
	cout << s2.m_Name << " " << s2.m_Age << " " << s2.m_Score << " " << s2.m_Hobby << endl;	//NULL 0 0 NULL
}

//结构体指针
void struct_Jx002()
{
	Student s1 = { "张三", 20, 10 };

	//创建结构体指针
	struct Student* p = &s1;

	//结构体指针访问属性
	cout << "姓名：" << p->m_Name << endl;		// p->name == (*p).name
}
