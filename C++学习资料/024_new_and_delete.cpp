#include <iostream>

using namespace std;

static class MyClass
{
public:
	MyClass(string str)
	{
		cout << str << endl;
	}

	MyClass()
	{
		cout << "��������" << endl;
	}

	// �� ����������ǰ�����~����, ��ô�������������������
	// ���������ͷŵ�ʱ��, ���Զ�ִ��
	// ��������û�� ����ֵ �� ����!
	~MyClass()
	{
		cout << "�ͷŶ���" << endl;
	}
};

void text_024(void)
{
	// ֻ��������ָ��
	// �������� malloc �� free �ķ�װ
	{
		MyClass* p = new MyClass;
		// ����������, ���Զ���ʧ, ���ǲ����Զ�ִ��delete !
		// ͬ��Ҳ�Ͳ���ִ������������

		// ע��: p ��һ�����Բ�����ʽ�ڴ�ռ�ı���,
		// ����������, ֻ��p��ʧ��, ���� p ָ��Ŀռ�û����ʧ!!!

		// �൱�� Կ�ײ�����, �Ż���!!! (�ڴ�й©)

		// �� new �� delete Ҫ�ɶ�ʹ��!!!
	}
	MyClass* q = new MyClass();

	{
		int* p = new int[10];	// ��������Ϊ10������
		delete[] p;				// �ͷ�����ҲҪ�Ǽ� [], ��Ȼ����ֻ�ͷ�һ��
	}
	{
		MyClass* p = new MyClass[5];
		delete[] p;
	}

	delete q;

	MyClass awa[2] = { {"awa!!!"}, {"awa..."} };	// ջ����������Գ�ʼ������
													// ���Ƕ�(new/malloc)������, ֻ��ʹ��Ĭ�ϵĹ��캯��
}