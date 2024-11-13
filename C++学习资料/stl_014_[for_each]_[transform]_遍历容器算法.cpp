#include <iostream>
#include <vector>
#include <algorithm> // !!!

using namespace std;

// 普通函数
static void _print(int var)
{
	cout << var << " ";
}

static int _copy(int var)
{
	return var * var;
}

// 仿函数
static class _Print
{
public:

	// 重载了(), const说明我们不会改变传入的内容
	void operator() (int var) const
	{
		cout << var << " ";
	}
};

static class _Copy
{
public:

	// 重载了(), const说明我们不会改变传入的内容
	int operator() (int var) const
	{
		return var >> 1;
	}
};

void stl_014(void)
{
	vector<int> v = { 4,3,2,1,3,4,7 };

	// --- for_each --- <自定义打印>
	cout << "函数指针: ";
	for_each(v.begin(), v.end(), _print);
	cout << endl << "仿函数: ";
	for_each(v.begin(), v.end(), _Print());
	cout << endl;
	
	// --- transform --- <自定义拷贝>

	vector<int> w;		// 目标容器
	w.resize(v.size());	// 目标容器需要提前开辟空间, 会把 目标容器的原内容直接覆盖, 所以需要开辟空间才可以覆盖
	transform(v.begin(), v.end(), w.begin(), _copy);
	for_each(w.begin(), w.end(), _print);
	cout << endl;
	transform(v.begin(), v.end(), w.begin(), _Copy());
	for_each(w.begin(), w.end(), _print);
}