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
//空指针访问成员函数
class PersonJx007
{
public:
	void showPersonClass()
	{
		cout << "This is Person class!" << endl;
	}
	void showPersonAge()
	{
		//添加一个判断
		if (this == NULL)
		{
			return;
		}
		cout << "age = " << m_Age << endl;
	}
	int m_Age;
};
void Class_Jx008()
{
	PersonJx007* p = NULL;		//创建一个类的空指针
	p->showPersonClass();		//可以正常调用
	//p->showPersonAge();		//引发了异常: 读取访问权限冲突。
								//**this** 是 nullptr。
	//报错的原因是空指针无法访问属性，因为 this指针为空。
	//在类中添加判断
	p->showPersonAge();			//这样就不会报错了

	//试试空对象
	PersonJx007 p1;
	//空对象均可以正常调用
	p1.showPersonClass();
	p1.showPersonAge();
}
//类中的常函数和常对象
class PersonJx008
{
public:
	//在成员函数后面加 const，修饰的是this指针，
	//	this指针的本质 是指针常量 指针指向不可以修改	
	void showPerson() const
	{
		//此时指针指向的值也不可以修改
		//this->m_A = 100;

		//mutable 变量在常函数中也可以修改
		m_B = 20;
		cout << "常函数的调用" << endl;
	}

	void func(){}

	int m_A;
	//如果想要在常函数中也可以修改，在变量前加 mutable
	mutable int m_B;
};
void Class_Jx009()
{
	const PersonJx008 p;	//在对象前加const，变为常对象
	//p.m_A = 100;			//常对象不能修改普通的成员变量
	p.m_B = 18;				//但是常对象可以修改 mutable 成员变量
	p.showPerson();			//常对象只能调用常函数
	cout << p.m_B << endl;
	//p.func()				//error:对象含有不兼容的类型限定符	
}


/*友元*/
//全局函数做友元
class BuildJx001;
class ClassGoodGay001;
class BuildJx001
{
	//GoodGay全局函数用friend声明	//甚至不用特意写在public作用域下
	friend void func_GoodGay(BuildJx001* build);
	//GoodGay类也是同样的方式声明
	friend class ClassGoodGay;
	//类的成员函数单独声明	//TODO：声明前后顺序并没有讲清，单纯这样写还是会报错
	//friend void ClassGoodGay001::visit();
public:
	BuildJx001();

public:
	string m_LivingRoom;		//客厅
private:
	string m_BedRoom;			//卧室
};
BuildJx001::BuildJx001()
{
	m_LivingRoom = "客厅";
	m_BedRoom = "卧室";
}
//	全局函数
void func_GoodGay(BuildJx001* build)
{
	cout << "全局函数正在访问： " << build->m_LivingRoom << endl;
	//cout << "全局函数正在访问： " << build->m_BedRoom << endl;	//私有属性不可访问

	//在类中用friend声明全局函数后即可访问类中私有变量
	cout << "全局函数正在访问： " << build->m_BedRoom << endl;
}
void Class_Jx010()
{
	BuildJx001 build;
	func_GoodGay(&build);
}
//类做友元
class ClassGoodGay
{
public:
	ClassGoodGay();
public:

	void visit();	//访问 BuildJx001 类中的属性

	BuildJx001* build;
};
ClassGoodGay::ClassGoodGay()
{
	//创建一个对象
	build = new BuildJx001;		//new对象返回指针
}
void ClassGoodGay::visit()
{
	cout << "好基友类正在访问： " << build->m_LivingRoom << endl;
	cout << "好基友类正在访问： " << build->m_BedRoom << endl;
}
//	test
void Class_Jx011()
{
	ClassGoodGay gp;		//创建一个类
	gp.visit();
}
//成员函数做友元
class ClassGoodGay001
{
public:
	ClassGoodGay001();
	void visit();		//	让visit函数可以访问私有成员
	void visit2();		//	让visit2函数不可以访问私有成员

private:
	BuildJx001* build;

};
ClassGoodGay001::ClassGoodGay001()
{  
	build = new BuildJx001;
}
void ClassGoodGay001::visit()
{
	cout << "好基友类正在访问： " << build->m_LivingRoom << endl;
	//cout << "好基友类正在访问： " << build->m_BedRoom << endl;
}
void ClassGoodGay001::visit2()
{
	cout << "好基友类正在访问： " << build->m_LivingRoom << endl;
	//cout << "好基友类正在访问： " << build->m_BedRoom << endl;	//visit2不可访问
}
//	test
//void Class_Jx012()
//{
//	ClassGoodGay001 gp;
//	gp.visit();
//}


