#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		A(string str) : str(str){}

		virtual void putInfo(void)
		{
			cout << "[Info]: " << str << endl;
		}

	protected:
		string str;
	};

	class B : public A
	{
	public:
		B(string name) : A(name){}

		virtual void putInfo(void)
		{
			cout << "[Info]: " << str << endl;
		}

	};
}

void text_037(void)
{
	/*
	*	构成多态的条件:
	*	1. 必须存在继承关系;
	*	2. 继承关系中必须有同名的[虚函数]，并且它们是覆盖关系（函数原型相同(参数的类型、顺序相同)）// 加 virtual 关键字就是虚函数
	*	3. 存在基类的指针，通过该指针调用虚函数。
	* */

	// 指针实现多态
	A* p = new A("大哥");
	p->putInfo();
	delete p;

	p = new B("小老弟");
	p->putInfo();
	delete p;
	// 这里的内存释放并不是正确的似乎,,, 所以只要看多态的代码就好

	// 引用实现多态
	A awa("吖");
	B qwq("砸");

	// 类型是基类类型哦!
	A& p1 = awa;
	A& p2 = qwq;

	p1.putInfo();
	p2.putInfo();
}