#include "../Jx_进阶案例.h"

/*== 算术运算符 ==*/
void arithmetic_operator()
{

}

void arithmetic_operator_division()
{
	//整数 / 整数 = 整数
	int i_a, i_b;
	i_a = 10;
	i_b = 3;
	std::cout << i_a / i_b << std::endl;

	float f_a, f_b;
	f_a = 10;
	f_b = 3;
	std::cout << f_a / f_b << std::endl;
	std::cout << f_a / i_b << std::endl;
}

/*== 逻辑运算符 ==*/
//&&
//condition1 && condition2时，会优先判断condition1
//condition1不满足时会直接返回false，并不会再执行conditon2
void test_andand001()
{
	std::vector<int> digits{ 9,9,9 };
	int bit = digits.size() - 1;
	while (bit >= 0 && digits[bit] == 9)
	//while (digits[bit] == 9 && bit >= 0)	//Expression: vector subscript out of range 
	{
		digits[bit] = 0;
		bit--;
	}
	for (int i = 0; i < digits.size(); i++)
	{
		std::cout << digits[i] << " ";
	}
	std::cout << std::endl;
}