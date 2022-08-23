#include "Transfer.h"


// 三目运算符 Exp1 ? Exp2 : Exp3;

void TripletOperator() {
	int a = 10; int b = 20; int c = 0;
	c = (a > b ? a : b);  // c 就是 a b 中最大的值

	std::cout << "三目运算符用于返回：" << std::endl;
	std::cout << c << std::endl;	// 20

	std::cout << "三目运算符用于赋值：" << std::endl;
	(a > b ? a : b) = 100;
	std::cout << b << std::endl;	// 100
}
