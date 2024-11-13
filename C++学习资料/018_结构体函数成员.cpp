#include <iostream>

using namespace std;

void text_018(void)
{
	struct MyStruct
	{
		int fun(void)
		{
			cout << "你调用了结构体函数成员!" << endl;
			return 666;
		}
	};

	MyStruct qwq;
	MyStruct *awa = &qwq;

	cout << awa->fun() << endl;
	cout << (*awa).fun() << endl;	// 都可以
}