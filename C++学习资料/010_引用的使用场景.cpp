#include <iostream>

using namespace std;

static void _text_010_1(void);		// ����1 ��Ϊ��������
static void _text_010_2(void);		// ����2 ��Ϊ����ֵ	(����Ƿ��� ���ε�����, �����Ǻ����ڵľ�̬����, ��Ҫ���ؾֲ�����������)

static void _text_010_X2(int& num)
{
	num *= 2;
}

static void _text_010_1(void)
{
	int n = 10;
	_text_010_X2(n);
	cout << n << endl;
}

/*---------------------------------*/

static int& _text_010_X2_ret(int& num)
{
	return num *= 2;
}

static void _text_010_2(void)
{
	// ֵ��ע�����, ����Ƿ��� ���ε�����, �����Ǻ����ڵľ�̬����, ��Ҫ���ؾֲ�����������
	int n = 10;
	cout << _text_010_X2_ret(n) << endl;
}

void text_010(void)
{
	_text_010_2();
}