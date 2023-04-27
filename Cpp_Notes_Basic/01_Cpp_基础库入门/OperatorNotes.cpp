#include <iostream>
#include "OperatorNotes.h"
using namespace std;

void TernaryOperator::Func_Basic()
{
	int a = 0;
	int b = 7;
	(a > b ? a : b) = 99;

	printf("a = %d, b = %d\n", a, b);	// a = 0, b = 99
}
