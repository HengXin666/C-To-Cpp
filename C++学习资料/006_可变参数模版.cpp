#include <iostream>
using namespace std;

static void _006_put(void)
{
	cout << endl;
}

template <class... T>
static void _006_putSizeof(T... t)
{
	cout << "[]: " << sizeof...(t) << endl; // 固定语法格式计算获取到模板参数的个数
	cout << "[]: " << sizeof...(T) << endl; // 注意sizeof...只能计算...的可变参
}

template <class L, class... T>
static void _006_put(L l, T... t)
{
	cout << l << " ";
	_006_put(t...);
}


void new_cpp11_006(void)
{
	_006_putSizeof(1, 2, 3, 4);

	_006_put(1, 2, 3, 4, "王德发", 0.721);
}