/*
案例：敲桌子 by (for 循环)
说明：从1~100，如果数字个位含有7，或者十位含有7，或者是7的倍数就打印敲桌子，其余数字直接打印输出。
*/

#include <iostream>
using namespace std;

int main(){

    for (int i = 1; i < 100; i++){
		if ((i % 10 == 7) or (i / 10 == 7) or (i % 7 ==0)){
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

    system("pause");

    return 0;

}