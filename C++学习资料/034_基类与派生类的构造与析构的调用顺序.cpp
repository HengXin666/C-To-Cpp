#include <iostream>

using namespace std;

static class Zoo
{
public:
	Zoo()
	{
		cout << "{ // Zoo" << endl;
	}

	~Zoo()
	{
		cout << "} // Kill Zoo" << endl;
	}
};

static class Cat:public Zoo
{
public:
	Cat()
	{
		cout << "\t{ // Cat" << endl;
	}

	Cat(string name)
	{
		cout << "\t{ // Cat" << endl;
		cout << "\t\t\t[init]: 君の名は ?" << endl;
	}

	~Cat()
	{
		cout << "\t} // Kill Cat" << endl;
	}
};

static class NbCat :public Cat
{
public:
	NbCat(string name)
	{
		cout << "\t\t{ // NbCat" << endl;
		this->name = name;
		cout << "\t\t\t[init]: 君の名は " << this->name << " です~" << endl;
	}

	NbCat()
	{
		cout << "\t\t{ // NbCat" << endl;
	}

	~NbCat()
	{
		cout << "\t\t} // Kill NbCat" << endl;
	}

	void maimai(void)
	{
		cout << "\t\t\t[NbNeKo]: giao ~ !" << endl;
	}
private:
	string name;
};

static void _text_034(void);
void text_034(void)
{
	// 当一个派生类被实例化为对象时, 会先调用基类的构造函数, 再调用派生类的构造函数
	// 当其结束时候, 会先调用派生类的析构函数, 再调用基类的析构函数, 类似于 递归的<归>
	// 值得注意的是: 调用的基类的函数是默认的构造函数, 如果没有则会报错
	// 当然通过其他方法是可以在没有默认构造函数的情况下, 基类和派生类都可以正常调用带参数的构造函数
	{
		NbCat awa("喵");
		awa.maimai();
	}
	cout << endl;
	_text_034();	// <--- 其他方法
}

// 使用一个匿名命名空间, 这样链接属性也是文件内
namespace {
	class _Zoo {
	public:
		_Zoo(int x) {
			cout << "{ // Zoo" << endl;
		}

		~_Zoo() {
			cout << "} // Kill Zoo" << endl;
		}
	};

	class _Cat : public _Zoo {
	public:
		_Cat(string name) : _Zoo(1) {
			cout << "\t{ // Cat" << endl;
			cout << "\t\t\t[init]: 君の名は " << name << " です~" << endl;
		}

		~_Cat() {
			cout << "\t} // Kill Cat" << endl;
		}

		void maimai() {
			cout << "\t\t\t[NbNeKo]: giao ~ !" << endl;
		}
	};

	class _NbCat : public _Cat {
	public:
		_NbCat(string name) : _Cat(name) {
			cout << "\t\t{ // NbCat" << endl;
			cout << "\t\t\t[init]: 君の名は " << name << " です~" << endl;
		}

		~_NbCat() {
			cout << "\t\t} // Kill NbCat" << endl;
		}
	};
}

static void _text_034(void)
{
	// 这个就是不用默认的构造函数, 也不写 By GPT-3.5
	_NbCat awa("超级喵~");
	awa.maimai();
}