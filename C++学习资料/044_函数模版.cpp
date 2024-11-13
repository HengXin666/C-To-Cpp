#include <iostream>

using namespace std;

template <typename T, class H>// 这两个关键字都可以
static T _text_044_add(T& a, H& b)
{
	return a + b;
}

void text_044(void)
{
	// 函数模版本质上是编译器自动的函数重载, 只不过是隐式的
	// 类型不一定智能, 比如下面不会返回浮点型, 而是按照上面的顺序哦~
	int a = 4.1;
	double b = 5.1;
	cout << _text_044_add(a, b) << endl;
}