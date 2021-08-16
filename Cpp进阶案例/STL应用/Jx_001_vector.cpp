#include "../Jx_test.h"
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
// 写一个打印vector<vector<int>>的函数方便调用

void printVector(vector<vector<int>>& v)
{
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}

// 创建一个一维向量，并打印出来
void init_Dim1andCout(vector<int>& v)
{
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "查看一下创建的vector数据" << endl;
    printVector(v);
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

    // n个elem方式构造   //`vector(n, elem);`
    vector<int> v3(10, 100);
    printVector(v3);
    //  elem不写不会报错，elem会被初始化为0  //Jx_star
    vector<int> v5(10);
    cout << "v5容量：" << v5.capacity() << endl;
    printVector(v5);

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
    init_Dim1andCout(v1);

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

    // v1继续直接赋值
    v1 = v2;
    cout << "看看v1赋值后的结果" << endl;
    printVector(v1);
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
    cout << "空容器的容量为：" << v1.capacity() << endl;        // out:0
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


// vector 插入和删除
/*- `push_back(ele);`		// 尾部插入元素ele
- `pop_back();`			// 尾部删除一个元素
- `insert(const_iterator pos, ele);`		// 迭代器指向位置pos插入元素ele
- `insert(const_iterator pos, int count, ele);`		// 迭代器指向位置pos插入count个元素ele
- `erase(const_iterator pos);`		// 删除迭代器指向的元素
- `erase(const_iterator start, const_iterator end);`		// 删除迭代器从start到end之间的元素
- `clear();`			// 删除容器中所有元素*/
void vector_011()
{
    vector<int> v1;
    init_Dim1andCout(v1);

    for (int i = 0; i < 5; i++)
    {
        v1.pop_back();      // pop_back()并不返回数据
    }
    cout << "利用pop_back()删除5次" << endl;
    printVector(v1);

    // 迭代器的方式插入
    v1.insert(v1.begin() + 2, 99);
    cout << "在中间插入数据" << endl;
    printVector(v1);

    // 迭代器的方式删除
    v1.erase(v1.begin() + 2);
    cout << "删除之前插入的99" << endl;
    printVector(v1);

    // clear() 清除
    v1.clear();
    cout << "clear()清除" << endl;
    printVector(v1);
}


// vector数据存取
/*- `at(int idx);`		// 返回索引idx所指的数据
- `operator[];`			// 返回索引idx所指的数据
- `front();`			// 返回容器中第一个数据元素
- `back();`				// 返回容器中最后一个数据元素*/
void vector_012()
{
    vector<int> v1;
    init_Dim1andCout(v1);

    cout << "利用for循环分别取索引输出：" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "第一个元素：" << v1.front() << endl;;
    cout << "第一个元素：" << v1.back() << endl;
}


// vector 互换容器
/*`swap(vec);`		// 将vec与本身的元素互换*/
void vector_013()
{
    vector<int> v1;
    init_Dim1andCout(v1);

    vector<int> v2(10,0);       // 提前分配好空间
    for (int i = 0,j = v2.size()-1; i < v2.size(); i++,j--)
    {
        v2[i] = j;
    }
    cout << "v2创建的数据为：" << endl;
    printVector(v2);

    v2.swap(v1);
    cout << "swap()互换后" << endl;
    cout << "v1的数据为：" << endl;
    printVector(v1);
    cout << "v2的数据为：" << endl;
    printVector(v2);

    // 应用场景
    //      可以查看当前v2的容量
    cout << "当前v2的容量为：" << v2.capacity() << endl;
    cout << "当前v2的元素为：" << v2.size() << endl;
    //      运用 匿名对象拷贝构造 + swap 可以缩小内存空间让'容量=个数'
    vector<int>(v2).swap(v2);
    cout << "swap()后v2的容量为：" << v2.capacity() << endl;
    cout << "swap()后v2的元素为：" << v2.size() << endl;
    printVector(v2);
}


// vector 预留空间
/*`reserve(int len);`		// 容器预留len个元素长度，预留位置不初始化，元素不可访问。*/
void vector_014()
{
    vector<int> v;
    // 查看压入十万次数据时，内存开辟的次数
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "开辟内存的次数：" << num << endl;

    vector<int> v1;
    v1.reserve(100000);
    num = 0;
    p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "开辟内存的次数：" << num << endl;
}



// vector与数组联动
void vector_016()
{
    // 内置数组我们可以显式地把数组的元素初始化为一组常量值
    int ia_a[10] = { 0,1,2,3,4,5,6,7,8,9 };
    //      但是vector不能够这样
    //      不过可以用指针的形式来利用数组创建对象
    // 数组 ia_a 就是一个指针，指向此数组的首地址，因此可以这样创建vector
    vector<int> ivt_v1(ia_a, ia_a+ sizeof(ia_a) / sizeof(ia_a[0]));
    printVector(ivt_v1);

    // 还可以;可以有多种写法
    vector<int> ivt_v2(&ia_a[3], &ia_a[9]);
    //vector<int> ivt_v2(&ia_a[3], &ia_a[8] + 1);
    //vector<int> ivt_v2(&ia_a[3], &ia_a[8+1]);
    printVector(ivt_v2);

    //vector<int> ivt_v2();   // TODO：这是一个奇怪的对象

    // 扩展insert()
    //  insert(const_iterator pos, beg(), end())
    //  通俗来说是可以插入指针范围内的数据
    cout << endl;
    cout << "将v2插入v1的前面：" << endl;
    ivt_v1.insert(ivt_v1.begin(), ivt_v2.begin(), ivt_v2.end());
    printVector(ivt_v1);

    cout << endl;
    cout << "将数组插入v2可是可以的：" << endl;
    ivt_v2.insert(ivt_v2.begin(), ia_a, ia_a + 3);
    printVector(ivt_v2);
}


// vector 新特性创建向量
void vector_C11_eg001()
{
    // 直接用数组创建向量
    //  一维数组
    vector<int> ivt_v1{ 1,2,3,4,5 };
    cout << "新特性创建一维数组v1：" << endl;
    printVector(ivt_v1);
    cout << endl;
    //  二维数组
    vector<vector<int>> ivt_vv1{ {1,2,3},{2,3,4},{3,4,5} };
    printVector(ivt_vv1);
}


//研究一下二维向量
void vector_015()
{
    vector<vector<int>> v;
    cout << "空的二维数组对象容量为：" << v.capacity() << endl;
    // 创建小容器
    vector<int> v1;
    cout << "空的一维数组对象容量为：" << v1.capacity() << endl;
    v1 = { 1,2,3,4 };   // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v.push_back(v1);
    }
    // 通过大容器，遍历所有数据
    printVector(v);

    //cout << v[1][1] << endl;    // 说明可以v[][]调用某一个元素
    //printVector(v[1]);  // 说明v[row]是一个vector<>尖括号内的对象
}

