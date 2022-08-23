#pragma once
#include <iostream>

void BinaryRecursion(int n);

template <typename arrT>
void PrintArrry(arrT arr[], int num, int start = 0, int end = 0, int step = 1);



template <typename arrT>
void PrintArrry(arrT arr[], int num, int start, int end, int step) {
	if (end <= 0) {
		end += num;
	}
	std::cout << "[";
	for (size_t i = start; i < end; i+=step)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "]\n";
}