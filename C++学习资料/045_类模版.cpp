#include <iostream>

using namespace std;

namespace
{
	template <typename T, class H>
	class MyClass
	{
	public:
		void printT(T p);

		void putH(H p)	// 在类内实现就不需要
		{
			cout << "[putH]: p == " << p << endl;
		}

		T a;
	};

	// 在类外实现方法, 需要像下面这样
	template <typename T, class H>	// 模版
	void MyClass<T, H>::printT(T p)	// 类也要记得跟上 "<>参数列表"
	{
		cout << "[printT]: p == " << p << endl;
	}
}

typedef MyClass<int, char> M;

// 好像 template 要写在函数外面, 是的!
template <typename T, class H>
using t = MyClass<int, char>;

void text_045(void)
{
	MyClass<int, char> a;	// 类的实例化也要跟上 "<>参数列表"
	a.putH('G');
	a.printT(1433223);

	// 模版别名
	M b; // 通俗易懂, 但是多个这样的别名过几天就会忘记了...

	// 所以有using的别名

	t<int, double> t1;	// 这里的<>列表就不重要了, 必需要看using t处的才是对的 ?
						// 除非 using t = MyClass<T, H>;
	t1.printT(123);
	t1.putH('A');
}