#include "../Jx_进阶案例.h"

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