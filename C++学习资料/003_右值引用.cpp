#include <iostream>

using namespace std;

static int add(int a, int b)
{
	return a + b;
}

static int num = 10;

int& resnum(void)
{
	return num;
}

void new_cpp11_003(void)
{
	const int&& num1 = 10; // ��ֵ����ʾ��
	// ���ú�������ֵ������ֵ��һ����ʱ������Ϊ��ֵ
	const int&& num2 = add(10, 10);

	cout << num1 << " " << num2 << endl;
	/*
	1. һ����Ϊ����ֵ�ɷ��ڸ�ֵ���ŵ���ߣ���ֵ���Է��ڸ�ֵ���ŵ��ұߣ�
				�����ܹ�ȡ��ַ�ĳ�Ϊ��ֵ������ȡ��ַ�ĳ�Ϊ��ֵ.

	2. ��ֵҲ�ܷ��ڸ�ֵ���ŵ��ұߣ���ֵֻ�ܷ��ڸ�ֵ���ŵ��ұ�
	*/

	resnum() = 111;
	cout << num << endl;
}