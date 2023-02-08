#include <stdio.h>
//#include "C_Basic_main.h"


#pragma region FlowControl_if
void func_FlowControl_if() {
	// if (expression) statement
	int x = 10;
	if (x == 10) printf("x is 10");

	// if (expression) statement
	// else statement

}
#pragma endregion

#pragma region FlowControl_三元运算符
void func_FlowControl_TernaryOperator() {
	// <expression1> ? <expression2> : <expression3>
	int x = (10 > 5) ? 10 : 5;
	printf("x is %d", x);
}
#pragma endregion

#pragma region FlowControl_switch
void func_FlowControl_switch() {
	/*switch (expression) {
	  case value1: statement
	  case value2: statement
	  default: statement
	}*/
	int grade = 0;
	switch (grade) {
	case 0:
		printf("False");
		break;
	case 1:
		printf("True");
		break;
	default:
		printf("Illegal");
	}

	// case后面的语句体，不用放在大括号里面，这也是为什么需要break的原因。
}
#pragma endregion


#pragma region FlowControl_while
void func_FlowControl_FlowControl_while() {
	// while (expression)
	//   statement
}
#pragma endregion

#pragma region FlowControl_do_while
void func_FlowControl_FlowControl_do_while() {
	// do statement
	// while (expression);
}
#pragma endregion

#pragma region FlowControl_for
void func_FlowControl_FlowControl_for() {
	// for (initialization; continuation; action)
	//    statement;
	for (int i = 10; i > 0; i--)
		printf("i is %d\n", i);
	
	// 条件部分的三个表达式，每一个都可以有多个语句，语句与语句之间使用逗号分隔。
	int i, j;
	for (i = 0, j = 999; i < 10; i++, j--) {
		printf("%d, %d\n", i, j);
	}
}
#pragma endregion


#pragma region FlowControl_break

#pragma endregion

#pragma region FlowControl_continue

#pragma endregion

#pragma region FlowControl_goto

#pragma endregion
