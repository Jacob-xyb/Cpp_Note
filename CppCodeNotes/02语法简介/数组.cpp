#include "Transfer.h"


void ArrayDeclarationWay() {
	// 1.使用未初始化的内存，不会补0，但是可以调用
	int arr1[10];
	PrintArrry(arr1, 10);		// [-1283640808, 32759, -1283647303, 32759, 31, 0, 1, 0, 0, 0, ]

	// 2.使用初始化的内存，会补0
	int arr2_1[4] = {};	// 会有 arraySize 个 0
	PrintArrry(arr2_1, 4);		// [0, 0, 0, 0, ]
	int arr2_2[4] = { 1, 2 };	// 没有定义的话会自动补 0
	PrintArrry(arr2_2, 4);		// [1, 2, 0, 0, ]

	// 3.长度会依据输入的数据个数而定
	int arr3_1[] = { 1, 2, 3};
	PrintArrry(arr3_1, 3);		// [1, 2, 3, ]
}

void ArrayVariableName() {
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	std::cout << arr1 << std::endl;				// 0000000F42AFFAF0
	std::cout << arr1 + 1 << std::endl;			// 0000000F42AFFAF4
	std::cout << *arr1 << std::endl;			// 1
	std::cout << *(arr1 + 1) << std::endl;		// 2
}
