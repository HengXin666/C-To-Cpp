#include <iostream>
#include <format>
using namespace std;

void new_cpp20_004(void)
{
	string str = "Hello C++";
	// ��˳�����
	cout << format("����ַ�����'{}', ������ {} .", str, str.size()) << endl;

	// ָ������λ��(������ ��0��ʼ)
	cout << format("����ַ�����'{1}', ������ {0} .", str.size(), str) << endl;
}