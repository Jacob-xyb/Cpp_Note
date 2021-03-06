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
//语法·
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


/*-- 继承 --*/
//继承的基本语法
/*	继承实现页面 */
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登陆、注册...(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++...（公共列表）" << endl;
	}
};
class WebJava : public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};
class WebPython : public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};
class WebCpp : public BasePage
{
public:
	void content()
	{
		cout << "Cpp学科视频" << endl;
	}
};
void Class_successor()
{
	cout << "这是Java页面" << endl;
	WebJava webjava;
	webjava.header();
	webjava.footer();
	webjava.left();
	webjava.content();
	cout << "\n这是Python页面" << endl;
	WebPython webpy;
	webpy.header();
	webpy.footer();
	webpy.left();
	webpy.content();
	cout << "\n这是Cpp页面" << endl;
	WebCpp webcpp;
	webcpp.header();
	webcpp.footer();
	webcpp.left();
	webcpp.content();
}
//继承中的对象模型
class BaseTest
{
public:
	int m_public_A;
protected:
	int m_protected_B;
private:
	int m_private_C;	//私有属性只是被隐藏了，但还是会继承下去
};
class SonTest : public BaseTest
{
public:
	int m_D;
};
void Class_successor001()
{
	cout << sizeof(SonTest) << endl;		//16
}
//继承中构造和析构顺序
class BaseTest001
{
public:
	BaseTest001();
	~BaseTest001();
public:
	int m_public_A;
protected:
	int m_protected_B;
private:
	int m_private_C;	//私有属性只是被隐藏了，但还是会继承下去
};
BaseTest001::BaseTest001()
{
	cout << "父类的构造函数调用" << endl;
}
BaseTest001::~BaseTest001()
{
	cout << "父类的析构函数调用" << endl;
}
class SonTest001 : public BaseTest001
{
public:
	SonTest001();
	~SonTest001();
public:
	int m_D;
};
SonTest001::SonTest001()
{
	cout << "子类的构造函数调用" << endl;
}
SonTest001::~SonTest001()
{
	cout << "子类的析构函数调用" << endl;
}
void Class_successor002()
{
	SonTest001 son;
	//父构造 子构造 子析构 父析构
}
//继承同名成员处理方式
class BaseTest002
{
public:
	BaseTest002();
public:
	int getA();
public:
	void func();
	void func(int a);
private:
	int mA;
};
BaseTest002::BaseTest002() { mA = 30; }
int BaseTest002::getA() { return mA; }
void BaseTest002::func()
{
	cout << "父类同名成员函数的调用" << endl;
}
void BaseTest002::func(int a)
{
	cout << "父类有参的同名成员函数调用" << endl;
}
class SonTest002 : public BaseTest002
{
public:
	SonTest002();
public:
	int getA();
public:
	void func();
private:
	int mA;
};
SonTest002::SonTest002() { mA = 18; }
int SonTest002::getA() { return mA; }
void SonTest002::func()
{
	cout << "子类同名成员函数的调用" << endl;
}
void Class_successor003()
{
	SonTest002 son;
	cout << son.getA() << endl;						//子类同名成员直接访问即可
	cout << son.BaseTest002::getA() << endl;		//父类同名成员加后缀即可访问

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类的所有同名成员函数
	son.func();					//cout:子类同名成员函数的调用
	//son.func(1);				//error C2660: “SonTest002::func”: 函数不接受 1 个参数
	son.BaseTest002::func(1);	//cout:父类有参的同名成员函数调用
}
//菱形继承 or 钻石继承
class Animal
{
public:
	int mAge;
};
class Sheep :public Animal{};
class Tuo :public Animal{};
class SheepTuo :public Sheep, public Tuo{};
void Class_successor004()
{
	SheepTuo st;
	st.Sheep::mAge = 18;
	st.Tuo::mAge = 28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::mAge = " << st.Sheep::mAge << endl;
	cout << "st.Tuo::mAge = " << st.Tuo::mAge << endl;
	//这份数据我们知道，只需要有一份即可，菱形继承导致数据有两份，资源浪费
}
//	虚继承 解决菱形继承导致的资源浪费
class Animal001
{
public:
	int mAge;
};
//	Animal类被称为虚基类
class Sheep001 :virtual public Animal001{};
class Tuo001 :virtual public Animal001{};
class SheepTuo001 :public Sheep001, public Tuo001{};
void Class_successor005()
{
	SheepTuo001 st;
	st.Sheep001::mAge = 18;
	st.Tuo001::mAge = 28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::mAge = " << st.Sheep001::mAge << endl;
	cout << "st.Tuo::mAge = " << st.Tuo001::mAge << endl;
	//这份数据我们知道，只需要有一份即可，菱形继承导致数据有两份，资源浪费
	
	//虚继承后的同名数据就为同一份数据
	cout << "st.mAge = " << st.mAge << endl;
	//此时两个父类的内容都是(vbptr -- 虚基类指针)
}


