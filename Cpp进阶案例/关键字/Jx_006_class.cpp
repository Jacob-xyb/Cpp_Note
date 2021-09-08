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
//深浅拷贝
class PersonJx003
{
public:
	//无参构造函数
	PersonJx003()
	{
		cout << "无参构造函数的调用" << endl;
	}
	//有参构造函数
	PersonJx003(int age, int height)
	{
		this->mAge = age;
		this->mHeight = new int(height);
		cout << "有参构造函数的调用" << endl;
	}
	//用深拷贝重写拷贝构造函数	//默认拷贝构造函数是浅拷贝
	PersonJx003(const PersonJx003& p)
	{
		this->mAge = p.mAge;
		this->mHeight = new int(*p.mHeight);
		cout << "拷贝构造函数的调用" << endl;
	}
	~PersonJx003()
	{
		if (mHeight)
		{
			delete mHeight;
			mHeight = NULL;
		}
		cout << "析构函数的调用" << endl;
	}
public:
	int mAge;
	int *mHeight;	//将此数据创建到堆区
};
void Class_Jx004()
{
	PersonJx003 p1(18, 160);	//有参构造
	PersonJx003 p2(p1);			//拷贝构造函数，此时属于浅拷贝函数
	cout << "p1的年龄" << p1.mAge << endl;
}
//初始化列表
class PersonJx004
{
public:
	//传统初始化操作
	/*PersonJx004(int a, int b, int c)
	{
		mA = a;
		mB = b;
		mC = c;
	}*/

	//初始化列表创建无参构造函数
	PersonJx004():mA(10),mB(20),mC(30){}

	//有参构造函数也可以用初始化列表改写
	PersonJx004(int a, int b, int c):mA(a), mB(b), mC(c) {}
public:
	int mA;
	int mB;
	int mC;
};
void Class_Jx005()
{
	PersonJx004 p1;
	cout << p1.mA << "\t" << p1.mB << "\t" << p1.mC << endl;
	PersonJx004 p2(11, 22, 33);
	cout << p2.mA << "\t" << p2.mB << "\t" << p2.mC << endl;
}
//静态成员变量和静态成员函数
class PersonJx005
{
public:
	//静态成员函数
	static void func()
	{
		cout << "静态成员函数的调用" << endl;
		mA = 100;		//静态成员函数可以访问静态成员变量
		//mB = 200;		//静态成员函数不能访问非静态成员变量

	}
	//静态成员变量
	static int mA;
	//非静态成员变量
	int mB;
private:
	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "私有的静态成员函数的调用" << endl;
	}
};
//	初始化静态成员变量
int PersonJx005::mA = 0;
void Class_Jx006()
{
	//1.通过对象访问
	PersonJx005 p1;
	p1.func();

	//2.通过类名访问
	PersonJx005::func();
}
//this指针返回本身	//链式编程
class PersonJx006
{
public:
	PersonJx006() {}	//如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
	PersonJx006(int age)
	{
		this->mAge = age;
	}
	/*无返回值*/
	//void PersonAddAge(PersonJx006& p)
	//{
	//	this->mAge += p.mAge;
	//}
	/*返回对象的引用*/
	PersonJx006& PersonAddAge(PersonJx006& p)
	{
		this->mAge += p.mAge;
		//this指向实例化对象，而*this就是解引用，也就是实例化对象本体
		return *this;
	}
	/*返回对象的拷贝*/
	//PersonJx006 PersonAddAge(PersonJx006& p)
	//	此时返回的时候会创建一个新的对象，注意区分

	int mAge;
};
void Class_Jx007()
{
	PersonJx006 p1(10);
	PersonJx006 p2(18);
	p1.PersonAddAge(p2);	//这样当然是可以的
	cout << p1.mAge << endl;
	//如果想采用链式编程，调用的函数就得返回对象本身
	p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
	cout << p1.mAge << endl;
}