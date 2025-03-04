/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-04 16:32:57
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-04 16:37:20
 * @Description: Life is struggle.
 */

#include <iostream>

using namespace std;

class Point
{
public:
    Point(int x, int y) : m_x(x), m_y(y) {}

    // 常量成员函数，不会修改任何成员变量
    void print() const
    {
        std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
    }

private:
    int m_x, m_y;
};

int main()
{
    const Point p(1, 2);
    p.print(); // 正确：print是一个常量成员函数，可以在常量对象上调用
    return 0;
}
