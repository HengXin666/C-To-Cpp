#include <iostream>

using namespace std;

static class Qwq;			// 声明, 说明下文会有定义, 不要着急报错
static class Awa
{
public:
	Awa()
	{
		//my_var = 1;		// 类内部函数可以访问私有成员
	}
	friend class Qwq;		// 声明 Awa 是 Qwq的友元类 即, 声明 友元类 Qwq

private:
	int my_var;
};

static class Qwq
{
public:
	// friend class Awa;	// 可以互为友元类
	void awa(Awa& A)
	{
		cout << A.my_var << endl;
	}

	void get_var_to_awa(Awa& A, int x)	// 不写引用是拷贝对象哦
	{
		A.my_var = x;		// 友元类也可以访问 该类的私有成员
	}
};

void text_030(void)
{
	Qwq q;
	Awa a;
	q.get_var_to_awa(a, 666);
	q.awa(a);
}