#include <iostream>

using namespace std;

void text_007(void)
{
	char str[128];

	//cin >> str;
	//cout << str << endl;

	// һ����gets , ���� vs ֻ��gets_s
	gets_s(str);	// ����
	puts(str);		// ���
}