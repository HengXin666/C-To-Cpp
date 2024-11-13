#include <iostream>

using namespace std;

template <class R, class T, class U>
static R add_1(T a, U b)
{
	return a + b;
}

// �����
//template <class T, class U>
//static decltype(a + b)add_2(T a, U b)
//{
//	return a + b;
//}

template <class T, class U>
static auto add_3(T a, U b) -> decltype(a + b)
{
	return a + b;
}

void new_cpp11_002(void)
{
	// �Ƶ���������
	{
		int a = 10;
		auto num1 = a;
		auto num2 = 20;
		decltype(num1 + num2) num3;
	}

	// ����ģ��, ���Զ��Ƶ� �����б������, ���ǲ����Ƶ�����ֵ������
	{
		int cs = 10;
		double cs_2 = 21.1;
		auto res = add_1<decltype(cs + cs_2)>(cs, cs_2);
	}

	cout << add_3(2, 3.14) << endl;
}