/*-- 多态 --*/
//多态基本语法和实现
class Animal002
{
public:
	//speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
	virtual void speak();
};
void Animal002::speak()
{
	cout << "动物在说话" << endl;
}
class Cat002 : public Animal002
{
public:
	void speak();

};
void Cat002::speak()
{
	//重写 函数返回值类型 函数名 参数列表 完全相同
	cout << "小猫在说话" << endl;
}
//	地址早绑定 在编译阶段确定函数地址
//	如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void doSpeak(Animal002& animal)
{
	animal.speak();
}
//	动态多态满足条件
//	1. 有继承关系
//	2. 子类要重写父类中的虚函数
//	动态多态使用
//	父类指针或引用指向子类对象
void Class_Polymorphism()
{
	Cat002 cat;
	//C++默认允许父与子类间类型转换
	doSpeak(cat);
}
//多态底层原理剖析
void Class_Polymorphism001()
{
	cout << "sizeof(Animal) = " << sizeof(Animal002) << endl;	
	//无virtual 1
	//带virtual 8
}
/*多态案例一：计算器类*/
//	普通写法
class Calculator
{
public:
	int getResult(string oper);
	
	int num1;
	int num2;
};
int Calculator::getResult(string oper)
{
	if (oper == "+")
	{
		return num1 + num2;
	}
	else if (oper == "-")
	{
		return num1 - num2;
	}
	else if (oper == "*")
	{
		return num1 * num2;
	}
	//如果想扩展新的功能，需要修改源码
	//在真实开发中 提倡 开闭原则
	//开闭原则：对扩展进行开放，对修改进行关闭
}
void Class_Polymorphism002()
{
	Calculator c;
	c.num1 = 20;
	c.num2 = 10;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
}
//	多态写法
/*多态好处
* 1.组织结构非常清晰
* 2.可读性强
* 3.对于前期和后期扩展以及维护性高
*/
//		实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult() { return 0; }
	int num1;
	int num2;
};
//		加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};
//		减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};
class MulCalculator :public AbstractCalculator
{
public:
	int getResult() { return num1 * num2; }
};
void Class_Polymorphism003()
{
	//多态使用条件
	//父类指针或引用指向子类对象
	AbstractCalculator* abc = new AddCalculator;
	abc->num1 = 20;
	abc->num2 = 10;
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	//用完后手动销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->num1 = 20;
	abc->num2 = 10;
	cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
	//用完后手动销毁
	delete abc;
}
//纯虚函数和抽象类
class Abstract
{
	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象类
	//抽象类特点：
	//1.无法实例化对象
	//2.抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};
//多态案例二：制作饮品
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() { cout << "煮矿泉水" << endl; }
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
class Coffee :public AbstractDrinking
{	
public:
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};
void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}
void Class_Polymorphism004()
{
	doWork(new Coffee);
	cout << "----" << endl;
	doWork(new Tea);
}
//虚析构和纯虚析构
class Animal003
{
public:
	Animal003(){ cout << "Animal的构造函数调用" << endl; }
	virtual ~Animal003(){ cout << "Animal的析构函数调用" << endl; }
	//纯虚函数
	virtual void speak() = 0;
};
class Cat003 :public Animal003
{
public:
	Cat003(string name)
	{
		cout << "Cat的构造函数调用" << endl;
		this->name = new string(name);
	}
	~Cat003()
	{
		if (name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete name;
			name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *name << "小猫在说话" << endl;
	}
	string* name;	//创建在堆区
};
void Class_Polymorphism005()
{
	Animal003* animal = new Cat003("Tom");
	animal->speak();
	//父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
	//因此要采用虚析构来解决 父类指针释放子类对象时不干净的问题
	delete animal;
}
//多态案例三：电脑组装
class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;
};
class Memory
{
public:
	//抽象的存储函数
	virtual void storage() = 0;
};
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
	//提供工作的函数
	void work()
	{
		//让零件工作起来
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
private:
	//构造函数中传入三个零件指针
	CPU* m_cpu;		//CPU的零件指针
	VideoCard* m_vc;	//显卡零件指针
	Memory* m_mem;	//内存条零件指针

};
class IntelCpu :public CPU
{
public:
	//Intel厂商提供
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了." << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	//Intel厂商提供
	virtual void display()
	{
		cout << "Intel的VideoCard开始显示了." << endl;
	}
};
class IntelMemory :public Memory
{
public:
	//Intel厂商提供
	virtual void storage()
	{
		cout << "Intel的Memory开始存储了." << endl;
	}
};
class LenovoCpu :public CPU
{
public:
	//Lenovo厂商提供
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了." << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	//Lenovo厂商提供
	virtual void display()
	{
		cout << "Lenovo的VideoCard开始显示了." << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	//Lenovo厂商提供
	virtual void storage()
	{
		cout << "Lenovo的Memory开始存储了." << endl;
	}
};
void Class_Polymorphism006()
{
	//第一台电脑零件
	CPU* intelCpu = new IntelCpu;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	//第二台电脑零件
	CPU* lenovoCpu = new LenovoCpu;
	VideoCard* lenovoCard = new LenovoVideoCard;
	Memory* lenovoMem = new LenovoMemory;

	//创建第二台电脑
	Computer* computer2 = new Computer(lenovoCpu, lenovoCard, lenovoMem);
	computer2->work();
	delete computer2;
}