/*运算符重载*/
//加号运算符重载
class PersonJx009
{
public:
	PersonJx009& operator+(PersonJx009& p)
	{
		PersonJx009 temp;
		temp.mA = p.mA + this->mA;
		temp.mB = p.mB + this->mB;
		return temp;
	}
public:
	int mA;
	int mB;
private:
};
//	成员函数重载
void Class_Operator001()
{
	PersonJx009 p1;
	p1.mA = 10;
	p1.mB = 100;
	PersonJx009 p2;
	p2.mA = 20;
	p2.mB = 200;
	PersonJx009 p3;
	p3 = p1 + p2;		//重载运算符+
	cout << p3.mA << " " << p3.mB << endl;
}
//	全局函数重载
class PersonJx010
{
public:
	int mA;
	int mB;
private:
};
PersonJx010& operator+(PersonJx010& p1, PersonJx010& p2)
{
	PersonJx010 temp;
	temp.mA = p1.mA + p2.mA;
	temp.mB = p1.mB + p2.mB;
	return temp;
}
void Class_Operator002()
{
	PersonJx010 p1;
	p1.mA = 10;
	p1.mB = 100;
	PersonJx010 p2;
	p2.mA = 20;
	p2.mB = 200;
	PersonJx010 p3;
	p3 = p1 + p2;		//重载运算符+
	cout << p3.mA << " " << p3.mB << endl;
}
//左移运算符重载
class PersonJx011
{
	//利用全局函数做友元访问私有属性
	friend ostream& operator<<(ostream& cout, PersonJx011& p);
public:
	PersonJx011(int a, int b);

	//通常不会利用成员函数重载 左移运算符， 因为无法实现 cout 在左侧
	//void operator<< (PersonJx011& p);
private:
	int mA;
	int mB;
};
PersonJx011::PersonJx011(int a, int b)
{
	this->mA = a;
	this->mB = b;
}
//	只能利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, PersonJx011& p)
{
	cout << p.mA << " " << p.mB;
	//还需注意链式编程思想
	return cout;
}
void Class_Operator003()
{
	PersonJx011 p(10, 20);
	cout << p << endl;
}
//递增运算符重载
class MyInteger
{
public:
	MyInteger();
	int getNum();

	//重载前置++运算符	//返回值的话重复调用就会出现问题
	MyInteger& operator++()
	{
		mNum++;
		return *this;
	}
	//重载后置++运算符	//int代表占位参数，可以用于区分前置和后置递增，只认int！
	MyInteger operator++(int)
	{
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		mNum++;
		//返回的是局部对象，因此不能返回引用
		return temp;
	}
private:
	int mNum;
};
MyInteger::MyInteger()
{
	this->mNum = 0;
}
int MyInteger::getNum()
{
	return this->mNum;
}
//	重载左移运算符打印输出
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.getNum();
	return cout;
}
void Class_Operator004()
{
	MyInteger myint;
	cout << ++myint << endl;
	MyInteger myint2;
	cout << myint2++ << endl;
}
//赋值运算符重载
class PersonJx012
{
public:
	PersonJx012(int age);
	~PersonJx012();

	//浅拷贝会重复释放堆区内存
	PersonJx012& operator=(PersonJx012& p);

	int* getAge();
private:
	int* mAge;
};
PersonJx012::PersonJx012(int age)
{
	mAge = new int(age);
}
PersonJx012::~PersonJx012()
{
	if (mAge!=NULL)
	{
		delete mAge;
		mAge = NULL;
	}
}
//	还要考虑链式编程
//void PersonJx012::operator=(PersonJx012& p)
PersonJx012& PersonJx012::operator=(PersonJx012& p)
{
	/*编译器提供的浅拷贝*/
	//mAge = p.mAge;

	/*为了避免堆区重复释放，应该对赋值运算操作符进行重载*/
	//先判断是否有属性在堆区，如果有先释放干净
	if (mAge!=NULL)
	{
		delete mAge;
		mAge = NULL;
	}
	//然后进行深拷贝
	this->mAge = new int(*p.getAge());
	return *this;
}
int* PersonJx012::getAge() { return mAge; }
void Class_Operator005()
{
	PersonJx012 p1(18);
	PersonJx012 p2(20);

	p2 = p1;	//赋值操作

	cout << *p1.getAge() << endl;
	cout << *p2.getAge() << endl;
}
//关系运算符重载
class PersonJx013
{
public:
	PersonJx013(string name, int age);

	bool operator==(PersonJx013& p);
	bool operator!=(PersonJx013& p);

	string getName() { return mName; }
	int getAge() { return mAge; }
private:
	string mName;
	int mAge;
};
PersonJx013::PersonJx013(string name, int age)
{
	mName = name;
	mAge = age;
}
bool PersonJx013::operator==(PersonJx013& p)
{
	if (mName == p.getName() && mAge == p.getAge())
	{
		return true;
	}
	return false;
}
bool PersonJx013::operator!=(PersonJx013& p)
{
	if (mName == p.getName() && mAge == p.getAge())
	{
		return false;
	}
	return true;
}
void Class_Operator006()
{
	PersonJx013 p1("zhangsan", 18);
	PersonJx013 p2("zhangsan", 18);
	if (p1==p2)
	{
		cout << "p1和p2是相等的" << endl;
	}
	else { cout << "p1和p2是不相等的" << endl; }
}
//函数调用运算符重载
class MyPrint
{
public:
	//由于使用起来很像函数的调用，因此被称为仿函数
	void operator()(string test);

private:

};
void MyPrint::operator()(string test)
{
	cout << test << endl;
}
void Class_Operator007()
{
	MyPrint p;
	p("hello world");

	//匿名对象写法
	MyPrint()("匿名对象方式调用");
}