#include <iostream>

using namespace std;

static void _text_010_1(void);		// 场景1 作为函数参数
static void _text_010_2(void);		// 场景2 作为返回值	(最好是返回 传参的引用, 或者是函数内的静态变量, 不要返回局部变量的引用)

static void _text_010_X2(int& num)
{
	num *= 2;
}

static void _text_010_1(void)
{
	int n = 10;
	_text_010_X2(n);
	cout << n << endl;
}

/*---------------------------------*/

static int& _text_010_X2_ret(int& num)
{
	return num *= 2;
}

static void _text_010_2(void)
{
	// 值得注意的是, 最好是返回 传参的引用, 或者是函数内的静态变量, 不要返回局部变量的引用
	int n = 10;
	cout << _text_010_X2_ret(n) << endl;
}

void text_010(void)
{
	_text_010_2();
}