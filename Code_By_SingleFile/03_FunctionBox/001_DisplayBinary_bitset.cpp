#include <iostream>
#include <bitset>
using namespace std;

string GetBinaryString(int num)
{
    return bitset<sizeof(int) * 4>(num).to_string();
}

void DisplayBinary(int num)
{
    cout << GetBinaryString(num) << endl;
}

int main()
{
    DisplayBinary(10); //Out:0000000000001010
    DisplayBinary(-2); //Out:1111111111111110
    return 0;
}

