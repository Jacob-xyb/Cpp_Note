#include "../Jx_进阶案例.h"

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
//	`string(int n, char c);`		    // 使用n个字符c初始化
void string_003()
{
	string s4(10, 's');
	cout << s4 << endl;
}


// string 赋值操作 （等号；成员函数）
/*- `string& operator=(const char* s);`		// `char*`类型字符串 赋值给当前字符串
- `string& operator=(const string& s);`		// 字符串s 赋值给当前字符串
- `string& operator=(char c);`		// 字符c 赋值给当前字符串
- `string& assign(const char* s);`		// 字符串s 赋值给当前字符串
- `string& assign(const char* s, int n);`		// 字符串s 的前n个字符 赋值给当前字符串
- `string& assign(const string& s);`		// 字符串s  赋值给当前字符串
- `string& assign(int n, char c);`		// n个字符c  赋值给当前字符串*/
void string_004()
{
	string jx;
	// `string& operator=(const char* s);`
	jx = "hello world";
	cout << "string& operator=(const char* s);" << jx << endl;
	// `string& operator=(const string & s); `
	string jx2;
	jx2 = jx;
	cout << "string& operator=(const string & s); " << jx2 << endl;
	// `string& operator=(char c); `
	jx2 = 'x';
	cout << "string& operator=(char c); " << jx2 << endl;
	
	// `string& assign(const char* s); `
	jx2.assign("hello world");
	cout << "string& assign(const char* s); " << jx2 << endl;
	// `string& assign(const char* s, int n); `
	jx2.assign("hello world", 8);
	cout << "string& assign(const char* s, int n); " << jx2 << endl;
	// `string& assign(const string & s); `
	jx2.assign(jx);
	cout << "string& assign(const string & s); " << jx2 << endl;
	// `string& assign(int n, char c); `
	jx2.assign(5, 'x');
	cout << "string& assign(int n, char c);" << jx2 << endl;
}


// string字符串拼接
/*- `string& operator+=(const char* str);`		// 重载+=操作符
- `string& operator+=(const char c);`		// 重载+=操作符
- `string& operator+=(const string& str);`		// 重载+=操作符
- `string& append(const char* s);`		// 把字符串s连接到当前字符串结尾
- `string& append(const char* s,int n);`		// 把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const string& s);`		// 同 `operator+=(const string& str)`
- `string& append(const string&s, int pos, int n);`		// 字符串s中从pos开始的n个字符连接到字符串结尾*/
void string_005()
{
	string jx = "I";
	// `string& operator+=(const char* str);`
	jx += " have ";
	cout << "string& operator+=(const char* str);" << jx << endl;
	//-`string& operator+=(const char c); `		// 重载+=操作符
	jx += " a";
	cout << "string& operator+=(const char c); " << jx << endl;
	//-`string& operator+=(const string & str); `		// 重载+=操作符
	string str = " hobby";
	jx += str;
	cout << "string& operator+=(const string & str); " << jx << endl;

	string jxa = "I";
	//-`string& append(const char* s); `		// 把字符串s连接到当前字符串结尾
	jxa.append(" have");
	cout << "string& append(const char* s); " << jxa << endl;
	//-`string& append(const char* s, int n); `		// 把字符串s的前n个字符连接到当前字符串结尾
	jxa.append(" a hobby", 2);
	cout << "string& append(const char* s, int n); " << jxa << endl;
	//-`string& append(const string & s); `		// 同 `operator+=(const string& str)`
	jxa.append(str);
	cout << "string& append(const string & s); " << jxa << endl;
	//-`string& append(const string & s, int pos, int n); `		// 字符串s中从pos开始的n个字符连接到字符串结尾*/
	str = "I have a hobby that is coding!";
	jxa.append(str, 14, 16);
	cout << "string& append(const string & s, int pos, int n); " << jxa << endl;
	//		if `int n > len`,what will happen?
	jxa.append(str, 14, 26);
	cout << "string& append(const string & s, int pos, int n); " << jxa << endl;
	//		no error happend
}


