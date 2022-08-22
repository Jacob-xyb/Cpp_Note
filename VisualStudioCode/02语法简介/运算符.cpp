#include "Transfer.h"


// 优先级：！ > 算术运算符 > 关系运算符 > && > || > 赋值运算符
void ArithmeticOperator() {
	// 算术运算符： +  -  *  /  %  ^  !
	float fA = 10.18;
	float fB = 08.28;
	int iA = 777;
	int iB = 2;
	
	// 1.加减乘除
	std::cout << "10.10 + 08.28 = " << fA + fB << std::endl;
	std::cout << "10.10 - 08.28 = " << fA - fB << std::endl;
	std::cout << "10.10 * 08.28 = " << fA * fB << std::endl;
	std::cout << "10.10 / 08.28 = " << fA / fB << std::endl;
	//   比较特殊的：int / int 直接会省去小数点后的数
	std::cout << "除法有些特殊" << std::endl;
	std::cout << "float / int = float: " << fA / iB << std::endl;
	std::cout << "int / float = float: " << iA / fB << std::endl;
	std::cout << "int / int = int: " << iA / iB << std::endl;		
}
