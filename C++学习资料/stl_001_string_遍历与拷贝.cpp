#include <iostream>
#include <string>

using namespace std;

void stl_001(void)
{
	string s = "hello hx";
	// --- ���� || ���� ---
	// C++11��������
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
	// ��������
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	// ������(������ָ��)���� (�������Ϊ s.begin()�ǵ�һ��Ԫ�صĵ�ַ, Ȼ�� s.end()�����һ��Ԫ�صĺ�һ��Ԫ�صĵ�ַ)
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	// --- ���� ---
	s.insert(s.begin(), 'a');			// �� ��ͷ �� ���� 1 �� 'a'
	s.insert(s.begin(), 6, 'w');		// �� ��ͷ �� ���� 6 �� 'w'
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
	s.insert(s.begin(), s.begin(), ++s.begin());	// ̯�������������, ����ܳ, ��֧֮�� + �����ӷ�, �Լ�ʵ������!?
	s.insert(s.end(), {'s','i','s'});	// �� ĩβ �� ���� 1 �� �ַ�����// ����ʹ���ַ���(��Ϊ�ַ����ǻ�Ĭ�����'\0'��β)
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
}