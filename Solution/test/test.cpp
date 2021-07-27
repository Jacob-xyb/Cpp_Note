#include <iostream>
using namespace std;

int main()
{
	string temp;
	cout << "input:" << endl;
	cin >> temp;
	if (temp == "")
	{
		cout << "可以为空" << endl;
	}
	else
	{
		cout << "回车无效" << endl;
	}

	system("pause");
	return 0;
}