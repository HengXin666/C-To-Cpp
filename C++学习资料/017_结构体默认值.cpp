#include <iostream>
#include <string>

using namespace std;

void text_017(void)
{
	typedef struct Loli {
		string L_name = "������Ŷ~";
		string L_xp = { "���ϸ�ֵĬ��ֵҲ����!" };
		int arg = { 14 };	// ��һ��Ҫ�ַ���
	} Loli;

	Loli awa;
	cout << awa.L_name << " " << awa.L_xp << " " << awa.arg << endl;
}