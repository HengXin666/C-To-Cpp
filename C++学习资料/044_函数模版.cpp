#include <iostream>

using namespace std;

template <typename T, class H>// �������ؼ��ֶ�����
static T _text_044_add(T& a, H& b)
{
	return a + b;
}

void text_044(void)
{
	// ����ģ�汾�����Ǳ������Զ��ĺ�������, ֻ��������ʽ��
	// ���Ͳ�һ������, �������治�᷵�ظ�����, ���ǰ��������˳��Ŷ~
	int a = 4.1;
	double b = 5.1;
	cout << _text_044_add(a, b) << endl;
}