#include <iostream>
#include <utility>

using namespace std;

std::pair<const char*, int> _demo_get(int a, const char* b)
{
	return make_pair(b, a);
}

void stl_011(void)
{
	// 声明
	pair<int, const char*> p(123, "啊?");

	// 访问
	cout << p.first << " " << p.second << endl;

	// 因为本质上是结构体, 不是类, 所以没有什么函数
	p = make_pair(456, "这...");
	cout << p.first << " " << p.second << endl;

	// 如果是函数返回值, 可以使用stl::tie接受
	int ages;
	const char* name;
	std::tie(name, ages) = _demo_get(p.first, p.second);
}