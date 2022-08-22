#include <fstream>
#include <sstream> 
//#include "../Jx_进阶案例.h"

/*
char buff[MAX_PATH];//用于存放获取的路径信息。
GetModuleFileName(NULL,buff,MAX_PATH);//第一个参数为句柄，NULL则指向当前程序。第二个参数用于存放地址的指针，第三个参数，系统自带的宏定义。不用管。
CString str=buff;//将buff存放的路径赋给字符串str,此时buff值如：“E:\MyTest\Debug\****.exe”
int pos=str.ReverseFind('\\');//查找倒数最后一个“\\”符号
str=str.Left(pos+1);//str只获取exe所在文件夹路径； str为："E:\MyTest\Debug\"
//注意：第三步reversefind()函数中使用的是单引号。
*/

std::string getExePath()
{
#ifdef WIN32
	char buffer[260];
	GetModuleFileName(NULL, (LPSTR)buffer, MAX_PATH); //获取当前exe的路径
	string addr_profile = string(buffer);
	addr_profile = addr_profile.substr(0, addr_profile.rfind('\\'));

	subreplace(addr_profile, "\\", "/");//换成/斜杠
	return addr_profile;
#else
#endif
}