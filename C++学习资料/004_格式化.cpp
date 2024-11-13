#include <iostream>
#include <format>
using namespace std;

void new_cpp20_004(void)
{
	string str = "Hello C++";
	// 按顺序分配
	cout << format("这个字符串是'{}', 长度是 {} .", str, str.size()) << endl;

	// 指定参数位置(索引， 从0开始)
	cout << format("这个字符串是'{1}', 长度是 {0} .", str.size(), str) << endl;
}