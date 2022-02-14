#include "../Jx_进阶案例.h"

/*-- preface --*/
/*
数据类型存在意义：给变量分配合适的内存空间
*/

/*宏常量*/
// 宏常量不可以修改
#define WEEKDAY 7

/*静态对象*/
class Dog
{
public:
    Dog(string name)
    {
        m_name = name;
        count ++;
    }

    static void func()
    {   
        count = 0;
        // 静态函数 只能调用 静态变量
        // m_name = "Sunshine";
        cout << "static void func 调用" << endl;
    }
    static int count;
    void func_test();
    int m_test = 10;
private:
    string m_name;
};
//初始化类静态成员
int Dog::count = 0;
void static_object_001()
{
    Dog dog01("Sherry");
    Dog dog02("Henry");
    Dog::func();
    cout << "现在有 " << Dog::count << " 只狗：" << endl;
}
void Dog::func_test()
{
    std::cout << m_test << std::endl;
    //std::cout << ::m_test << std::endl;     // 类中 :: 并不能调用类中实例
    std::cout << Dog::m_test << std::endl;     // 类中 :: 必须带类名才能调用类中实例
}


/*变量类型*/
//全局区   //全局变量、静态变量、常量  //程序运行前
int global_a = 1;           //全局变量
int global_b = 1;           //全局变量
const int CstG_a = 1;       //const修饰的全局变量 - 全局常量
const int CstG_b = 1;       //const修饰的全局变量 - 全局常量
void ParamType_001()
{
    //局部变量
    int a = 1;
    int b = 1;

    //静态变量
    static int static_a = 1;
    static int static_b = 1;

    //常量
    //  字符串常量
    cout << "字符串常量的地址：\t\t" << (int)&"hello" << endl;
    //  const修饰的变量
    //      const修饰的全局变量 - 全局常量
    //      const修饰的局部变量 - 局部常量
    const int Cst_a = 1;
    const int Cst_b = 1;

    //输出
    cout << "全局变量 global_a 地址：\t" << (int)&global_a << endl;
    cout << "全局变量 global_b 地址：\t" << (int)&global_b << endl;
    cout << "局部变量 a 地址：\t\t" << (int)&a << endl;
    cout << "局部变量 b 地址：\t\t" << (int)&b << endl;
    cout << "静态变量 static_a 地址：\t" << (int)&static_a << endl;
    cout << "静态变量 static_b 地址：\t" << (int)&static_b << endl;
    cout << "全局常量 CstG_a 地址：\t\t" << (int)&CstG_a << endl;
    cout << "全局常量 CstG_b 地址：\t\t" << (int)&CstG_b << endl;
    cout << "局部常量 Cst_a 地址：\t\t" << (int)&Cst_a << endl;
    cout << "局部常量 Cst_b 地址：\t\t" << (int)&Cst_b << endl;

    //总结:局部不在全局区，其余(全局变量、静态变量、常量)都在全局区
}
void ParamType_002()
{
    // 如果函数类同时存在全局变量和局部变量，可以用 :: 调用全局变量
    int global_a = 10;
    std::cout << global_a << std::endl;
    std::cout << ::global_a << std::endl;
}


//栈区    //存放函数的参数值，局部变量等
int* func_Stack_001()
{
    int a = 10; //局部变量  //存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;
}
void Stack_001()
{
    /*注意事项*/
    //  不要返回局部变量的地址
    int* p = func_Stack_001();
    cout << *p << endl;     //能够正常输出10是因为编译器做了保留
}
//堆区    //new创建
int* func_Heap_001()
{
    //利用new关键字 可以将数据开辟到堆区
    //  指针也是局部变量，存放在栈区
    int* p = new int(10);   //new 返回的是该类型的指针
    int* arr = new int[10]; //10代表数组有10个元素，返回数组的首地址
    delete[] arr;           //手动释放数组
    return p;
}
void Heap_001()
{
    //在堆区开辟数据
    int* p = func_Heap_001();   //程序执行完自动释放
    delete p;                   //也可以手动释放
    //cout << *p << endl;       //error:读取访问权限冲突。
}