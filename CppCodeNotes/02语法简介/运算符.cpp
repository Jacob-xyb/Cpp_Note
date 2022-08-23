#include "Transfer.h"


// 优先级：！ > 算术运算符 > 关系运算符 > && > || > 赋值运算符

void ArithmeticOperator() {
	// 算术运算符： +  -  *  /  %  ^  !
	float fA = 10.18;
	float fB = 08.28;
	int iA = 777;
	int iB = 2;
	
	// 1.加减乘除
	std::cout << "1.加减乘除：" << std::endl;
	std::cout << "10.10 + 08.28 = " << fA + fB << std::endl;
	std::cout << "10.10 - 08.28 = " << fA - fB << std::endl;
	std::cout << "10.10 * 08.28 = " << fA * fB << std::endl;
	std::cout << "10.10 / 08.28 = " << fA / fB << std::endl;
	//   比较特殊的：int / int 直接会省去小数点后的数
	std::cout << "除法有些特殊：" << std::endl;
	std::cout << "float / int = float: " << fA / iB << std::endl;
	std::cout << "int / float = float: " << iA / fB << std::endl;
	std::cout << "int / int = int: " << iA / iB << std::endl;	

	// 2. int 取整; % 取余
	std::cout << "取余取整：" << std::endl;
	std::cout << "777 / 2 = " << iA / iB << std::endl;		// 整数除法天生取整
	std::cout << "777 % 2 = " << iA % iB << std::endl;

}

void BinaryRecursion(int n)
{
	int a = n % 2;
	n >>= 1;
	if (n != 0)
	{
		BinaryRecursion(n);
	}
	std::cout << a;
}

void AssignmentOperator() {
	// 和算术运算符相关的赋值运算符就不介绍了

	// 位运算符
	std::cout << "位运算：" << std::endl;
	std::cout << "1 << 2 = " << (1 << 2) << std::endl;		// 4
	std::cout << "1 << 4 = " << (1 << 4) << std::endl;		// 16
	std::cout << "8 >> 1 = " << (8 >> 1) << std::endl;		// 4
	std::cout << std::endl;

	// 与或运算
	std::cout << "与或运算：" << std::endl;
	std::cout << "1100 & 100 = ";	// 1100 & 100 = 100
	BinaryRecursion(0xc & 0x4);
	std::cout << std::endl;		
	std::cout << "1010 | 110 = ";	// 1010 & 110 = 1110
	BinaryRecursion(10 | 6);
	std::cout << std::endl;		
	std::cout << "1010 ^ 110 = ";	// 1010 & 110 = 1100
	BinaryRecursion(10 ^ 6);
	std::cout << std::endl;
}

void CommaOperator() {
	int a = 1;
	int b = 2;
	int c = (a, b++, a+=b);
	std::cout << c << std::endl;		// 4
	// 计算顺序为：a=1, b=2+1=3, a=a+b=1+3=4, c=a=4
}

