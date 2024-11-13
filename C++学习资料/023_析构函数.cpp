#include <iostream>

using namespace std;

static class MyClass
{
public:
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

private:

};

void text_023(void)
{
	MyClass awa;
}