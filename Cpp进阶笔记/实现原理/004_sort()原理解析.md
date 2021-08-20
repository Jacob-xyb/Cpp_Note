# sort()原理解析

## 基本介绍

在很多应用中，排序都是至关重要的，而且很多`STL`算法也只适用于有序对象序列。定义在 algorithm 头文件中的函数模板 `sort<Iter>()` 默认会将元素段排成升序，这也就意味着排序的对象的类型需要支持 `<` 运算符。 

对象也必须是可交换的，这说明可以用定义在 utility 头文件中的函数模板 `swap()` 来对两个对象进行交换。这进一步表明这种对象的类型需要实现移动构造函数和移动赋值运算符。

函数模板 `sort<Iter>()` 的类型参数 Iter 是元素段元素对应的迭代器类型，而且它们必须支持随机访问迭代器。这表明 sort() 算法只能对提供随机访问迭代器的容器中的元素进行排序，也说明 sort() 只能接受 array、vector、deque 或标准数组中的元素。可以回顾前面章节，list 和 forward_list 容器都有成员函数 sort(); 这些用来排序的特殊成员函数是必要的，因为 list 只提供双向迭代器，且 forward_list 只提供正向迭代器。

## 实现原理

- sort有三种排序方式：快排/插排/堆排

STL的sort()算法，定义了一个SORT_MAX变量来进行判断，如果大于SORT_MAX就采用Quick Sort，分段递归排序。一旦分段后的SORT_MAX小于某个阈值，为避免Quick Sort的递归调用带来过大的额外开销，就改用Insertion Sort（插入排序）。如果递归层次过深，还会改用Heap Sort。

快速排序最关键的地方在于枢轴的选择，最坏的情况发生在分割时产生了一个空的区间，这样就完全没有达到分割的效果。STL采用的做法称为median-of-three，即取整个序列的首、尾、中央三个地方的元素，以其中值作为枢轴。

#  快速排序（Quick Sort）

## 基本介绍

快速排序是一种对于冒泡排序的方法的一种改进，简单粗暴，因为一听到这个名字你就知道它存在的意义，就是快，而且效率高！它是处理大数据最快的排序算法之一了。

冒泡排序是将两个相邻元素进行交换，而快速排序在此基础上使用了二分法对数组进行操作，确定一个基数的位置，然后对基数右侧的都是比基数大的数字，而左侧都是比它小的数字，然后再进行递归排序。但快速排序并不是一个稳定的排序的方法，其时间复杂度并不是确定的，其平均排序时间复杂度为O(nlogn)，但当情况特殊时，其最差的时间复杂度为O(n^2)和冒泡排序相同。但是人家就是优秀，在大多数情况下都比平均时间复杂度为 O(n logn) 的排序算法表现要更好。（别问为什么，没说的就是不知道！）

- 《算法艺术与信息学竞赛》

*快速排序的最坏运行情况是 O(n²)，比如说顺序数列的快排。但它的平摊期望时间是 O(nlogn)，且 O(nlogn) 记号中隐含的常数因子很小，比复杂度稳定等于 O(nlogn) 的归并排序要小很多。所以，对绝大多数顺序性较弱的随机数列而言，快速排序总是优于归并排序。*

## 算法步骤

1. 从数列中挑出一个元素，称为 `"基准"（pivot）`;
2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为`分区（partition）`操作；
3. 递归（recursive）地把小于基准值元素的子数列和大于基准值元素的子数列排序；

## 动图演示

![](https://www.runoob.com/wp-content/uploads/2019/03/quickSort.gif)


## 源代码

- 排序一个升序序列时，基准位置基本没有变化，因此是O(n^2)。

### 比较容易写的版本，从前往后排序

```cpp
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
```

### 两边逼近

- 因为某些原因，将分区步骤写在了一起

```cpp
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
```

# 插入排序（Insertion Sort）

## 基本介绍

插入排序(InsertionSort)，一般也被称为直接插入排序。

对于少量元素的排序，它是一个有效的算法。插入排序是一种最简单的排序方法，它的基本思想是将一个记录插入到已经排好序的有序表中，从而一个新的、记录数增 1 的有序表

。在其实现过程使用双层循环，外层循环对除了第一个元素之外的所有元素，内层循环对当前元素前面有序表进行待插入位置查找，并进行移动。

- 复杂度

插入排序的平均时间复杂度也是 **O(n^2)**，空间复杂度为常数阶 **O(1)**，具体时间复杂度和数组的有序性也是有关联的。

插入排序中，当待排序数组是有序时，是最优的情况，只需当前数跟前一个数比较一下就可以了，这时一共需要比较 **N-1** 次，时间复杂度为 **O(N)**。最坏的情况是待排序数组是逆序的，此时需要比较次数最多，最坏的情况是 **O(n^2)**。

## 算法步骤

步骤非常简单，两层循环

第一层循环就是从第二位置开始遍历一遍所有数据；

第二层就将当前数据往前面插入，直到前面的数比自己小为止；

## 源代码

```cpp
void sort_Isort001(vector<int>& a)
{
	if (a.size() < 2) return;
	for (int i = 1; i < a.size(); i++)
	{
		int j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
}
```

# 堆排序（Heap Sort）

# TODO

