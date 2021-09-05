#include "../Jx_进阶案例.h"

/*封装*/
//封装一个简单的类：圆类
const double PI = 3.14;
class Circle
{
public:
	double m_R;		//半径
	double CirclePerimeter()
	{
		return 2 * PI * m_R;
	}
};
void Class_Jx001()
{
	//创建一个 圆类 对象
	Circle c1;
	c1.m_R = 10;
	cout << "c1周长: " << c1.CirclePerimeter() << endl;
}
//封装一个较普通的类：学生
class Student
{
public:		//权限
	//属性
	string mName;
	int mId;
	//行为
	void showStudent()
	{
		cout << "姓名: " << this->mName << endl;
		cout << "学号: " << this->mId	<< endl;
	}
	//	赋值函数
	void setName(string& name) { this->mName = name; }
	void setId(int id) { this->mId = id; }
};
//访问权限
class PersonPermission
{
public:
	//公共权限
	string mName;
protected:
	//保护权限
	string mCar;
private:
	//私有权限
	int mIdPassword;
public:
	void func()		//类内可以访问所有权限
	{
		this->mName = "Jx";
		this->mCar = "Porsche";
		this->mIdPassword = 666666;
	}
};
void Class_Permission()
{
	PersonPermission p1;
	p1.mName = "张三";	//类外只能访问公共权限
}
//diff in struct and class
struct DiffInStruct
{
	int m_A;		//默认权限为公共权限
};
class DiffInClass
{
	int m_A;		//默认权限为私有权限
};
void Class_DiffInStructAndClass()
{
	DiffInStruct obj_1;
	obj_1.m_A = 100;	//struct 可以访问
	DiffInClass obj_2;
	//obj_2.m_A = 100;	//class 不可以访问
}
//自己控制成员属性的读写权限
class PersonPermission01
{
public:
	//写姓名
	//字符串最好不要用引用，直接输入字符串时，无法用引用传参
	void setName(string name) {this->mName = name;}
	//读姓名
	string getName() {return this->mName;}
	//只读年龄
	int getAge() { this->mAge = 18; return this->mAge; }
	//只写爱好
	void setHobby(string hobby) { this->mHobby = hobby; }
private:
	string mName;		//可读可写
	int mAge;			//只读
	string mHobby;		//只写
};
void Class_Permission01()
{
	PersonPermission01 p1;
	p1.setName("张三");
	cout << p1.getName()	<< endl;
	cout << p1.getAge()		<< endl;
	p1.setHobby("coding");
}

/*构造函数和析构函数*/
//语法
class PersonJx001
{
public:
	//构造函数
	PersonJx001()
	{
		cout << "构造函数的调用" << endl;
	}
	//析构函数
	~PersonJx001()
	{
		cout << "析构函数的调用" << endl;
	}
};
void Class_Jx002()
{
	PersonJx001 p1;
	cout << "this is a pause.." << endl;
}
//构造函数的分类
void Class_Jx003()
{

}
