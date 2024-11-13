#include <iostream>
using namespace std;

static class MyClass_ByCpp11_007 {
public:
	// 通过将默认构造函数声明为delete，我们禁用了该类的默认构造函数。这意味着无法通过无参方式创建该类的对象, 下同
	MyClass_ByCpp11_007() = delete;                          // 禁用默认构造函数
	MyClass_ByCpp11_007(const MyClass_ByCpp11_007&) = delete;            // 禁用拷贝构造函数
	MyClass_ByCpp11_007& operator=(const MyClass_ByCpp11_007&) = delete; // 禁用拷贝赋值运算符

	// 将移动构造函数和移动赋值运算符声明为default，我们显式声明了默认的移动操作。
	// 这样做可以确保对象在需要进行移动语义的情况下可以高效地进行资源转移。
	MyClass_ByCpp11_007(MyClass_ByCpp11_007&&) = default;                // 显式声明默认移动构造函数

	~MyClass_ByCpp11_007();
	MyClass_ByCpp11_007& operator=(MyClass_ByCpp11_007&&);
};

MyClass_ByCpp11_007::~MyClass_ByCpp11_007() = default;
MyClass_ByCpp11_007& MyClass_ByCpp11_007::operator=(MyClass_ByCpp11_007&&) = default;     // 显式声明默认移动赋值运算符

void new_cpp11_007(void)
{
	// 见上面啊
}