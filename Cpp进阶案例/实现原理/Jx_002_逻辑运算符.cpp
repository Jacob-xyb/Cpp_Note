#include "../Jx_进阶案例.h"

//&&
//condition1 && condition2时，会优先判断condition1
//condition1不满足时会直接返回false，并不会再执行conditon2
void test_andand001()
{
	vector<int> digits{ 9,9,9 };
	int bit = digits.size() - 1;
	while (bit >= 0 && digits[bit] == 9)
	//while (digits[bit] == 9 && bit >= 0)	//Expression: vector subscript out of range 
	{
		digits[bit] = 0;
		bit--;
	}
	for (int i = 0; i < digits.size(); i++)
	{
		cout << digits[i] << " ";
	}
	cout << endl;
}