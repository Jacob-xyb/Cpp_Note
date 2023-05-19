#include "SpecialTopic.h"
#include <Windows.h>
#include <io.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <direct.h>

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

void SpecialTopic::Func_memset() {
	char cFilePath[_MAX_PATH];
	//std::string res = std::string(cFilePath);	// 未添加字符串零终止符
	memset(cFilePath, 0, _MAX_PATH);
	string res = string(cFilePath);
	std::cout << res << std::endl;
}

void SpecialTopic::Func_memset_Advance() {
	int a[6];
	int len = sizeof(a);
	// 只取最后一个字节来初始化
	py_print(a, 6);

	memset(a, -1, len);
	py_print(a, 6);

	memset(a, 1, len);
	py_print(a, 6);

	memset(a, 0, len);
	py_print(a, 6);
}

void SpecialTopic::Func_GetModuleFileName() {
	char cFilePath[_MAX_PATH];
	ZeroMemory(cFilePath, _MAX_PATH);
	GetModuleFileName(NULL, cFilePath, _MAX_PATH);
	string res = string(cFilePath);
	std::cout << res << std::endl;
}

void SpecialTopic::Func_access() {
	char cFilePath[_MAX_PATH];
	memset(cFilePath, 0, _MAX_PATH);
	 _getcwd(cFilePath, _MAX_PATH);		// 此文件所在的文件夹
	std::cout << cFilePath << std::endl;
	// 返回值 0,代表文件存在；

	char cExePath[_MAX_PATH];
	memset(cExePath, 0, _MAX_PATH);
	GetModuleFileName(NULL, cExePath, _MAX_PATH);
	std::cout << cExePath << std::endl;
	std::cout << _access(cExePath, 0) << std::endl;
}

