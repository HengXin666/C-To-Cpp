#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool _find_if_fun(int var)
{
	return var == 9;
}

static bool _count_if_fun(int var)
{
	return var >= 8;
}


class _Find_if_class
{
public:
	// 像这样, 返回bool的仿函数 称为 "谓词"
	bool operator() (int var) const
	{
		return var == 9;
	}
};

void stl_015(void)
{
	vector<int> v = { 1,2,3,4,4,5,6,7,8,9,9,9,9,9,9,9,9,9,9,9,9,-1, };
	
	// ---find---
	// 查找 元素9 返回是迭代器, 失败就返回 .end() 迭代器
	cout << *find(v.begin(), v.end(), 9) << endl;

	// ---find_if--- <自定义查找>
	cout << *find_if(v.begin(), v.end(), _find_if_fun) << endl;
	cout << *find_if(v.begin(), v.end(), _Find_if_class()) << endl;

	// ---adjacent_find--- <查找相邻重复元素>
	cout << *adjacent_find(v.begin(), v.end()) << endl; // 返回第一个出现重复元素的迭代器

	// ---binary_search--- 通过二分查找, 判断区间是否存在该元素 返回bool, 前提是原本区间是有序的!
	cout << binary_search(v.begin(), v.end(), -1) << endl;

	// ---count--- 计数
	cout << "重复数: " << count(v.begin(), v.end(), 9) << endl;

	// ---count_id--- <自定义条件计数>
	cout << count_if(v.begin(), v.end(), _count_if_fun) << endl;
		// 一样的, 函数指针 或者 谓词 均可, 统计满足条件的元素个数
}