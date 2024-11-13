#include <iostream>

using namespace std;

static int add(int a, int b)
{
	return a + b;
}

static int num = 10;

int& resnum(void)
{
	return num;
}

void new_cpp11_003(void)
{
	const int&& num1 = 10; // 右值引用示例
	// 引用函数返回值，返回值是一个临时变量，为右值
	const int&& num2 = add(10, 10);

	cout << num1 << " " << num2 << endl;
	/*
	1. 一般认为：左值可放在赋值符号的左边，右值可以放在赋值符号的右边；
				或者能够取地址的称为左值，不能取地址的称为右值.

	2. 左值也能放在赋值符号的右边，右值只能放在赋值符号的右边
	*/

	resnum() = 111;
	cout << num << endl;
}