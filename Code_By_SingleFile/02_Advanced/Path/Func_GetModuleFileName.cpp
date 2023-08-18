#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char cFilePath[MAX_PATH];		// 文件路径
    memset(cFilePath, 0, MAX_PATH);
    int size = GetModuleFileName(NULL, (LPSTR)cFilePath, MAX_PATH);

    printf("path=%s\nsize=%d\n", cFilePath, size);
    // 注意：获取的是 .exe 文件的完整路径

    // 继续获取路径
    string strModuleFoldPath = string(cFilePath);
    int iFind = strModuleFoldPath.rfind('\\');
    strModuleFoldPath = strModuleFoldPath.substr(0, iFind);
    printf("dir=%s\n", strModuleFoldPath.c_str());

    return 0;
}
