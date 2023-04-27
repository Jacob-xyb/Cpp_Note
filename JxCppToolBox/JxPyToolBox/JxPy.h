#pragma once
#include <iostream>

#define JxPy_DLL extern "C" _declspec(dllimport) 

namespace JxPy
{
	/// <summary>
	/// 打印数组
	/// </summary>
	/// <typeparam name="arrT"></typeparam>
	/// <param name="arr"></param>
	/// <param name="num"></param>
	/// <param name="start"></param>
	/// <param name="end"></param>
	/// <param name="step"></param>
	template <typename arrT>
	void print(arrT* arr, int num, int start = 0, int end = 0, int step = 1);

	template<typename arrT>
	void print(arrT* arr, int num, int start, int end, int step)
	{
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
};

namespace JxTool {
	/// <summary>
	/// 将整数以二进制输出
	/// </summary>
	/// <param name="n"></param>
	void BinaryRecursion(int n);
}

