#pragma once
#include <iostream>
#include <stdio.h>

void Call_point_and_array();

#define test_Jx() Call_point_and_array()

template <typename arrT>
void PrintArrry(arrT arr[], int num, int start = 0, int end = 0, int step = 1);



template <typename arrT>
void PrintArrry(arrT arr[], int num, int start, int end, int step) {
	if (end <= 0) {
		end += num;
	}
	std::cout << "[";
	for (size_t i = start; i < end; i += step)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "]\n";
}