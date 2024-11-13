#include <iostream>

using namespace std;

static void _text_011_(int x, int op = 114514)
{
	cout << x << " " << op << endl;
}

void text_011(void)
{
	_text_011_(1);		// 传参可以为空(不传)
	_text_011_(1,2);
}