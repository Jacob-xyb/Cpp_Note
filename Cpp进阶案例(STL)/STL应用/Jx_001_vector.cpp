                  #include "Jx_test.h"
//#include <vector>
//#include <algorithm>


// 写一个打印vector<int>的函数方便调用
void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


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


// vector 构造函数
/*- `vector<T> v;`		// 采用模板实现类实现，默认构造函数
- `vector(v.begin(),v.end());`		// 将v[ begin(),end() ) 区间中的元素拷贝给本身
- `vector(n, elem);`				// 构造函数将n各elem拷贝给本身
- `vector(const vector& vec);`		// 拷贝构造函数*/
void vector_008()
{
    // 默认构造函数，无参构造
    vector<int> v1;     
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);        // 对 v1 添加数据
    }
    printVector(v1);        // 自写一个 print 函数进行输出

    // 区间方式构造
    vector<int> v2(v1.begin(), v1.end());       
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}


// vector 赋值操作
/*- `vector& operator=(const vector& vec);`		// 重载等号操作符
- `assign(beg,end);`		// [beg,end) 区间拷贝赋值
- `assign(n,elem);`		// n个elem拷贝赋值*/
void vector_009()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    // = 直接赋值
    cout << "= 直接赋值" << endl;
    vector<int> v2 = v1;
    printVector(v2);

    // 区间拷贝复制
    cout << "区间拷贝复制" << endl;
    v2.assign(v1.begin(), v1.end());
    printVector(v2);

    // n个elem拷贝赋值
    cout << "n个elem拷贝赋值" << endl;
    v2.assign(10, 10);
    printVector(v2);
}


// vector 容量和大小
/*- `empty();`			// 判断容器是否为空
- `capacity();`			// 容器的容量
- `size();`				// 返回容器中元素的个数
- `resize(int num);`	// 重新定义容器的长度为num,
  // 如果容器变长，则以默认值填充新位置。
  // 如果容器变短，则末尾超出容器长度的元素被删除。
- `resize(int num, elem);`	// 默认值变为 elem*/
void vector_010()
{
    vector<int> v1;
    cout << "空容器调用empty() 返回值为：" << v1.empty() << endl;
    cout << "空容器的容量为：" << v1.capacity() << endl;
    cout << "空容器中元素的个数：" << v1.size() << endl;

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "查看一下赋值后容器的数据" << endl;
    printVector(v1);

    // 可以发现，容器的容量比容器的个数要大，是因为vector会自动多分配空间
    cout << "此时容器调用empty() 返回值为：" << v1.empty() << endl;
    cout << "容器的容量为：" << v1.capacity() << endl;
    cout << "容器中元素的个数：" << v1.size() << endl;
    // 容器中元素个数为10个时，容器容量为13

    // 扩充一下容器的长度
    v1.resize(12);
    cout << endl << "元素个数扩充到12时：" << endl;
    cout << "查看一下扩充后容器的数据" << endl;
    printVector(v1);
    cout << "此时容器容量为：" << v1.capacity() << endl;
    cout << "此时容器中元素的个数为：" << v1.size() << endl;
    // 此时容器的容量还是13，说明元素个数不大于容器容量时，容器容量不会增加
    //      那么，会缩小吗？
    cout << endl << "元素个数缩小到6，容器容量会有变化吗？" << endl;
    v1.resize(6);
    cout << "查看一下缩减后容器的数据" << endl;
    printVector(v1);
    cout << "此时容器容量为：" << v1.capacity() << endl;
    cout << "此时容器中元素的个数为：" << v1.size() << endl;
    //      嗯..个数缩减时容量也不会发生变化，
    //      可以理解为，已经开辟了这么大的空间了，够用就不会再改变了
    cout << endl << "验证一下`容量==个数`时的情形" << endl;
    v1.resize(v1.capacity());
    cout << "此时容器容量为：" << v1.capacity() << endl;
    cout << "此时容器中元素的个数为：" << v1.size() << endl;
    //      验证结果：空间够用就不会再改变
    cout << endl << "验证一下`容量==个数+1`时的情形" << endl;
    v1.resize(v1.capacity()+1);
    cout << "此时容器容量为：" << v1.capacity() << endl;
    cout << "此时容器中元素的个数为：" << v1.size() << endl;
    //      此时，容器中元素个数为14，容量为19
    //      总之，会多开辟空间，但是每次多开辟多少是容器类自己决定的
}