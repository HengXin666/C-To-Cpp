#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass(string str)
	{
		cout << str << endl;
	}

	MyClass()
	{
		cout << "声明对象" << endl;
	}

	// 在 析构函数名前面加上~符号, 那么这个函数就是析构函数
	// 即当对象被释放的时候, 会自动执行
	// 析构函数没有 返回值 和 参数!
	~MyClass()
	{
		cout << "释放对象" << endl;
	}
};

void text_024(void)
{
	// 只能作用于指针
	// 本质上是 malloc 与 free 的封装
	{
		MyClass* p = new MyClass;
		// 出了作用域, 会自动消失, 但是不会自动执行delete !
		// 同样也就不会执行析构函数了

		// 注意: p 是一个可以操作隐式内存空间的变量,
		// 出了作用域, 只是p消失了, 但是 p 指向的空间没有消失!!!

		// 相当于 钥匙不见了, 门还在!!! (内存泄漏)

		// 故 new 与 delete 要成对使用!!!
	}
	MyClass* q = new MyClass();

	{
		int* p = new int[10];	// 创建长度为10的数组
		delete[] p;				// 释放数组也要是加 [], 不然可能只释放一个
	}
	{
		MyClass* p = new MyClass[5];
		delete[] p;
	}

	delete q;

	MyClass awa[2] = { {"awa!!!"}, {"awa..."} };	// 栈上声明类可以初始化参数
													// 但是堆(new/malloc)上申请, 只能使用默认的构造函数
}