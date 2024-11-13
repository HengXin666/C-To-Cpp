#include <iostream>
#include <stack>

using namespace std;

static void _demo_(void)
{
	// ������ת��Ϊ16����
	int n;
	cin >> n;
	stack <char> s;
	while (n)
	{
		s.push(n % 16);
		n /= 16;
	}

	while (!s.empty())
	{
		cout << (s.top() >= 10 ? char('A' - 10 + s.top()) : char(s.top() + '0'));
		s.pop();
	}
}

void stl_004(void)
{
	// ����ջ, ��������һ��ʹ�ù��캯��
	stack <int> s({ 1, 2, 3, 4 });


	// ջ�Ĳ���
	cout << s.top() << endl;	// ����ջ��Ԫ�� (��ɾ��)

	s.push(1433223);			// ��ջ�����Ԫ�� [��ջ]
	cout << s.top() << endl;

	s.pop();					// ɾ��ջ��Ԫ��
	cout << s.top() << endl;	// ��ӡ��Ҫʹ�� top

	// ջ���ж�
	cout << "ջ�Ƿ�Ϊ��: " << s.empty() << endl;			// �ж�ջ�Ƿ�Ϊ��, 1�ǿ�, 0�ǿ�

	cout << "ջ�ĳ���(Ԫ�ظ���): " << s.size() << endl;	// ջ��Ԫ�ظ���

	_demo_();
}