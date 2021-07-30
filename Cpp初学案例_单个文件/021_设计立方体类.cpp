/*
encoding: GB2312(936)
state:设计立方体类
		求出立方体的面积和体积
		分别用全局函数和成员函数判断两个立方体是否相等
*/

#include <iostream>
using namespace std;

class Cube
{
private:
	int m_l, m_w, m_h;
public:
	// 设置数据
	void setLength(int l, int w, int h)
	{
		m_l = l, m_w = w, m_h = h;
	}
	// 获取数据
	int getLength()
	{
		return m_l;
	}
	int getWidth()
	{
		return m_w;
	}
	int getHeight()
	{
		return m_l;
	}
	// 计算函数
	int getFaceArea()
	{
		return 2 * (m_l * m_w + m_w * m_h + m_h * m_l);
	}
	int getVolume()
	{
		return m_l * m_w * m_h;
	}
	// 成员函数判断是否相等
	bool isSame(Cube& a)
	{
		if (m_l == a.getLength() &&
			m_w == a.getWidth() &&
			m_h == a.getHeight())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool CubeisSame(Cube &a, Cube &b)
{
	if (a.getLength() == b.getLength() &&
		a.getWidth() == b.getWidth() &&
		a.getHeight() == b.getHeight())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Cube c1;
	c1.setLength(10, 20, 30);
	cout << "立方体c1的表面积为：" << c1.getFaceArea() << endl;
	cout << "立方体c1的体积为：" << c1.getVolume() << endl;

	Cube c2;
	c2.setLength(10, 20, 30);
	if (CubeisSame(c1,c2))
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
		cout << "两个立方体不相等" << endl;
	}
	system("pause");
	return 0;
}

