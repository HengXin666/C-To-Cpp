#include <iostream>

using namespace std;

static class Qwq;			// ����, ˵�����Ļ��ж���, ��Ҫ�ż�����
static class Awa
{
public:
	Awa()
	{
		//my_var = 1;		// ���ڲ��������Է���˽�г�Ա
	}
	friend class Qwq;		// ���� Awa �� Qwq����Ԫ�� ��, ���� ��Ԫ�� Qwq

private:
	int my_var;
};

static class Qwq
{
public:
	// friend class Awa;	// ���Ի�Ϊ��Ԫ��
	void awa(Awa& A)
	{
		cout << A.my_var << endl;
	}

	void get_var_to_awa(Awa& A, int x)	// ��д�����ǿ�������Ŷ
	{
		A.my_var = x;		// ��Ԫ��Ҳ���Է��� �����˽�г�Ա
	}
};

void text_030(void)
{
	Qwq q;
	Awa a;
	q.get_var_to_awa(a, 666);
	q.awa(a);
}