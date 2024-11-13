#include <iostream>
#include <string>

using namespace std;

void text_017(void)
{
	typedef struct Loli {
		string L_name = "有名字哦~";
		string L_xp = { "酱紫赋值默认值也可以!" };
		int arg = { 14 };	// 不一定要字符串
	} Loli;

	Loli awa;
	cout << awa.L_name << " " << awa.L_xp << " " << awa.arg << endl;
}