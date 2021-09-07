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
class PersonJx002
{
public:
	//无参构造函数
	PersonJx002()
	{
		cout << "无参构造函数的调用" << endl;
	}
	PersonJx002(int a)
	{
		this->mAge = a;
		cout << "有参构造函数的调用" << endl;
	}

	//拷贝构造函数
	PersonJx002(const PersonJx002& p)
	{
		mAge = p.mAge;
		cout << "拷贝构造函数的调用" << endl;
	}
	
	//析构函数
	~PersonJx002()
	{
		cout << "年龄为 " << mAge << " 的对象被析构" << endl;
	}

	int getAge() { return mAge; }
private:
	int mAge;
};
void Class_Jx003()
{
	//1.括号法
	PersonJx002 p1;		//调用无参构造函数
	cout << p1.getAge() << endl;
	PersonJx002 p2(10);	//调用有参构造函数
	cout << p2.getAge() << endl;

	PersonJx002 p3(p2);	//调用拷贝构造函数
	cout << p3.getAge() << endl;

	//2.显式法
	PersonJx002 p4;		//PersonJx002 p4();	写法错误，会认为是一个函数声明.
	PersonJx002 p5 = PersonJx002(20);
	PersonJx002 p6 = PersonJx002(p5);

	//注意事项
	PersonJx002(30);		// 匿名对象	特点：当前行执行结束后，系统会立即回收掉匿名对象
	cout << "aaa" << endl;		// 测试发现会在 'aaa' 之前进行构造和析构
	// 注意：不要利用拷贝构造函数初始化匿名对象
	// 因为编译器会认为 PersonJx002(p6) 是 PersonJx002 p6；对象重定义
	// PersonJx002(p6);

	//3.隐式转换法
	PersonJx002 p7 = 40;	//有参构造
	PersonJx002 p8 = p7;	//拷贝构造
}
