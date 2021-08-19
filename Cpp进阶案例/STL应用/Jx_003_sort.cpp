#include "../Jx_进阶案例.h"

void sort_Jxtest001()
{
	vector<int> vec_v1{ 6,8,2,9,1,5 };
	sort(vec_v1.begin(), vec_v1.end());
	for (int i = 0; i < vec_v1.size(); i++) cout << vec_v1[i] << " ";
	cout << endl;
}

//==================================================
//实现原理
//	sort有三种排序方式：快排/堆排/插排
/*STL的sort()算法，定义了一个SORT_MAX变量来进行判断，如果大于SORT_MAX就采用Quick Sort，分段递归排序。一旦分段后的SORT_MAX小于某个阈值，为避免Quick Sort的递归调用带来过大的额外开销，就改用Insertion Sort（插入排序）。如果递归层次过深，还会改用Heap Sort。
* 
快速排序最关键的地方在于枢轴的选择，最坏的情况发生在分割时产生了一个空的区间，这样就完全没有达到分割的效果。STL采用的做法称为median-of-three，即取整个序列的首、尾、中央三个地方的元素，以其中值作为枢轴。
*/

//	快速排序（Quick Sort） 
void sort_Qsort001(vector<int>& a, int L,int H)
{
	//基本结束条件	//L >= H 就结束
	if (L < H)
	{
		//对当前序列排序
		//	定基准
		int pivot = a[L];
		//	划分区间
		int privotIndex = L;	//创建基准标签
		for (int i = L+1; i <= H; i++)
		{
			if (a[i] < pivot)
			{
				if (i - privotIndex == 1)
				{
					privotIndex++;
					continue;
				}
				privotIndex++;
				int temp = a[privotIndex];
				a[privotIndex] = a[i];
				a[i] = temp;
			}
		}
		//	将基准数放置基准位上
		a[L] = a[privotIndex];
		a[privotIndex] = pivot;

		//缩小范围
		sort_Qsort001(a, L, privotIndex - 1);
		sort_Qsort001(a, privotIndex + 1,H);
	}
}

//		两边逼近的方法
void sort_Qsort002(vector<int>& a, int L, int H)
{
	//基本结束条件
	if (L < H)
	{
		// 提取出基准
		int pivot = a[L];
		int lIndex = L;
		int hIndex = H;

		while(lIndex < hIndex)
		{
			//从H向左，直到遇到比pivot小的
			while (lIndex < hIndex && !(a[hIndex] < pivot))
			{
				hIndex--;
			}
			a[lIndex] = a[hIndex];
			//从L向右，直到遇见比pivot大的
			while (lIndex < hIndex && !(a[lIndex] > pivot))
			{
				lIndex++;
			}
			a[hIndex] = a[lIndex];
		}
		//此时lIndex == hIndex
		//	将基准数放置基准位上
		a[lIndex] = pivot;

		//缩小范围
		sort_Qsort002(a, L, lIndex - 1);
		sort_Qsort002(a, lIndex + 1, H);
	}
}

//		成功 很nice
void sort_Qsort_test()
{
	vector<int> vec_v1{ 20,40,10,70,10,30 };
	//sort_Qsort001(vec_v1, 0, vec_v1.size() - 1);
	sort_Qsort002(vec_v1, 0, vec_v1.size() - 1);
	for (int i = 0; i < vec_v1.size(); i++)
	{
		cout << vec_v1[i] << " ";
	}
	cout << endl;
}

//	插入排序（Insertion Sort）
void sort_Isort001(vector<int>& a)
{
	if (a.size() < 2) return;
	for (int i = 1; i < a.size(); i++)
	{
		while (true)
		{

		}
	}
}
//==================================================