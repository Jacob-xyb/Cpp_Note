#include "Jx_test.h"
//#include <vector>
//#include <algorithm>

// vector容器内存放内置数据类型
void vector_001()
{
    //// 创建了一个vector容器，数组
    vector<int> v;

    //// 向容器中插入数据
    //// push_back()      // 向 vector 内尾插数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 通过迭代器访问容器中的数据
    // vector<int>::iterator  vector 作用域下的 迭代器
    vector<int>::iterator itBegin = v.begin();      // v.begin() 起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();      // v.end(); 结束迭代器，指向容器中最后一个元素的下一个位置
}

// vector 的 第一种遍历方式
void vector_002()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    // 第一种
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
}

// vector 的 第二种遍历方式
void vector_003()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << endl;
    }
}


void myPrint(int val)
{   
    cout << val << endl;
}

// vector 的 第三种遍历方式
void vector_004()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 第三种 利用STL提供遍历算法 <algorithm>
    for_each(v.begin(), v.end(), myPrint);      // 运用了回调技术
}

//vector 容器中存放自定义数据类型
//  存放类
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void vector_005()
{
    vector<Person> v;
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // *it 解引用后是一个 Person 数据类型；就是vector<>内的内容
        cout << "姓名：" << (*it).m_Name << endl;
        cout << "年龄：" << (*it).m_Age << endl;
        // 当 it 是指针时，可以直接用指针访问类属性
        cout << "姓名：" << it->m_Name << endl;
        cout << "年龄：" << it->m_Age << endl;
    }
}

//  存放指针
void vector_006()
{
    vector<Person*> v;      // Type* 就是指针的意思
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);
    v.push_back(&p1);       // &对象  取实例化对象地址
    v.push_back(&p2);
    v.push_back(&p3);
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // *it 解引用后是一个 Person* 数据类型；就是vector<>内的内容
        cout << "姓名：" << (*(*it)).m_Name << endl;
        cout << "年龄：" << (*(*it)).m_Age << endl;
        // 两次解引用也可以这样写
        cout << "姓名：" << (**it).m_Name << endl;
        cout << "年龄：" << (**it).m_Age << endl;
        // 当 *it 是指针时，可以直接用指针访问类属性
        cout << "姓名：" << (*it)->m_Name << endl;
        cout << "年龄：" << (*it)->m_Age << endl;
    }
}


// 容器嵌套容器
void vector_007()
{
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 通过大容器，遍历所有数据
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << "\t";
        }
        cout << endl;
    }

}