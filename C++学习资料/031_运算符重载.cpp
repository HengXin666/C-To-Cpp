#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass (int v)
	{
		this->val = v;
	}

	int operator+(MyClass& m_1)		// A + B	A สวืิผบ, B สวดซฒฮ, ฟษาิศฯฮช
	{
		return this->val + m_1.val;
	}

	void operator()(int x) {

	}

	void operator()(int x, int y) {

	}

	int operator!() {

	}

	void operator/(int x) {

	}
private:
	int val;
};

void text_031(void)
{
	MyClass my1 = 1;
	MyClass my2(2);

	cout << my1 + my2 << endl;
}