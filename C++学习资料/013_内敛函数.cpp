#include <iostream>

using namespace std;

// ��ʵ�ֵ�ʱ��ʹ������ؼ���, ������ʱ����
inline static void _text_013_say(string& str)
{
	cout << "[init]: " << str << endl;
}

void text_013(void)
{
	string str = "wdf";
	_text_013_say(str);
}