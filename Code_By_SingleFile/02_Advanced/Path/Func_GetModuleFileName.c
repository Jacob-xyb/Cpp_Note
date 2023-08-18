#include <stdio.h>
#include <Windows.h>

int main(int argc, char const *argv[])
{
    char cFilePath[MAX_PATH];		// 文件路径
    memset(cFilePath, 0, MAX_PATH);
    int size = GetModuleFileName(NULL, (LPSTR)cFilePath, MAX_PATH);

    printf("path=%s\nsize=%d\n", cFilePath, size);
    // 注意：获取的是 .exe 文件的完整路径

    return 0;
}
