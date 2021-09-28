// test.h

#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>


// 函数声明
void Class_Polymorphism001();

#define test() Class_Polymorphism001()



// 实用函数
template<typename T>
vector<T> JxTool_GetData(string filePath)
{
    vector<T> Array;
    T temp;
    std::ifstream infile(filePath);
    if (!infile)
    {
        std::cout << "Unable to read file." << std::endl;
        return Array;
    }
    while (!infile.eof())            // 若未到文件结束一直循环
    {
        infile >> temp;
        Array.push_back(temp);
    }
    return Array;
}

//Jx_global
template<typename T>
void printVector(vector<T>& v)
{
    //int n = v.size();
    //for (int i = 0; i < n; i++)
    //{
    //    cout << v[i] << " ";
    //}
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename T>
void printVector(vector<vector<T>>& v)
{
    for (typename vector<vector<T>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (typename vector<T>::iterator jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
    cout << endl;
}

