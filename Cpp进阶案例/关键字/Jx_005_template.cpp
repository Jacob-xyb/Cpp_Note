#include "../Jx_进阶案例.h"

/*函数模板*/
//通用数据类型
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void Template_Type_001()
{
	/*两种方式使用模板函数*/
	int a = 10;
	int b = 80;
	//1.自动类型推导
	mySwap(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	//2.显式指定类型
	mySwap<int>(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}
//函数模板注意事项
template<typename T>
void Template_Func_002()
{
	cout << "func 调用" << endl;
}
void Template_Type_002()
{
	//Template_Func_002();		//error:未能为“T”推导 模板 参数
	Template_Func_002<int>();	//但是显示指定类型就可以使用
}
//函数模板案例
template<typename T>
void mySort_001(T arr[])
{
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		int minIdx = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			mySwap(arr[i], arr[minIdx]);
		}
	}
}
void Template_Eg_001()
{
	char arr1[] = "dabiadao";
	mySort_001(arr1);
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
}
//普通函数与函数模板
int myAdd_001(int a, int b)
{
	return a + b;
}
template<typename T>
int myAdd_002(T a, T b)
{
	return a + b;
}
//	普通函数可以发生隐式类型转换
void Template_Type_003()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a+b：" << myAdd_001(a, b) << endl;	//30
	/*普通函数*/
	//隐式类型转换，a -- ASCII(97);c -- ASCII(99)
	cout << "a+c：" << myAdd_001(a, c) << endl;	//109
	/*模板函数*/
	//自动类型推导
	//cout << myAdd_002(a, c) << endl;	//error:参数不匹配
	//显式指定类型
	cout << myAdd_002<int>(a, c) << endl;		//109
}
//调用规则
void myFuncPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}
template<typename T>
void myFuncPrint(T a, T b)
{
	cout << "调用的函数模板" << endl;
}
template<typename T>
void myFuncPrint(T a, T b, T c)
{
	cout << "重载函数模板" << endl;
}
void myFuncPrint_test001()
{
	int a = 0, b = 0;
	//1.优先调用普通函数
	myFuncPrint(a, b);
	//	如果普通函数只有声明没有实现，也不会去执行函数模板，而是依旧优先执行普通函数然后报错，error：1个无法解析的外部命令
	//2.通过空模板参数列表，强制调用函数模板
	myFuncPrint<>(a, b);
	//3.函数模板可以发生函数重载
	myFuncPrint(a, b, 100);
	//4.如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myFuncPrint(c1, c2);	//推导优于隐式转换，优先调用函数模板
}
//模板局限性	//模板函数重载
struct PersonTest001
{
	string m_Name;
	int m_Age;
};
template<typename T>
bool myCompare001(T& a, T& b)
{
	return (a == b);
}
// 利用具体化Person的版本实现代码，具体化会被优先调用
template<> 
bool myCompare001(PersonTest001& p1, PersonTest001& p2)
{
	return (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age);
}
void Template_Type_004()
{
	//正常调用函数模板
	int a = 10, b = 20;
	cout << myCompare001(a, b) << endl;
	//具体化函数模板
	PersonTest001 p1 = { "Tom", 10 };
	PersonTest001 p2 = { "Tom", 10 };
	cout << myCompare001(p1, p2) << endl;
}


/*类模板*/
//类模板语法
template<class NameT, class AgeT>
class PersonClass
{
public:
	PersonClass(NameT name, AgeT age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	NameT m_Name;
	AgeT m_Age;
};
void ClassTemplate_001()
{
	//类模板必须要使用模板参数列表
	PersonClass<string, int> p1("张三", 18);
}
//类模板与函数模板的区别
void ClassTemplate_002()
{
	//1.只能用显式指定类型
	PersonClass<string, int> p1("张三", 18);
	//
}