#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass(){}
	~MyClass(){}
	void get_int(int n)
	{
		this->n = n;		// this 指针可以解决 形参与成员变量名相同问题
	}

private:
	int n;					// n 私有成员变量, 只能在类里面使用, 不能在类外面通过 对象.n = xxx; 赋值修改
};

void text_028(void)
{
	/*	<< C++ this指针的本质 >> By 01
	* this实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给this。
	* 不过this这个形参是隐式的，它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中。
	* 
	* this作为隐式形参，本质上是成员函数的局部变量，
	* 所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给this赋值。
	* 
	* this是const指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
	* 
	* this只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
	* 只有当对象被创建后this才有意义，因此不能在static成员函数中使用。
	* */

	MyClass me;
	me.get_int(123);

	/* << this的应用场景与注意事项 >> By GPT-3.5
	* this 指针在 C++ 中有许多应用场景，以下是一些常见的使用情况和注意事项：
	*
	* 明确指代当前对象：通过 this 指针可以明确引用当前对象，避免与局部变量或参数发生命名冲突。
	*
	* 在成员函数中访问成员变量：使用 this-> 可以显式地访问当前对象的成员变量，即使成员变量与函数参数同名也不会产生歧义。
	*
	* 返回当前对象的引用：在链式编程中，可以将 this 指针作为返回值，以便连续调用当前对象的成员函数。
	*
	* 在构造函数和析构函数中使用：在构造函数和析构函数中，可以使用 this 指针对当前对象进行操作和初始化。
	*
	* 传递给其他函数：在需要将当前对象作为参数传递给其他函数时，可以使用 this 指针将当前对象传递给目标函数。
	*
	* 注意事项：
	*
	* this 指针只能在非静态成员函数中使用，因为静态成员函数不依赖于具体对象的实例。
	*
	* 在构造函数中使用 this 指针要谨慎，因为在对象尚未完全构造完成之前，使用 this 指针可能导致不确定的结果。
	*
	* 避免在成员函数中返回局部变量的指针或引用，因为该指针或引用可能会在成员函数结束后失效。
	* 如果需要返回当前对象的引用，可以使用 *this 来返回对象自身的引用。
	*
	* 在多线程环境下，要注意使用 this 指针的线程安全性，确保多个线程对同一对象的操作不会导致竞态条件。
	*
	* 总而言之，this 指针在面向对象编程中起着重要的作用，它提供了对当前对象的隐式引用。
	* 正确使用 this 指针可以增加代码的清晰度和可读性，但也需要注意它的使用限制和潜在的问题。
	* */
}