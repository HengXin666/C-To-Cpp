#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass() {}
	~MyClass() {}
	friend static void _text_029_n(MyClass m);	// ��Ԫ���� �ؼ���: friend
	// ������������, ��������ʵ��(��������ʵ��Ҳ���ǲ���), ���Է��� ���ȫ��˽�г�Ա���� �� �ܱ����ĳ�Ա����
	
	 friend void awa(MyClass m) {
		 cout << m.n << endl;
		 // cout << this.n << endl;
	 }
private:
	int n;
};

static void _text_029_n(MyClass m)				// ע���β�, ����
{												// ʹ�ú���ͨ����û������
	m.n = 1;
}

void text_029(void)
{
	MyClass me;
	// me.n = 1;		// �޷�����
	_text_029_n(me);	// û�б��� <-- ֱ��ʹ��, ���� ".����"
	awa(me);
}