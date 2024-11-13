#include <iostream>

using namespace std;

namespace
{
	class Animal
	{
	public:
		virtual void fun1(void)
		{
			cout << "zoo fun1" << endl;
		}

		virtual void fun2(void)
		{
			cout << "zoo fun2" << endl;
		}
	};

	class Cat : public Animal
	{
	public:
		virtual void fun3(void)
		{
			cout << "cat fun3" << endl;
		}

		virtual void fun4(void)
		{
			cout << "cat fun4" << endl;
		}

		
		virtual void fun2(void) override
		{
			cout << "cat fun2" << endl;
		}
	};

	// �����Ƿ��麯���ĶԱ� �޷�ʵ��

	class A
	{
	public:
		void awa(void)
		{
			cout << "A awa" << endl;
		}

		void qwq(void)
		{
			cout << "A qwq" << endl;
		}
	};

	class B : public A
	{
	public:
		void awa(void)
		{
			cout << "B awa" << endl;
		}
	};
}

void text_039(void)
{
	// ��̬, Ҫ���㶯̬����Ŷ
	Animal* p = new Cat();
	p->fun1();				// ���ʸ�����п���
	p->fun2();				// ���Է���������д�ķ��� ��̬

	((Animal*)p)->fun2();
	((Cat*)p)->fun3();		// ����ת�����Է��������������� (������ö�̬, ��ôһ�㲻���������)

	// �Ա�: ��, ԭ��: �޷������̬������, ����ʹ��ָ������������, ���Һ������ǵ�
	A* a = new A;
	a->awa();

	A* b = new B;
	b->awa(); // ���ʵ��� A �ķ���

	((B*)b)->awa(); // ����ת���ŷ��ʵ���B
}