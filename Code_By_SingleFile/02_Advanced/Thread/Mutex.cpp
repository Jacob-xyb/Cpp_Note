// need use vs to run

#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

class SeaKing
{
public:
	void makeFriend()
	{
		for (int i = 0; i < 10000; i++)
		{
			// m_mutex.lock();        //加锁
			printf("增加一个女朋友:%d", i);
			mm.push_back(i);
			// m_mutex.unlock();      //解锁
		}
	}
	void breakUp()
	{
		for (int i = 0; i < 10000; i++)
		{
			if (!mm.empty())
			{
				// m_mutex.lock();        //加锁
				printf("分手一个女朋友:%d\n", mm.back());
				mm.pop_back();
				// m_mutex.unlock();      //解锁
			}
			else
			{
				printf("海王变单身狗!\n");
			}
		}
	}
protected:
	list<int> mm;        //共享数据
	mutex m_mutex;				//首先第一步构建一个互斥量对象
};

int main()
{
	SeaKing man;
	thread t1(&SeaKing::makeFriend, &man);  //创建两个线程
	thread t2(&SeaKing::breakUp, &man);
	t1.join();
	t2.join();
	return 0;
}