//  二维数组的申明
void vector_2dim001()
{
    //声明一维向量的方式：
    //  `vector(n, elem);`
    vector<int> dim1_v1(10);
    cout << "如果不填elem，则初始化为0" << endl;
    printVector(dim1_v1);
    vector<int> dim1_v2(10, 1);
    cout << "如果填elem，则初始化为elem" << endl;
    printVector(dim1_v2);
    //  其实(n,elem)中：
    //      n：指代vector<>中<>内的数量
    //      elem：指代vector<>中<>内的内容

    //将一维数组的构造类比到二维数组的构造上
    //  创建m*n的数组
    //vector<vector<int>> dim2_v1(m, vector<int>(n));
    vector<vector<int>> dim2_v1(3, vector<int>(3));
    cout << "查看构造的二维数组" << endl;
    printVector(dim2_v1);
    vector<vector<int>> dim2_v2(3, vector<int>(3, 6));
    cout << "查看构造的二维数组" << endl;
    printVector(dim2_v2);
    
    //对二维数组的单行进行赋值
    //  tips:可以超出原有数组长度进行赋值
    dim2_v2[0] = { 1,2,3,4,5,6 };
    cout << "单行赋值的二维数组" << endl;
    printVector(dim2_v2);

    //构建二维数组只输入一个参数
    vector<vector<int>> dim2_v3(3);
    cout << "构建二维数组只输入一个参数" << endl;
    printVector(dim2_v3);   //输出为空
    cout << "是否能调用空间" << endl;
    //dim2_v3[0][0] = 1;    //不能调用空间，切记切记！
}

//vector区间
void vector_017()
{
    vector<int> v{ 0,1,2,3,4,5,6 };
    //创建一个v1，size()小于v.size()
    vector<int> v1(3);
    copy(v.begin(),v.begin() + 2, v1.begin());
    printVector(v1);    
    //  在范围内进行拷贝当然是没有问题
    //copy(v.begin(), v.end(), v1.begin());
    //printVector(v1);
    ////  在范围外进行拷贝就会报错，程序崩溃

    //assign比较便捷
    //printVector((v.begin(), v.end()));
}

//二维数组resize()
void vector_2dim002()
{
    vector<vector<int>> v1(3, { 6,6,6,6,6,6 });
    cout << "打印初始创建的二维数组" << endl;
    printVector(v1);
    cout << "此时的容量：" << v1.capacity() << endl;  //这只是一行
    cout << "此时的空间：" << v1.size() << endl;
    cout << "再次计算整个二维数组" << endl;
    cout << "此时的容量：" << v1.capacity()*v1[0].capacity() << endl;
    cout << "此时的空间：" << v1.size()*v1[0].size() << endl;

    v1.resize(4, {0,0});    //resize仅仅只针对v1<>里面的东西进行resize
    printVector(v1);
    cout << "再次计算整个二维数组" << endl;
    cout << "此时的容量：" << v1.capacity() * v1[0].capacity() << endl;
    cout << "此时的空间：" << v1.size() * v1[0].size() << endl;

    v1[0].resize(12);
    printVector(v1);
    cout << "再次计算整个二维数组" << endl;
    cout << "此时的容量：" << v1.capacity() * v1[0].capacity() << endl;
    cout << "此时的空间：" << v1.size() * v1[0].size() << endl;
    cout << "显然乘法不能够算出精确的容量和个数了" << endl;
    int cap = 0, num = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        cap += v1[i].capacity();
        num += v1[i].size();
    }
    cout << "再次计算整个二维数组" << endl;
    cout << "此时的容量：" << cap << endl;
    cout << "此时的空间：" << num << endl;
}