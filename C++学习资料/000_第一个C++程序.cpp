#include <iostream>

using namespace std;    // 这个可以让 cout 不用写 std::

void text_000(void)
{
	// 第一个C++程序
	cout << "hellow 测试一下!\n";
	cout << "还有这样\n这样这样!" << endl;
	cout << "这样也可以!" << endl << "woc" << endl;	// endl != '\n'
	// 因为 endl 是换行 并且 清空输出缓冲区
}