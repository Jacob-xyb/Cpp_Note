#pragma once
namespace SingleSmallCase
{
	/*
	案例：猜数字游戏 by while循环
	游戏规则：随机生成一个 1~100 的整数，猜对即可。
	额外要求：
	1.增加了玩家猜测的次数显示；
	*/
	void NumberGuessingGame();

	/*
	案例：找寻水仙花数字 by (do ... while ...)
	说明：水仙花数字：一个3位数，每个位上的数字的3次幂之和等于它本身。
	规则：用do while 求出所有3位数中的水仙花数。
	*/
	void DaffodilNumber();

	/*
	案例：冒泡排序
	说明：给一个数组，冒泡排序并依次输出。
	流程：
	1.比较相邻的元素。如果第一个比第二个大，就交换他们两个；
	2.对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值；
	3.重复以上的步骤，每次比较次数-1，直到不需要比较。
	*/
	void BubbleSort(int* arr, int num);
};

