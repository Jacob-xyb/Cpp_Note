#include "Transfer.h"

std::string G_NAME = "Jacob-xyb";

void Call_OwnershipOperator() {
	std::string G_NAME = "与系统重名的局部变量";
	std::cout << "隐式调用优先调用局部变量: " << G_NAME << std::endl;
	std::cout << "显式调用全局变量: " << ::G_NAME << std::endl;
}
