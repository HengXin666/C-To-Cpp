#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

static void _putDeque(deque <int> d)
{
	cout << "[info]: ";
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_006(void)
{
	// 声明
	deque <int> dQ(10);	// 创建一个长度为10个int的双端队列, 因为没有指定数值, 所以默认初始化为 0
	dQ.push_front(1);	// 头部添加
	_putDeque(dQ);
	dQ.pop_front();		// 头部删除
	_putDeque(dQ);		

	dQ.push_back(2);	// 尾部添加
	_putDeque(dQ);
	dQ.pop_back();		// 尾部删除
	_putDeque(dQ);

	dQ.insert(dQ.begin() + 1, 2, 1);	// 指定 迭代器位置, 插入几(2)个, 1
	_putDeque(dQ);

	// 双端队列可以通过索引访问
	cout << dQ[1] << " == " << dQ.at(1) << endl;

	// 访问第一个元素			   // 访问最后一个元素
	cout << dQ.front() << " " << dQ.back() << endl;

	dQ.erase(dQ.begin() + 1, dQ.begin() + 3);	// 生成指定迭代器区间 [a, b) 的内容
	_putDeque(dQ);

	dQ.clear();	// 清除
	_putDeque(dQ);

	dQ = { 1, 2, 5, -1, 3, 3 };

	sort(dQ.begin(), dQ.end());

	for (auto& it : dQ)
		cout << it << " ";


	try
	{
		// at的访问和 [] 一样, 不会检测越界的
		cout << dQ.at(314) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}