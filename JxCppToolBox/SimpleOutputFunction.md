# PrintEverything

## void BinaryRecursion(int n)

递归输出二进制码

```cpp
void BinaryRecursion(int n)
{
	int a = n % 2;
	n >>= 1;
	if (n != 0)
	{
		BinaryRecursion(n);
	}
	std::cout << a;
}
```

## void PrintArrry(arrT arr[], int num, int start = 0, int end = 0, int step = 1)

```cpp
template <typename arrT>
void PrintArrry(arrT arr[], int num, int start = 0, int end = 0, int step = 1);



template <typename arrT>
void PrintArrry(arrT arr[], int num, int start, int end, int step) {
	if (end <= 0) {
		end += num;
	}
	std::cout << "[";
	for (size_t i = start; i < end; i+=step)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "]\n";
}
```

