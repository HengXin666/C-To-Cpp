#include <iostream>
#include <set>

using namespace std;

static void _putSet(set<int> s)
{
	cout << "[info]: ";
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_009(void)
{
	// 声明
	set<int> s = { 4,6,7,1,2,2,3 };	// set会自动将元素由小到大排序, 并且不会有重复元素
	_putSet(s);

	// 插入(只能插入一个元素, 并且因为自动排序, 所以没有位置选择)
	s.insert(12);
	_putSet(s);

	// 删除
	s.erase(s.begin());						// 删除迭代器所指位置
	_putSet(s);

	s.erase(++++s.begin(), ----s.end());	// 删除迭代器区间 [a, b)
	_putSet(s);

	s.erase(2);								// 删除 指定值的元素
	_putSet(s);

	// 清空集合
	s.clear();

	// 常用方法
	if (s.empty())	// 判断是否为空
	{
		cout << "为空" << endl;
	}
	else
	{				// 返回集合元素个数
		cout << "长度为: " << s.size() << endl;
	}

	// 查找
	auto p = s.find(3);	// 查找值为3的元素, 并且返回其迭代器, 如果找不到, 那么返回 迭代器s.end()
	if (p != s.end())
	{
		cout << *p << endl;
	}
	else
	{
		cout << "没有找到!" << endl;
	}
}