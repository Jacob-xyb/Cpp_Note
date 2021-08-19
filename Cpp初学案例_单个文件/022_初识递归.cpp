#include <iostream>
using namespace std;

//初识最简单的递归应用
//计算n!
//	递归三部曲
/*
1. 递归算法必须有一个基本结束条件（最小规模问题的直接解决）
2. 递归算法必须能改变状态向基本结束条件演进（减小问题规模）
3. 递归算法必须调用自身（解决减小了规模的相同问题）
*/

int factorial(int n)
{
	//最小规模问题
	if (n <= 1)	return 1;	//0!=1
	//减小规模问题,调用自身
	//	n! = n*(n-1)!
	return n * factorial(n - 1);
}

int main()
{
	cout << factorial(3) << endl;
	system("pause");
	return 0;
}