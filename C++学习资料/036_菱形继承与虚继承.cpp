#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		int m_a;
	};

	class B : public A
	{
	public:
		int m_b;
	};

	class C : public A
	{
	public:
		int m_c;
	};

	class D : public B, public C
	{
	public:
		void getA(int a)
		{
			// this->m_a = a;	// ����ȷ
			// this->D::m_a = a;// ����ȷ

			// ����
			this->A::m_a = a;

			// ����
			this->B::m_a = a + 1;
			this->C::m_a = a + 2;

			// �����Ͳ��������ֳ�Ա����m_a, �ڴ治���ظ�... ����ĳЩ�����������
		}

		void putA(int xz)
		{
			switch (xz)
			{
			case 1:
				cout << A::m_a << endl;
				break;
			case 2:
				cout << B::m_a << endl;
				break;
			case 3:
				cout << C::m_a << endl;
				break;
			default:
				break;
			}
		}
	public:
		int m_d;
	};
}

static void _text_036(void);
void text_036(void)
{
	/*	���μ̳�Ч��ͼ:
	*			A		����
	*		   / \
	*		  B	  C		�̳л���A��������B, C
	*		   \ /
	*			D		�̳л���B, C��������D
	* 
	*	Σ��: ��� A�еĳ�Ա������B, C�̳в��Ҽ̳е�D, ��ô�� ����A�ı���, �Ͳ�֪���� B�Ļ���A�� ���� C�Ļ���A�� (��������)
	* 
	*	�������:	1. ������ܵļ̳����� ��������������ô��?�Ҿ���Ҫ�ð�		[Pass]
	*				2. ����, ��ʽҪ��ʹ�� A::����	, ���ǻ��ǻ���һ�ݵı�������	[Warning]
	*				3. ��Ϊʹ����̳� �� _text_036();							[Info]
	*
	*	ֵ��ע�����:
	*		"ʹ����̳л���������ʱ�Ŀ�������Ҫ�������ָ����������������ࡣ"
	*
	* ��ˣ��������ļ̳нṹʱ��ֻ���ڴ������μ̳е�����»�ȷʵ��Ҫʹ����̳н��[����������]ʱ�����Ƽ�ʹ����̳С�
	* ���������������ͨ�ļ̳м�����������
	*	<<ֵ��ע��>> By GPT-3.5 
	* */
	D d;
	d.getA(123);
	d.putA(1);
	d.putA(2);
	d.putA(3);
	_text_036();
}


namespace
{
	class X_A
	{
	public:
		int m_a;
	};

	class X_B : virtual public X_A
	{
	public:
		int m_b;
	};

	class X_C : virtual public X_A
	{
	public:
		int m_c;
	};

	class X_D : virtual public X_B, virtual public X_C
	{
	public:
		void getA(int a)
		{
			this->m_a = a;
		}

		void putA(void)
		{
			cout << m_a << endl;
		}

	public:
		int m_d;
	};
}

static void _text_036(void)
{
	X_D xd;
	xd.getA(114514);
	xd.putA();
}