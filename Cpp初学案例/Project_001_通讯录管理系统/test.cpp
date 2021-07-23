#include <iostream>
using namespace std;


void printStart(int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "*";
    }
    
}


int main()
{
    // printStart(10);
    string menuArr[] ={
    "1、添加联系人",
    "2、显示联系人",
    "3、删除联系人",
    "4、查找联系人",
    "5、修改联系人",
    "6、清空联系人",
    "0、退出通讯录",
    };

    cout << sizeof(menuArr) << "\t" << sizeof(menuArr[0]) << endl;
    return 0;
}