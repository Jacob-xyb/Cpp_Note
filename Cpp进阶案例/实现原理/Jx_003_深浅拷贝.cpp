#include "../Jx_进阶案例.h"

// = 数组赋值是深拷贝还是浅拷贝
//	猜测是深拷贝	// 事实证明 = 操作符是深拷贝
void copy_Jx001()
{
	vector<int> vec_v1{ 1,2,3,4,5,6 };
	vector<int> vec_v2;
	vec_v2 = vec_v1;
	for (int i = 0; i < vec_v2.size(); i++)
	{
		vec_v2[i] ++;
		cout << vec_v1[i] << " ";
	}
	cout << endl;
}