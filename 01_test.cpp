/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-06-21 16:42:17
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-04 16:31:12
 * @Description: Life is struggle.
 */
// xx.cpp
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void assign(int *p)
{
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
}

class Person
{
};

int main()
{
	bool is_b = 2 * 2 < 3;
	cout << is_b << endl;;
	if (is_b = false)
	{
		cout << "xx";
	}

	int arr[20] = {};
	// *barr = false;

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	
	// cout << barr[0] << endl;
	// cout << barr[1] << endl;
	
	

	return 0;
}