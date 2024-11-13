#include <iostream>

using namespace std;

static class MyClass
{
public:
	int MC_i, MC_j;
	MyClass(const MyClass& C)	// 赋值构造函数 (自定义的)
	{
		MC_i = C.MC_i;
		MC_j = C.MC_j;
		cout << "拷贝啦!" << endl;
	}

	MyClass(int i, int j)		// 构造函数
	{
		MC_i = i;
		MC_j = j;
	}
};

void text_022(void)
{
	MyClass awa(7, 8);	// 声明对象

	// 拷贝对象
	MyClass qwq(awa);	// C++11 支持的
	MyClass o_0 = qwq;	// 原始的
}