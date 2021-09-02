// test.h

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>


// º¯ÊýÉùÃ÷
void Class_Jx001();

#define test() Class_Jx001()


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

