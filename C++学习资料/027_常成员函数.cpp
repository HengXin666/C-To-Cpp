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
		name = _name;
		arg = _arg;
		cout << "声明成员并且初始化!" << endl;
	}

	~HengXin()
	{
		cout << "成员释放!" << endl;
	}
	
	void getStr(void)
	{
		cin >> this->name;
	}

	void putStr(void) const	// 常成员函数
	{
		cout << this->name << endl;
	}

	const string* getName() const;
};

void text_027(void)
{
	HengXin hx;
	hx.getStr();
	hx.putStr();

	string* s = (string *)hx.getName();
	*s = "awa";
	cout << *s << endl;
	hx.putStr();
}

const string* HengXin::getName() const
{
	return &this->name;
}
