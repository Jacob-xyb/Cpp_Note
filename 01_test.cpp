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

class Person
{

};

int main()
{
	unsigned int x = 10;
	int y = x;

	Person* p = nullptr;

	if (p)
	{
		cout << y << endl;
	}
	
	return 0;
}