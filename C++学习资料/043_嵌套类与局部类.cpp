#include <iostream>

using namespace std;

namespace
{
	class WaiBuClass
	{
	public:
		class ClassClass	// �����ڲ�����������Ƕ����(�ڲ���)
							// һ��Ƕ������Ϊ�˸��ⲿ���Լ�ʹ�õ�, ���ṩ�����
		{
		public:
			void func(void);
		public:
			int b;			// �ڲ����ǲ��ܷ����ⲿ��ı�����
		};

		void func(void);
	public:
		int a;
	};

	void WaiBuClass::ClassClass::func(void)	// �������ⲿʵ��
	{
		cout << "�������Ƕ����" << endl;
		// b = a; // ����, ���ܷ���
		b = 1;
	}

	void WaiBuClass::func(void)
	{
		cout << "������ⲿ��" << endl;
		a = 2;
	}
}

static void _text_043_class(void)
{
	class JuBuClass	// �ֲ���, �����ں�������, �������ں�������, �����������ļ�(ȫ��������)
	{
	public:
		void func(void)
		{
			cout << "����Ǿֲ���" << endl;
		}

		static void funawa(void)	// ���Զ��徲̬��Ա����, ����Ҫע��������, ���ܷ�������κα���
									// ��Ϊ���ܷ��ʷǾ�̬��Ա����, �ܷ��ʾ�̬��Ա����, ����̬��Ա�����ֲ��ܶ���
		// [!] ����, ������ʵ����Pythonһ���ں������涨���Ӻ���, ֻ��Ҫͨ�� "����::������(�����б�)" �ķ�ʽ���ʼ���
		{
			cout << "����" << endl;
		}

		//static int a; // ����������̬��Ա���� <����>
	};

	JuBuClass awa;
	awa.func();
	JuBuClass::funawa();
}

//void JuBuClass::func(void)	// �ֲ��಻��������ʵ�ֺ��� <����>
//{
//	;
//}

static auto _text_043_class_()
{
	class CCClass {
	public:
		void awa() {
			cout << "The CCClass!" << endl;
		}
	};

	return CCClass(); // ������Ϊ����ֵ!!!
}

void text_043(void)
{
	WaiBuClass w;
	w.func();
	cout << endl;
	// ������Ҫ�����ڲ���, ֻ��ָ������:
	WaiBuClass::ClassClass cc;
	cc.func();
	cout << endl;
	// �ֲ���
	_text_043_class();

	auto x = _text_043_class_();
	x.awa();
}