//#include "Cpp_Basic_main.h"
#include <iostream>

using namespace std;
using namespace System;


int main() {
	//SpecialTopic::Func_access();
	//DataTypeConvert::Func_CharTest();
	//TernaryOperator::Func_Basic();
	//DataTypeArray::Func_TwoDimArrayInitialize();
	//PointNotes::Func_PointDefine();
	//SpecialTopic::Func_memset_Advance();
	//Constant_Const::Func_ConstAndQuote();
	//BitwiseOperator::Func_BitwiseXOR();

	int len = 200 * 5 * 1044;

	cli::array<double, 1>^ dwavelength = gcnew cli::array<double, 1>(len);

	for (size_t i = 0; i < len; i++)
	{
		cout << dwavelength[i] << ", ";
	}

	cout << "success" << endl;

	getchar();

}