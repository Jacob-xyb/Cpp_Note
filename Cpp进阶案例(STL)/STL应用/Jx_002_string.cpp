#include "Jx_test.h"

// string的构造函数
//	`string();`		// 创建一个空的字符串 例如：string str;
//	`string(const char* s); `		// 使用字符串s初始化
void string_001()
{
	string s1;	// 默认构造
	const char* str = "hello world";		// C语言风格字符串
	string s2(str);
	cout << "构造的字符串为：" << s2 << endl;
}
//	`string(const string& str);`		// 使用一个string对象初始化另一个string对象
void string_002()
{	
	string str = "hello world";
	string s3(str);
	cout << "string初始化的对象为：" << s3 << endl;
}