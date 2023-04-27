#include "DataType.h"
#include <string>

using namespace std;

template<typename T>
void py_print(T* arr, int length) {
	cout << "[ ";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

void DataType::Func_Test() {
	std::cout << "hello world" << std::endl;
}

void DataTypeConvert::Func_Test() {
	int iX = 7;
	string sX = to_string(iX);
	
	char cX = 65;		// 65: A
	cout << cX << endl;  // Out:A

}

void DataTypeConvert::Func_NumberToString() {
	int iX = 7;
	string sX = to_string(iX);

	char cX = 65;		// 65: A
	cout << cX << endl;  // Out:A

}

void DataTypeConvert::Func_CharTest() {
	char cX = 0b01000001;		// 65: A
	cout << cX << endl;

	char cY = 0b1;
	// char + char 就会默认转换为整型
	cout << cX + cY << endl;	//Out: 66

	char cZ = cX + cY;  // char = int
	cout << cZ << endl;		//Out: B

	int iX = cX;		// int = char
	cout << iX << endl;		// 65
}

void DataTypeArray::Func_ArrayInitialize()
{
	// 1.使用未初始化的内存，不会补0，但是可以调用
	int arr1[10];
	py_print(arr1, 10);		// [-1283640808, 32759, -1283647303, 32759, 31, 0, 1, 0, 0, 0, ]
	memset(arr1, 0, sizeof(arr1));
	py_print(arr1, 10);		// 手动内存初始化

	// 2.使用初始化的内存，会补0
	int arr2_1[4] = {};	// 会有 arraySize 个 0
	py_print(arr2_1, 4);		// [0, 0, 0, 0, ]
	int arr2_2[4] = { 1, 2 };	// 没有定义的话会自动补 0
	py_print(arr2_2, 4);		// [1, 2, 0, 0, ]

	// 3.长度会依据输入的数据个数而定
	int arr3_1[] = { 1, 2, 3 };
	py_print(arr3_1, 3);		// [1, 2, 3, ]
}

void DataTypeArray::Func_TwoDimArrayInitialize() {
	int arr1[2][3] = { 1,2,3,4,5,6 };
	cout << arr1[0][2] << endl;		// 3
	py_print(arr1, 6);				// 输出一维数组的地址, 间隔为 3 * 4 = 12 byte
	py_print(arr1[0], 6);			// 正常输出
	py_print(&arr1, 6);				// 输出二维数组的地址，间隔为 6 * 4 = 24 byte
	py_print(&arr1[0], 6);			// 输出一维数组的地址, 间隔为 3 * 4 = 12 byte
	py_print(&arr1[0][0], 6);		// 正常输出

	/*
	对于二维数组： arr == &arr[0] ; arr[0] == &arr[0][0] ; &arr 是数组指针
	*/
}