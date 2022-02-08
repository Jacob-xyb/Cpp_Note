#include <fstream>
#include <sstream> 
#include "../Jx_进阶案例.h"

//
////简单获取数据
//template<typename T>
//vector<T> JxTool_GetData(string filePath)
//{
//    vector<T> Array;
//    T temp;
//    std::ifstream infile(filePath);
//    if (!infile)
//    {
//        std::cout << "Unable to read file." << std::endl;
//        return Array;
//    }
//    while (!infile.eof())            // 若未到文件结束一直循环
//    {
//        infile >> temp;
//        Array.push_back(temp);
//    }
//    return Array;
//}

/*-- 简易读取txt文件 --*/
void read_txt_001(std::string& path, std::vector<double>& data)
{
	std::ifstream ifs;
	ifs.open(path, std::ios::in);
	double temp;
	while (ifs >> temp)
	{
		data.push_back(temp);
	}
	ifs.close();
}

void call_read_txt_001()
{
	std::string path = "D:\\1.company\\GitLab\\DA_Test\\Test-DA-Jx-Proj\\nk.txt";
	std::vector<double> data;
	read_txt_001(path, data);
	for (size_t i = 0; i < data.size(); i+=3)
	{
		std::cout << data[i] << "\t" << data[i + 1] << "\t" << data[i + 2] << std::endl;
	}
}

/*-- 简易读写教程 --*/
void Jx_IOStream_001()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ofstream ofs;
	//3.指定打开方式
	ofs.open("test.txt", ios::out);		//没写权限好像也不会有啥问题
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "姓名：李四" << endl;
	ofs << "姓名：王五" << endl;
	//5.关闭文件
	ofs.close();
}
void Jx_IOStream_002()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ifstream ifs;
	//3.打开文件 并且判断是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }
	//4.读数据
	/*第一种*/
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	/*第二种*/
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	/*第三种*/
	/*string line;
	while (getline(ifs,line))
	{
		cout << line << endl;
	}*/
	/*第四种*/
	//不推荐
	char c;
	while ( (c = ifs.get()) != EOF )	// EOF
	{
		cout << c;
	}
	//5.关闭文件
	ifs.close();
}
//二进制文件 写文件
class Person
{
public:
	char m_Name[64];	//姓名
	int m_Age;			//年龄
};
void Jx_IOStream_003()
{
	ofstream ofs;
	ofs.open("Person.txt", ios::out | ios::binary);
	Person p = { "张三",18 };
	ofs.write( (const char *)&p, sizeof(p));
	ofs.close();
}
//二进制文件 读文件
void Jx_IOStream_004()
{
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }
	Person p;
	ifs.read((char*)&p, sizeof(p));
	ifs.close();
	cout << p.m_Name << endl;
	cout << p.m_Age << endl;
}

void Jx_read_csv(string fileName)
{
	vector<double> data;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }
	string line;
	int num = 0;
	while (getline(ifs, line))
	{
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		string field;
		if (num == 0)
		{
			++num;
			continue;
		}
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			double temp;
			temp = stod(field);
			data.push_back(temp); //将刚刚读取的字符串添加到向量fields中
		}
		++num;
	}
	ifs.close();

	cout << data.size() << endl;
}

template<typename T_>
void Jx_ReadTxt(std::string& path, std::vector<T_>& data)
{
	std::ifstream ifs;
	ifs.open(path, std::ios::in);
	if (!ifs.is_open()) { std::cout << "文件打开失败" << std::endl; return; }
	T_ temp;
	while (ifs >> temp)
	{
		data.push_back(temp);
	}
	ifs.close();
}