// string查找和替换
/*- `int find(const string& str, int pos = 0) const;`		// 查找str第一次出现的位置，从pos开始查找
- `int find(const char* s, int pos = 0) const;`		// 查找s第一次出现的位置，从pos开始查找
- `int find(const char* s, int pos, int n) const;`		// 从pos位置查找s的前n个字符第一次位置
- `int find(const char c, int pos = 0) const;`		// 查找字符c第一次出现的位置
- `int rfind(const string& str, int pos = npos) const;`		// 查找str最后一次位置，从pos开始查找
- `int rfind(const char* s, int pos = npos) const;`		// 查找s最后一次位置，从pos开始查找
- `int rfind(const char* s, int pos, int n) const;`		// 从pos位置查找s的前n个字符最后一次位置
- `int rfind(const char c, int pos =0) const;`		// 查找字符c最后一次位置
- `string& replace(int pos, int n, const string& str);`		// 替换从pos开始n个字符为字符串str
- `string& replace(int pos, int n, cosnt char* s);`		// 替换从pos开始n个字符为字符串s*/
void string_006()
{
	string jx = "aaabbbcccddd";
	int res;
	//`int find(const string& str, int pos = 0) const;`		// 查找str第一次出现的位置，从pos开始查找
	res = jx.find("bb");
	cout << "int find(const string& str, int pos = 0) const; " << res << endl;
	//-`int find(const char* s, int pos, int n) const; `		// 从pos位置查找s的前n个字符第一次位置
	res = jx.find("bb", 3);
	cout << "int find(const char* s, int pos, int n) const; " << res << endl;
	//		if nofonud, function will return -1;
	res = jx.find("bb", 5);
	cout << "int find(const char* s, int pos, int n) const; " << res << endl;
	//		返回的位置是位于整个string的位置，返回的结果与pos无关
	res = jx.find("bb", 5, 1);
	cout << "int find(const char* s, int pos, int n) const; " << res << endl;

	// rfind 从右往左查找
	//-`int rfind(const string & str, int pos = npos) const; `		// 查找str最后一次位置，从pos开始查找
	res = jx.rfind("bb");
	cout << "int rfind(const string & str, int pos = npos) const; " << res << endl;
	//		if `npos>len`;what will happen?
	//res = jx.rfind("bb",100);
	cout << "int rfind(const string & str, int pos = npos) const; " << res << endl;
	//		no error happend
	//		`npos<0`时 就是相当于找到最后，和python的index不相同。
	res = jx.rfind("ddd", -3);
	cout << "int rfind(const string & str, int pos = npos) const; " << res << endl;

	//-`string& replace(int pos, int n, const string & str); `		// 替换从pos开始n个字符为字符串str
	jx.replace(0, 10, "bb");
	cout << "string& replace(int pos, int n, const string & str); " << jx << endl;
}


// string字符串比较
/*- `int compare(const string& s) const;`
- `int compare(const char* s) const;`*/
void string_007()
{
	string str01 = "hello world";
	string str02 = "hello ";
	string str03 = "world";
	cout << "第一次比较的返回值： " << str01.compare(str02) << endl;
	str02 += str03;
	cout << "第二次比较的返回值： " << str01.compare(str02) << endl;
}


// string单个字符存取
/*- `char& operator[](int n);`		// 通过 [] 方式取字符
- `char& at(int n);`		// 通过 at 方法取字符*/
void string_008()
{
	string str = "hello world";
	///*- `char& operator[](int n);`		// 通过 [] 方式取字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;

	//-`char& at(int n); `		// 通过 at 方法取字符*/
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i);
	}
	cout << endl;

	// 修改单个字符
	str[0] = 'x';
	cout << "更改第一个字符：" << str << endl;
}


// string 插入和删除
/*- `string& insert(int pos, const char* s);`		// 插入字符串
- `string& insert(int pos, const string& str);`		// 插入字符串
- `string& insert(int pos, int n, char c);`		// 插入n个字符c
- `string& erase(int pos, int n = npos);`		// 删除从pos开始的n个字符*/
void string_009()
{
	string str = "hello";
	// 插入
	str.insert(0, "Jx ");
	cout << "插入后结果：" << str << endl;
	// 删除
	str.erase(2, 100);
	cout << "删除后结果：" << str << endl;
	//		if 后面npos不写会产生什么效果
	str.erase(0);		// erase() == erase(0)
	cout << "只写起始位置删除：" << str << endl;
	//		会删除pos后面所有的字符
}



// string子串	//substr
/*`string substr(int pos = 0, inte n = npos) const;`		// 返回由pos开始的n个字符组装成的字符串*/
void string_010()
{
	string str = "abcdefg";
	string jx = str.substr(2, 2);
	cout << "获得的子串：" << jx << endl;			//cd
	jx = str.substr(2);
	cout << "只写起始位置参数：" << jx << endl;		//cdefg
}

/*==================================================*/
/*-- 有关字符串的转换问题 --*/
//	字符串大小写转换	
void string_transform001()
{
	string str1 = "Hello World!";
	std::transform(str1.begin(), str1.end(), str1.begin(), tolower);
	cout << str1 << endl;	//hello world!
	std::transform(str1.begin(), str1.end(), str1.begin(), toupper);
	cout << str1 << endl;	//HELLO WORLD!

							
	/*-- Tips: --*/
	//test:前后的begin必须一致，否则error
	cout << endl;
	//std::transform(str1.begin() + 1, str1.end(), str1.begin() + 1, tolower);
	std::transform(str1.begin() + 1, str1.end()-4, str1.begin() + 1, tolower);
	cout << str1 << endl;
}
/*==================================================*/



/*-- 小案例 --*/
//	从邮箱地址中获取用户信息
void stringEg_001()
{
	string email = "zhangsan@sina.cn";
	int endIndex = email.find('@');
	cout << "邮箱用户名为：" << email.substr(0, endIndex) << endl;
}