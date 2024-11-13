#include <iostream>
#include <map>

using namespace std;

static void _putMultimap(multimap<int, int>& m)
{
	cout << "{ ";
	for (auto& it : m)
	{
		cout << "{ " << it.first << " : " << it.second << " }, ";
	}
	cout << "\b\b };" << endl;
}

void stl_013(void)
{
	// ---声明---
	multimap<int, int> m1 = { {1, 11}, {2, 22} , {3, 33} };

	multimap<int, int> m2(m1);	// 默认构造函数
	multimap<int, int> m3 = m1; // 重载运算符(=)
	
	_putMultimap(m1);

	// ---插入---(只展示常用的)
	m1.insert(make_pair(6, 616));
	m1.insert(make_pair(6, 626));
	m1.insert(make_pair(6, 636));
	m1.insert(make_pair(6, 646));
	m1.insert(make_pair(6, 656));
	m1.insert(make_pair(6, 666));
	m1.insert(make_pair(7, 77));
	m1.insert(make_pair(7, 77));
	_putMultimap(m1);

	// ---删除---
	m1.erase(1);				// 删除键
	_putMultimap(m1);

	m1.erase(--m1.end());		// 删除迭代器
	_putMultimap(m1);

	auto pos = m1.find(6);		// 删除迭代器区间
	m1.erase(m1.begin(), pos);
	_putMultimap(m1);

	// ---常用---
	if (m1.empty())
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "非空" << endl;
	}
	cout << "size:" << m1.size() << endl;

	// 清空, 交换 略了

	// 输出有多少个数量(同一个键)
	cout << m1.count(6) << endl;;

	// ---multi系列---
	auto p1 = m1.lower_bound(6);	// 查找大于等于 key 的内容
	auto p2 = m1.upper_bound(6);	// 查找大于 key 的内容
	cout << (*p1).first << " " << (*p1).second << endl;
	cout << (*p2).first << " " << (*p2).second << endl;

	// 查找出所有键是 key 的内容, 返回是一个 迭代器区间 结构体 [, )的
	auto range = m1.equal_range(6);
	for (auto i = range.first; i != range.second; ++i)
	{
		cout << "{ " << (*i).first << " : " << (*i).second << " }, ";
	}
}