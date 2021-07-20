/*
案例：猜数字游戏 by while循环
游戏规则：随机生成一个 1~100 的整数，猜对即可。

额外要求：
1.增加了玩家猜测的次数显示；
*/

#include <iostream>
using namespace std;
#include <ctime>  // 导入时间模块



int main() {

	srand((unsigned int)time(NULL));  // 根据时间生成一个随机数就是一个 真随机数，不然 rand()只会是一个 伪随机数。
	int num = rand() % 100 + 1;
	int times = 1;
	int ans = 0;
	while (true)
	{
		cout << "第" << times++ << "次尝试" << endl;	// 记录猜测次数
		cout << "输入猜测的数字(1~100)： " << endl;
		cin >> ans;

		if (ans == num)
		{
			cout << "恭喜你猜对了！" << endl;
			break;
		}
		else if (ans > num)
		{
			cout << "你猜大了..." << endl;
		}
		else
		{
			cout << "你猜小了..." << endl;
		}

		cout << endl;
	}

	system("pause");

	return 0;
}
