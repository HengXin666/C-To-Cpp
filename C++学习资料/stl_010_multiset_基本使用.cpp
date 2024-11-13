#include <iostream>
#include <set>	// 注意头文件

using namespace std;

static void _putMultiset(multiset<int> m)
{
	cout << "[info]: ";
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_010(void)
{
	// 声明
	multiset <int> set = { 1, 4, 5, 7, 7, 2, 3, 3 };
	_putMultiset(set);


	// 添加 (实际上不用理会在哪里添加, 毕竟集合会自动排序)
	set.insert(123);
	_putMultiset(set);

	// 插入一段数据
	multiset <int> set_2 = { 0, 7, 2, 1, 233 };
	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);

	// 清空集合
	set.clear();

	// 常用方法
	if (set.empty())	// 判断是否为空
	{
		cout << "为空" << endl;
	}
	else
	{				// 返回集合元素个数
		cout << "长度为: " << set.size() << endl;
	}

	// 查找
	auto p = set.find(3);	// 查找值为3的元素, 并且返回其迭代器, 如果找不到, 那么返回 迭代器s.end()
	if (p != set.end())
	{
		cout << *p << endl;
	}
	else
	{
		cout << "没有找到!" << endl;
	}

	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);

	// 统计位置
	int pos = 0;
	for (auto i = set.begin(); i != set.find(2); ++i, ++pos)
		;
	cout << "2所在位置索引是: " << pos << endl;

	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);
	// 其他常用的
	// 统计元素个数
	cout << "3有 " << set.count(3) << " 个, 0 有 " << set.count(0) << " 个" << endl;

	// 其他: 返回一个最近的符合条件的数
	cout << "大于等于2的数是 " << *set.lower_bound(2) << endl;

	cout << "大于2的数是 " << *set.upper_bound(2) << endl;
}