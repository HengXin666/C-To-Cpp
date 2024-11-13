#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		A(string str) : str(str){}

		virtual void putInfo(void)
		{
			cout << "[Info]: " << str << endl;
		}

	protected:
		string str;
	};

	class B : public A
	{
	public:
		B(string name) : A(name){}

		virtual void putInfo(void)
		{
			cout << "[Info]: " << str << endl;
		}

	};
}

void text_037(void)
{
	/*
	*	���ɶ�̬������:
	*	1. ������ڼ̳й�ϵ;
	*	2. �̳й�ϵ�б�����ͬ����[�麯��]�����������Ǹ��ǹ�ϵ������ԭ����ͬ(���������͡�˳����ͬ)��// �� virtual �ؼ��־����麯��
	*	3. ���ڻ����ָ�룬ͨ����ָ������麯����
	* */

	// ָ��ʵ�ֶ�̬
	A* p = new A("���");
	p->putInfo();
	delete p;

	p = new B("С�ϵ�");
	p->putInfo();
	delete p;
	// ������ڴ��ͷŲ�������ȷ���ƺ�,,, ����ֻҪ����̬�Ĵ���ͺ�

	// ����ʵ�ֶ�̬
	A awa("߹");
	B qwq("��");

	// �����ǻ�������Ŷ!
	A& p1 = awa;
	A& p2 = qwq;

	p1.putInfo();
	p2.putInfo();
}