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
	for (int i = 0; i < 10; i++)
	{
		if (i >= 10 / 2 + 1)
		{
			cout << i << " ";
		}
	}
	

	return 0;
}