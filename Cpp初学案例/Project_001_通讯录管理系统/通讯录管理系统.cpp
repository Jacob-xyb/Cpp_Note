#include <iostream>
using namespace std;
#define MAX 1000        // 最大人数
// 显示菜单界面

void printStart(int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "*";
    }   
}

void showMenu()
{
    // 声明变量
    string menuArr[] ={
        "1、添加联系人",
        "2、显示联系人",
        "3、删除联系人",
        "4、查找联系人",
        "5、修改联系人",
        "6、清空联系人",
        "0、退出通讯录",
    };

    // main
    printStart(5*2 + 2*2 + 1 + 2*6);
    cout << endl;
    for (int i = 0; i < 7; i++)
    {   
        printStart(5);
        cout << "  " << menuArr[i] << "  ";
        printStart(5);
        cout << endl;
    }
    printStart(5*2 + 2*2 + 1 + 2*6);
    cout << endl;
} 

struct Person
{
    string m_Name;
    int m_Sex;      // 性别 1男 2女
    int m_Age;
    string m_Phone;
    string m_Addr;
};


struct AddressBooks
{
    struct Person personArray[MAX];
    int m_Size;     // 通讯录中人员个数
};

void addPerson(struct AddressBooks * abs)
{
    // 判断通讯录是否已满，如果满了就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        // 添加具体联系人
        // add 姓名
        cout << "请输入姓名：" << endl;
        string name;        
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        // add 性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex;
        while (true)
        {   
            cin >> sex;
            if (sex == 1 || sex ==2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "性别输入有误，请重新输入：";            
        }
        // add phone
        string phone;
        cout << "请输入电话号码：" << endl;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        // add age
        
        // while (true)    
        // {
            // cin >> age;
        // }
        
        // add address
        cout << "请输入住址：" << endl;

        
        

    }
    
    
}

int main()
{   
    // 创建通讯录结构体变量
    struct AddressBooks abs;
    // 初始化通讯录中的当前人员个数
    abs.m_Size = 0;
 
    int select = 0;

    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:     // "1、添加联系人",
            addPerson(&abs);    // 利用地址传递可以修饰实参
            break;
        case 2:     // "2、显示联系人",
            break;
        case 3:     // "3、删除联系人",
            break;
        case 4:     // "4、查找联系人",
            break;
        case 5:     // "5、修改联系人",
            break;
        case 6:     // "6、清空联系人",
            break;
        case 0:     // "0、退出通讯录",
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;   
        default:
            break;
        }

        cout << endl;
    }
 
    return 0;
}