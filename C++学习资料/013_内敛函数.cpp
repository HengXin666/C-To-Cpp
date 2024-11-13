#include <iostream>

using namespace std;

// 在实现的时候使用这个关键字, 声明的时候不用
inline static void _text_013_say(string& str)
{
	cout << "[init]: " << str << endl;
}

void text_013(void)
{
	string str = "wdf";
	_text_013_say(str);
}