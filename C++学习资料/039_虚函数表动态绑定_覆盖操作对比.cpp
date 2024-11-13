#include <iostream>

using namespace std;

namespace
{
	class Animal
	{
	public:
		virtual void fun1(void)
		{
			cout << "zoo fun1" << endl;
		}

		virtual void fun2(void)
		{
			cout << "zoo fun2" << endl;
		}
	};

	class Cat : public Animal
	{
	public:
		virtual void fun3(void)
		{
			cout << "cat fun3" << endl;
		}

		virtual void fun4(void)
		{
			cout << "cat fun4" << endl;
		}

		
		virtual void fun2(void) override
		{
			cout << "cat fun2" << endl;
		}
	};

	// 下面是非虚函数的对比 无法实现

	class A
	{
	public:
		void awa(void)
		{
			cout << "A awa" << endl;
		}

		void qwq(void)
		{
			cout << "A qwq" << endl;
		}
	};

	class B : public A
	{
	public:
		void awa(void)
		{
			cout << "B awa" << endl;
		}
	};
}

void text_039(void)
{
	// 多态, 要满足动态条件哦
	Animal* p = new Cat();
	p->fun1();				// 访问父类独有可以
	p->fun2();				// 可以访问子类重写的方法 多态

	((Animal*)p)->fun2();
	((Cat*)p)->fun3();		// 类型转换可以访问子类新增方法 (如果是用多态, 那么一般不设计这样用)

	// 对比: 无, 原因: 无法满足多态的条件, 不能使用指针来访问子类, 并且函数覆盖等
	A* a = new A;
	a->awa();

	A* b = new B;
	b->awa(); // 访问的是 A 的方法

	((B*)b)->awa(); // 类型转化才访问的了B
}