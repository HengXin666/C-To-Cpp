#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass() {}
	~MyClass() {}
	friend static void _text_029_n(MyClass m);	// 友元函数 关键字: friend
	// 在类里面声明, 在类外面实现(在类里面实现也不是不行), 可以访问 类的全部私有成员变量 和 受保护的成员变量
	
	 friend void awa(MyClass m) {
		 cout << m.n << endl;
		 // cout << this.n << endl;
	 }
private:
	int n;
};

static void _text_029_n(MyClass m)				// 注意形参, 传参
{												// 使用和普通函数没有区别
	m.n = 1;
}

void text_029(void)
{
	MyClass me;
	// me.n = 1;		// 无法访问
	_text_029_n(me);	// 没有报错 <-- 直接使用, 不是 ".方法"
	awa(me);
}