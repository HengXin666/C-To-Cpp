#include <iostream>

using namespace std;

static class MyClass
{
public:
	int MC_i, MC_j;
	MyClass(const MyClass& C)	// ��ֵ���캯�� (�Զ����)
	{
		MC_i = C.MC_i;
		MC_j = C.MC_j;
		cout << "������!" << endl;
	}

	MyClass(int i, int j)		// ���캯��
	{
		MC_i = i;
		MC_j = j;
	}
};

void text_022(void)
{
	MyClass awa(7, 8);	// ��������

	// ��������
	MyClass qwq(awa);	// C++11 ֧�ֵ�
	MyClass o_0 = qwq;	// ԭʼ��
}