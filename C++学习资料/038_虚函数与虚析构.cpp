#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		/*~A()
		{
			cout << "call ~A" << endl;
		}*/

		// 请尝试注释下面 虚析构函数 然后运行, 看看有什么效果
		virtual ~A()
		{
			cout << "call virtual ~A" << endl;
		}
	};

	class B :public A
	{
	public:
		~B()
		{
			cout << "call ~B" << endl;
		}
	};
}

void text_038(void)
{
	// 虚函数主要是为了实现多态
	// 加 virtual 关键字就是虚函数

	// 虚析构是为了在 new 子类 在 delete 子类时候, 会调用基类的 析构函数
	// 如下:
	A* p = new B;
	delete p;

	// 可以把A的内存空间看成是苹果, 然后B是苹果籽, 如果delete p
	// 然后如果是在没有这个虚析构函数的情况下, 只是会释放苹果籽,但是苹果还在? --是的
}