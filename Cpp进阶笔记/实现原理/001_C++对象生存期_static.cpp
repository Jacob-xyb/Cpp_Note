#include <iostream>
using namespace std;

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

// 初始化类静态成员
int Dog::count = 0;

int main()
{
    Dog dog01("Sherry");
    Dog dog02("Henry");
    Dog::func();
    cout << "现在有 " << Dog::count << " 只狗：" << endl;
    
    system("pause");
    return 0;
}