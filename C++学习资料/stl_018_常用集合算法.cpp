#include <iostream>
#include <vector>
#include <algorithm> // 常用集合算法

using namespace std;

void stl_018(void)
{
	vector<int> v1 = { 1, 2, 3, 7 },
				v2 = { 2, 4, 6 },
				v3;

	// 交 (且)
	{
		// --- 将两个容器的[交集]存储至新容器，并返回交集中最后1个元素的迭代器位置 set_intersection() ---
		// v1 ∩ v2 --> v3
		v3.resize(min(v1.size(), v2.size()));	// 注意新容器需要提前开辟空间

		// 注意为什么返回是迭代器, 而不是直接end()即可, 因为开辟的空间有没有用上的, 为 init_var = 0
		auto pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		// 参数 待交集合 A B 的区间, 以及结果存放集合 C 的开始位置

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}

	// 并 (+)
	{
		// --- 将两个容器的并集存储至新容器，并返回并集中最后1个元素的迭代器位置 set_union() ---
		// v1 ∪ v2 --> v3
		v3.resize(v1.size() + v2.size());

		auto pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}

	// 差 (-)
	{
		// --- 将两个容器的差集存储至新容器，并返回差集中最后1个元素的迭代器位置 set_difference() ---
		// A - B --> C
		// [!]注意: 参数先后决定了结果! A - B != B - A
		v3.resize(max(v1.size(), v2.size()));	// MAX 是因为最差情况是 A 与 B 根本就没有元素相同

		auto pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		
		// ******************* 注意 减 与 被减 *******************

		pos = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}
}