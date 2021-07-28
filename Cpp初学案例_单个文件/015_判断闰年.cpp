#include <iostream>
using namespace std;

int main()
{
    int year;
    string choose;
    while (true)
    {
        cout << "输入年份: ";
        cin >> year;

        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                // // 这里如果被 400 整除是闰年
                if (year % 400 == 0)
                    cout << year << " 是闰年";
                else
                {
                    cout << year << " 不是闰年";
                }
            }
            else
            {
                cout << year << " 是闰年";
            }
        }
        else
        {
            cout << year << " 不是闰年";
        }

        cout << endl; 
        cout << "是否继续(yes/no)" << endl;
        cin >> choose;
        if (choose == "no" || choose == "n")    
        {
            system("pause");
            return 0;
        }
        else
        {
            system("cls");
        }
    }
}