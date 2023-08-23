// xx.cpp
#include <iostream>
#include <stdio.h>

using namespace std;

void assign(int *p)
{
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
}

int main()
{
	int *arr = new int[100]{0};
	assign((int*)arr + 10);
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}