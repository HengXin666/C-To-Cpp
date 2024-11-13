#include <iostream>
using namespace std;

static void _006_put(void)
{
	cout << endl;
}

template <class... T>
static void _006_putSizeof(T... t)
{
	cout << "[]: " << sizeof...(t) << endl; // �̶��﷨��ʽ�����ȡ��ģ������ĸ���
	cout << "[]: " << sizeof...(T) << endl; // ע��sizeof...ֻ�ܼ���...�Ŀɱ��
}

template <class L, class... T>
static void _006_put(L l, T... t)
{
	cout << l << " ";
	_006_put(t...);
}


void new_cpp11_006(void)
{
	_006_putSizeof(1, 2, 3, 4);

	_006_put(1, 2, 3, 4, "���·�", 0.721);
}