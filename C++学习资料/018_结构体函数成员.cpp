#include <iostream>

using namespace std;

void text_018(void)
{
	struct MyStruct
	{
		int fun(void)
		{
			cout << "������˽ṹ�庯����Ա!" << endl;
			return 666;
		}
	};

	MyStruct qwq;
	MyStruct *awa = &qwq;

	cout << awa->fun() << endl;
	cout << (*awa).fun() << endl;	// ������
}