#include <iostream>

using namespace std;

static double _myDiv(double a, double b)
{
	/*
	* 可以将try看成是if, 如果下面代码出现异常, 即throw语句执行
	* 那么就依次判断 catch(表达式) 的表达式是否为真 类似与 if {}else if{}else if{}
	* 而 (const char* mag) 可以输出throw的内容, (...) 是捕获全部异常并且处理, 但是不知道是那个异常, 它们都相当于 else
	* 因此, 尽量使用 const char* mag
	* C++ 似乎不能像py一样, 必需要手动书写全部的异常, 对数据进行限定 [?]
	* */
	try							// 下面是可能出现BUG的代码 
	{
		if (b == 0)				// 捕获异常
		{
			throw "不能除以零!";	// 输出异常, 输出的异常必需要进行处理
		}
		return a / b;
	}
	catch (const char* mag)		// 输出throw 的内容
	{
		cerr << mag << endl;
	}
	catch (...)					// 所有异常都可以激活它, 对异常进行处理
	{
		cout << "出错啦!" << endl;
		return -1;
	}
}

void text_041(void)
{
	// C++ 中 非零数除以零会返回inf 超出数的范围, 0除以0会返回-nan(inf) -未定义行为(超出范围)
	cout << _myDiv(0, 0) << endl;;
}