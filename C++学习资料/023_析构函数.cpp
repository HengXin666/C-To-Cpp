#include <iostream>

using namespace std;

static class MyClass
{
public:
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

private:

};

void text_023(void)
{
	MyClass awa;
}