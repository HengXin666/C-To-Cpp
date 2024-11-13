#include <iostream>

using namespace std;

void text_019(void)
{
	cout << "请输入一个整数:";
	int x;
	cin >> x;
	if ((x & 1) == 0)
		cout << "偶数!" << endl;
	else
		cout << "坤数!" << endl;
}