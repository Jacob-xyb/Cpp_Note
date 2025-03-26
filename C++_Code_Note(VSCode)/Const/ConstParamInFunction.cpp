/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-19 15:25:49
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-19 16:19:18
 * @Description: Life is struggle.
 */

#include <iostream>
#include <vector>

using namespace std;

void print(const int& num = 0) {
    cout << "The value of num is " << num << endl;
}

void print_vec(const vector<int>& data = {1, 2, 3})
{
    cout << "The size of data is " << data.size() << endl;
}

int main() {
    print_vec();
    
    return 0;
}