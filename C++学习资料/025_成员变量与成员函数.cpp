#include <iostream>

using namespace std;

static class HengXin
{
public:
	int arg;
	string name;

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

void text_025(void)
{
	HengXin hx_1 = { "loli", 13 };
	HengXin hx_2;
	hx_1.name = "LOLI";
	hx_1.print_name();
	hx_2.print_name("loli", 14);
}