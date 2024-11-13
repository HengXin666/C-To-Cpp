#include <iostream>

using namespace std;

static class HengXin
{
public:
	int arg;
	string name;

	static string xp;		// 使用 static 关键字 定义一个静态成员

	static void loli(void)	// 使用 static 关键字 定义一个静态函数
	{
		cout << xp << endl;	// 静态函数只能访问静态成员变量
	}

	HengXin()
	{
		cout << "声明成员!" << endl;
	}

	HengXin(string _name, int _arg)
	{
		name = _name;	// 这个形参变量名不能和类成员一样
		arg = _arg;		// 不然就都是形参的了, (作用域覆盖)
		cout << "声明成员并且初始化!" << endl;
	}

	~HengXin()
	{
		cout << "成员释放!" << endl;
	}

	void print_name(string name, int arg)
	{
		cout << name << " " << arg << "岁啦~" << endl;
	}

	void print_name(void)
	{
		cout << name << " " << arg << "岁啦~" << endl;
	}
};

string HengXin::xp = "萝莉";	// 在全局作用域中对静态变量进行改变, 需要在前面加上类型

/*	为什么函数外,即全局作用域又需要标注类型?
* 在全局作用域中声明并定义静态成员变量时，需要显式标注变量的类型，是因为全局作用域没有类的定义来指明变量的类型。
*
* 在全局作用域中，静态成员变量实际上是属于类的，但它是在类外部进行声明和定义的。
* 因此，在全局作用域中，编译器无法根据类定义来自动推断静态成员变量的类型，需要通过显式标注类型来告知编译器。
*
* 由于全局作用域中的静态成员变量不直接属于任何特定的对象，而是与类关联，并且可以在类的任何实例之间共享。
* 因此，在全局作用域中声明和定义静态成员变量时，需要以类名作为限定符，确切地指明要声明的是哪个类的静态成员变量。
* */

/*
* 静态成员函数也是该类共享的函数。静态成员函数属于类本身，而不是类的实例对象。它们可以直接通过类名调用，无需创建对象实例。
* 因此，静态成员函数不依赖于具体的对象，可以在没有对象的情况下被调用。
*
* 静态成员函数通常用于处理与类相关的操作，例如访问静态成员变量、执行静态方法等。
* 静态成员函数的特点是在调用的时候不需要创建对象实例，可以通过类名直接调用，例如 ClassName::staticFunction()。
*
* 需要注意的是，静态成员函数内部不能直接访问非静态成员变量和非静态成员函数，因为它们与具体的对象相关联。
* 但是，静态成员函数可以访问静态成员变量和其他静态成员函数，因为它们都属于类本身，在内存中只有一份拷贝。
* 
* 总结来说，静态成员函数是属于类的函数，不依赖于具体的对象实例，可以通过类名直接调用，并且可以访问静态成员变量和其他静态成员函数。
* */

void text_026(void)
{
	HengXin::loli();
	// 静态成员变量是全部该类的对象共享的
	HengXin::xp = "萝莉控";		// 可以通过类名进行访问
	HengXin::loli();
}