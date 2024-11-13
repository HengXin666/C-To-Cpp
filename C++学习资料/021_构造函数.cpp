#include <iostream>

using namespace std;

static class AwA
{
public:
	AwA()		// 构造函数, 在对象声明时候, 会自动调用该函数
				// 该函数没有返回值, 但是参数可变
				// 可以自定义构造函数, 构造函数的名字和类的名字相同 (不自定义编译器也会自动生成并执行)
	{
		cout << "qwq!!" << endl;
	}
				// 这样是函数重载, 如果写了有参数的, 没有写无参数的
				// 那么是无法使用无参数在声明对象的时候
	AwA(string str, int op = 1433223)
	{			// 当然, 函数也是可以设置默认值的
		cout << "awa!!! " << str << endl;
	}
};

void text_021(void)
{
	AwA o_O;
	AwA o_0("WDF");
}