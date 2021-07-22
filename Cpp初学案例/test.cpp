#include <iostream>
using namespace std;

int main()
{
    string seed = "ABCDE";
    string num = "字母" + seed[0];
    cout << num << endl;
    // num += seed[0];
    // cout << "字母" + seed[0] << endl;
    // cout << num << endl;

    return 0;
}