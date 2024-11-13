#include <iostream>
#include <stack>

using namespace std;

static void _demo_(void)
{
	// 将内容转化为16进制
	int n;
	cin >> n;
	stack <char> s;
	while (n)
	{
		s.push(n % 16);
		n /= 16;
	}

	while (!s.empty())
	{
		cout << (s.top() >= 10 ? char('A' - 10 + s.top()) : char(s.top() + '0'));
		s.pop();
	}
}

void stl_004(void)
{
	// 声明栈, 和其他的一样使用构造函数
	stack <int> s({ 1, 2, 3, 4 });


	// 栈的操作
	cout << s.top() << endl;	// 返回栈顶元素 (不删除)

	s.push(1433223);			// 在栈顶添加元素 [入栈]
	cout << s.top() << endl;

	s.pop();					// 删除栈顶元素
	cout << s.top() << endl;	// 打印需要使用 top

	// 栈的判断
	cout << "栈是否为空: " << s.empty() << endl;			// 判断栈是否为空, 1是空, 0非空

	cout << "栈的长度(元素个数): " << s.size() << endl;	// 栈的元素个数

	_demo_();
}