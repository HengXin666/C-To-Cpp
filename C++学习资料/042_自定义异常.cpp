#include <iostream>
#include <exception>

using namespace std;

namespace
{
	class MyException : public exception
	{
	public:
		// what是exception提供的公共方法, 用于返回异常原因
		// throw() 在 C++11 标准后已经被弃用，建议使用 noexcept 关键字来代替。
		// 这些关键字有助于提高程序的健壮性和安全性，避免程序在出现异常时崩溃或导致未定义行为
		const char* what() const noexcept
		{
			return "My text exception";
		}

		// 01:
		//const char* what() const throw()// 表示该函数不会抛出任何异常。
		//								// 注意，这个关键字在 C++11 中已经被弃用，取而代之的是 noexcept 关键字
		//{
		//	return "My text exception";
		//}
	};
}


static enum index { xiaBiaoTaiXiao, xiaBiaoTaiDa };	// 枚举类型的应用
static int _text_042_get_arr(int* arr, int index, int arrLen)
{
	if (index < 0)
	{
		throw xiaBiaoTaiXiao;
	}
	else if (index >= arrLen)
	{
		throw xiaBiaoTaiDa;
	}
	return arr[index];
}

void text_042(void)
{
	char a = 0;
	try
	{
		if (a == 0)
		{
			MyException myex;
			throw myex;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	int b[] = { 1,1,4,5,1,4 };
	try
	{
		_text_042_get_arr(b, 6, 6);
	}
	catch (index e)
	{
		switch (e)
		{
		case xiaBiaoTaiXiao:
			cout << "下标太小了" << endl;
			break;
		case xiaBiaoTaiDa:
			cout << "下标太大了" << endl;
			break;
		default:
			break;
		}
	}
}