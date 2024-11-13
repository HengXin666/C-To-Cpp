#include <iostream>

using namespace std;

namespace
{
	class Zoo
	{
	public:
		Zoo()
		{
			cout << "The Zoo Good" << endl;
		}

		void printInfo(void)
		{

		}
	};

	class Cat
	{
	public:
		Cat()
		{
			cout << "Cat Cat kawaii ~" << endl;
		}

		void printInfo(void)
		{

		}
	};

	// 这样就是[多继承], 可以是继承到不同的位置<属性修饰符>
	class CatInZoo : public Zoo, public Cat	// 构造函数/析构函数的调用顺序是多继承处声明决定的, 和下面这个的顺序无关
	{				// 构造顺序是: Zoo --> Cat (--> CatInZoo) 从左到右 
	public:
		CatInZoo(void) : Cat(), Zoo(){}		// 我就是上面那个的下面那个...
											// Cat(), Zoo() 的顺序不会对构造/析构的顺序产生影响

		void fun(void)
		{
			// <多继承名称冲突解决>
			// 这样调用 基类同名函数不会冲突
			Zoo::printInfo();
			Cat::printInfo();
		}
	};
}

void text_035(void)
{
	CatInZoo awa;
	awa.fun();		// 不报错
}