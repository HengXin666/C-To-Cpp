#include <iostream>
#include <list>

using namespace std;

static void _putList(list <int> L)
{
	cout << "[info]: ";
	// ---查--- 好像不能用 L[i] || at(i)
	for (auto i = L.begin(); i != L.end(); ++i)
		cout << *i << " ";

	cout << endl;
}

void stl_007(void)
{
	list <int> list = {0};

	// 判断是否为空
	cout << "为: " << (list.empty() ? "空" : "不空") << endl;

	// ---增---
	list.push_front(1);	// 头部添加
	list.push_back(2);	// 尾部添加

	// 指定位置添加
	list.insert(list.begin(), 2, 66);

	// 不能 list.begin() + 1, 但可以 ++list.begin 甚至 ++++++list.begin

	_putList(list);

	// ---删---
	list.pop_front();	// 头部删除
	list.pop_back();	// 尾部删除
	_putList(list);

	list.erase(list.begin(), ++++++list.begin());
	_putList(list);
	cout << "为: " << (list.empty() ? "空" : "不空") << endl;
}