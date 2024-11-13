#include <iostream>
#include <vector>

using namespace std;

static void _print(vector<int> v)
{
	cout << "[info]: ";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_003(void)
{
	vector <int> v({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	_print(v);

	// --- 删除元素 ---
	v.erase(v.begin() + 1);				// 删除迭代器指向的元素
	_print(v);

	v.erase(v.end() - 4, v.end() - 1);	// 删除从迭代器 [a, b) 之间的元素
	_print(v);

	v.pop_back();						// 删除末尾的元素
	_print(v);

	v.clear();							// 清空向量的元素
	_print(v);

	// --- 判断函数 ---
	cout << v.empty() << endl;			// 判断向量是否为空, 如果为空则返回1, 否则0

	// --- 大小函数 ---
	// 容器的size是指它已经保存的元素的数目；而capacity则是在不分配新的内存空间的前提下它最多可以保存多少元素。
	cout << v.size() << endl;			// 返回[当前]向量的元素个数
	cout << v.capacity() << endl;		// 返回[在不分配空间的情况下]向量可以容纳的元素个数
	cout << v.max_size() << endl;		// 返回当前向量可以容纳的最大元素个数

	// -- 其他函数 ---
	vector <int> v1({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	v.swap(v1);	// 交换两个向量的值
	_print(v);
	_print(v1);

	v1 = v;

	v.assign(3, 2233);	// 设置前 3 个 元素的值为 2233
	_print(v);			// 注意是 [设置] 不是添加/插入, 是清除了其他了

	v1.assign(v1.begin() + 1, v1.begin() + 2);	// 将向量内容 [设置] 为迭代器 [v1.begin() + 1, v1.begin() + 2) 的内容
	_print(v1);
}