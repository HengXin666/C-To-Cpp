#include <iostream>
#include <cstdlib>	// 产生随机数
#include <ctime>	// 系统时间

using namespace std;

void text_005(void)
{
	cout << "随机数的最大值是: " << RAND_MAX << endl;
	
	cout << "不使用动态数字作为种子:" << endl;

	srand(666);

	for (int i = 0; i < 5; ++i)
	{
		// 每次启动都是: 13 34 92 52 49
		cout << rand() % 100 << " ";
	}

	cout << endl << "使用系统时间作为种子:" << endl;

	srand(time(NULL));	// 从 1970.1.1 00:00:00 到 当前的秒数

	for (int i = 0; i < 5; ++i)
	{
		cout << rand() % 100 << " ";
	}

	cout << endl << "使用系统时间作为种子, 但是位置错误:" << endl;

	for (int i = 0; i < 5; ++i)
	{
		srand(time(NULL));
		cout << rand() % 100 << " ";
		// 值相同是因为:
		// 每次生成随机数时都重新设置了种子，即在循环内部使用srand(time(NULL))。
		// 由于时间精度太高，循环内部的设置种子操作可能在同一秒内完成，导致生成的随机数序列相同
	}

	// 可以看出, 从启动程序开始, 每次调用 srand(num), 都会依次参数与 num 有关的相同值
}