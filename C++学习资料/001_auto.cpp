#include <iostream>
#include <vector>

using namespace std;

// 充当函数返回值
static auto sum(int a, int b)
{
	return a + b;
}

static class Demo
{
public:
	//auto a = 1; 错误的
	//static auto a = 1; 错误的
	static const auto a = 1;
};


void new_cpp11_001(void)
{
	// 1. auto代替迭代器
	vector<int> arr = { 1,2,3,4,5 };
	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;
	}

	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;
	}

	// 2. 类型推导, 注意 const 与 auto, 有&则有const
	// 3. 半个类型

	// 不用用于模版
	//vector<auto> awa = { 1,2,3,4 };

	// 不能推导为数组类型, 这个推导是指针
	int array[] = { 1,2,3,4 };
	auto list = array;
	auto op = array[2];
}