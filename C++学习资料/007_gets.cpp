#include <iostream>

using namespace std;

void text_007(void)
{
	char str[128];

	//cin >> str;
	//cout << str << endl;

	// 一般是gets , 但是 vs 只有gets_s
	gets_s(str);	// 输入
	puts(str);		// 输出
}