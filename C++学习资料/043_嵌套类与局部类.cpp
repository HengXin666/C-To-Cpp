#include <iostream>

using namespace std;

namespace
{
	class WaiBuClass
	{
	public:
		class ClassClass	// 在类内部定义的类叫做嵌套类(内部类)
							// 一般嵌套类是为了给外部类自己使用的, 不提供给外界
		{
		public:
			void func(void);
		public:
			int b;			// 内部类是不能访问外部类的变量的
		};

		void func(void);
	public:
		int a;
	};

	void WaiBuClass::ClassClass::func(void)	// 可以在外部实现
	{
		cout << "这个就是嵌套类" << endl;
		// b = a; // 报错, 不能访问
		b = 1;
	}

	void WaiBuClass::func(void)
	{
		cout << "这个是外部类" << endl;
		a = 2;
	}
}

static void _text_043_class(void)
{
	class JuBuClass	// 局部类, 定义在函数里面, 作用域在函数里面, 而不是整个文件(全局作用域)
	{
	public:
		void func(void)
		{
			cout << "这个是局部类" << endl;
		}

		static void funawa(void)	// 可以定义静态成员函数, 但是要注意作用域, 不能访问类的任何变量
									// 因为不能访问非静态成员变量, 能访问静态成员变量, 但静态成员变量又不能定义
		// [!] 但是, 它可以实现像Python一样在函数里面定义子函数, 只需要通过 "类名::函数名(参数列表)" 的方式访问即可
		{
			cout << "达咩" << endl;
		}

		//static int a; // 不能声明静态成员变量 <报错>
	};

	JuBuClass awa;
	awa.func();
	JuBuClass::funawa();
}

//void JuBuClass::func(void)	// 局部类不能在类外实现函数 <报错>
//{
//	;
//}

static auto _text_043_class_()
{
	class CCClass {
	public:
		void awa() {
			cout << "The CCClass!" << endl;
		}
	};

	return CCClass(); // 可以作为返回值!!!
}

void text_043(void)
{
	WaiBuClass w;
	w.func();
	cout << endl;
	// 外界如果要访问内部类, 只能指名道姓:
	WaiBuClass::ClassClass cc;
	cc.func();
	cout << endl;
	// 局部类
	_text_043_class();

	auto x = _text_043_class_();
	x.awa();
}