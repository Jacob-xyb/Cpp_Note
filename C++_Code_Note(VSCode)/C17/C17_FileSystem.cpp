/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-14 10:16:09
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-17 11:14:19
 * @Description: Life is struggle.
 */
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
using namespace std;

/// @brief 判断路径是否存在
void Func_Path_Is_Exists();

/// @brief 获取目录中所有的文件路径
void Func_Get_Files_In_Directory();

int main()
{
    Func_Path_Is_Exists();
    Func_Get_Files_In_Directory();
    return 0;
}

void Func_Path_Is_Exists()
{
	printf("** Start Func_Path_Is_Exists **\n");
    std::string directory_path = "./c";
    if (fs::exists(directory_path))
    {
		cout << "Path exists." << endl;
    }
	else
	{
		cout << "Path not exists." << endl;
	}
}

void Func_Get_Files_In_Directory()
{
	printf("** Start Func_Get_Files_In_Directory **\n");

    std::string directory_path = "./";
    std::vector<fs::path> files;

	if (!fs::is_directory(directory_path))
	{
		cout << "Path not exists." << endl;
		return;
	}
	
    for (const auto &entry : fs::directory_iterator(directory_path))
    {
        // 普通文件是指不是目录、符号链接或其他特殊文件类型的文件。
        if (entry.is_regular_file())
        {
            files.push_back(entry.path());
        }
    }

    for (const auto &file : files)
    {
		std::cout << file.string() << std::endl;	// 拼接后的路径
        std::cout << file.filename().string() << std::endl;
    }
}