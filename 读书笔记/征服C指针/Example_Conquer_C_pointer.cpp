#include <stdio.h>
#include "../Proj/BookNotes_Head.h"

void exp_1_1_pointer()
{
	int hoge = 5;
	int piyo = 10;
	int* hoge_p;

	/*输出每个变量的地址*/
	printf("&hoge..%p\n", &hoge);		//&hoge..0000003A706FF9D4
	printf("&piyo..%p\n", &piyo);		//&piyo..0000003A706FF9F4
	printf("&hoge_p..%p\n", &hoge_p);	//&hoge_p..0000003A706FFA18

	/*将 hoge 的地址赋予 hoge_p */
	hoge_p = &hoge;
	printf("hoge_p..%p\n", hoge_p);		//hoge_p..0000003A706FF9D4	

	/*通过 hoge_p 输出 hoge 的内容*/
	printf("*hoge_p..%d\n", *hoge_p);	//*hoge_p..5

	/*通过 hoge_p 修改 hoge 的内容*/
	*hoge_p = 10;
	printf("hoge..%d\n", hoge);			//hoge..10
}
void exp_1_2_pointer_calc()
{
	int hoge;
	int* hoge_p;

	/*将指向 hoge 的指针赋予 hoge_p */
	hoge_p = &hoge;
	printf("hoge_p..%p\n", hoge_p);			//hoge_p..000000A1C88FF624
	++hoge_p;
	printf("hoge_p..%p\n", hoge_p);			//hoge_p..000000A1C88FF628
	printf("hoge_p..%p\n", hoge_p + 3);		//hoge_p..000000A1C88FF634
}
void exp_1_4_array2()
{
	int array[5];
	int* p;
	int i;

	for (i = 0; i < 5; i++)
	{
		array[i] = i;
	}

	/*输出数组各元素的值（指针版）*/
	for (p = &array[0]; p != &array[5]; p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
	/*换一种方式输出*/
	p = &array[0];
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
	/*甚至可以这样输出*/
	for (i = 0; i < 5; i++)
	{
		printf("%d ", i[array]);
	}
	printf("\n");
}


