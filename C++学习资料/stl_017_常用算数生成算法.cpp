#include <iostream>
#include <vector>
#include <numeric> // 常用算数生成算法 头文件

using namespace std;

void stl_017(void)
{
	vector<int> v;
	for (int i = 1; i <= 100; ++i)
	{
		v.push_back(i);
	}

	// --- accumulate 对容器的迭代器区间指定加数再求和 ---
	int a = 0;
	cout << "求和 + a:" << a << " = " << accumulate(v.begin(), v.end(), a) << endl;

	// --- fill 对容器的迭代器区间进行值填充
	vector<int> arr;

	// 注意需要预先分配空间, 因为没有分配迭代器是这样的 [a, a) 大概
	// 不然达不到目的
	arr.resize(10);
	fill(arr.begin(), arr.end(), 100);

	for (auto it : arr)
	{
		cout << it << " ";
	}
}