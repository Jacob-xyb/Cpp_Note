#include "Cpp_Basic_main.h"
#include <iostream>

using namespace std;

class Student {
	char* text = NULL;
	int age = 10;

public:
	Student() {
		this->text = new char[10];
	}

	~Student() {
		if (text != NULL)
		{
			delete text;
		}
	}
};

int main() {
	//SpecialTopic::Func_access();
	//DataTypeConvert::Func_CharTest();
	//TernaryOperator::Func_Basic();
	//DataTypeArray::Func_TwoDimArrayInitialize();
	//PointNotes::Func_PointDefine();
	//SpecialTopic::Func_memset_Advance();
	Constant_Const::Func_ConstAndQuote();

	int a;
	cout << sizeof(a) << endl;

	getchar();
}