#include <iostream>

using namespace std;

static class my_Class
{
public:
	void operator() (int n)
	{
		++n;
	}
};

void new_cpp11_004(void)
{
	auto fff = [] {};
	[](void) -> void {return; };
	int n = 10;
	auto fun = [=]() mutable {
		++n;
	};
	cout << n << endl << endl;

	// ---
	int num1 = 10, num2 = 20;
	auto fun3 = [&num1, &num2](int num3) {num2 = num1 + num3; };
	auto fun1 = [&num1, &num2](int num3) {num2 = num1 + num3; };
	//fun1 = fun3;
	fun1(20);
	
	// ---

	auto lbd = [=]() {cout << num1 << endl; };
	num1 = 2;
	lbd();
	num1 = 20;
	lbd();
	
}

static void _text_001_dbd(void)
{
	class Lambda
	{
	public:
		Lambda(int num1)
		{
			this->num1 = num1;
		}

		void operator() (void) const
		{
			cout << this->num1 << endl;
		}

	private:
		int num1;
	};

	int num1 = 10;
	Lambda lambda(10);
	auto lbd = lambda;
	num1 = 2;
	lbd();
	num1 = 20;
	lbd();
}