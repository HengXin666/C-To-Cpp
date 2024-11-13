#include <iostream>

using namespace std;

namespace
{
	class ZhiZuoYinPin	// [������Ʒ] ������� (���Խ�����������Ϊ�ܹ�/��������, ʵ�����������������)
	{
	public:
		// ����Ǵ��麯��, ֻ���ṩһ��ģ��, ��Ҫ����������ʵ��
		virtual void yeiTi(void) = 0;	// Һ��
		virtual void ZiZuo(void) = 0;	// ����
		virtual void ZhuanYi(void) = 0;	// ת��
		virtual void ZhuoLiao(void) = 0;// ����

		void MakeDrink(void)	// �涨�������� ȡҺ��-->����-->װ��-->��ҩ
		{
			yeiTi();
			ZiZuo();
			ZhuanYi();
			ZhuoLiao();
		}
	};

	class Coffee : public ZhiZuoYinPin
	{
	public:
		virtual void yeiTi(void)
		{
			cout << "��èè������ȡˮ, ���ҽ��ж�������" << endl;
		}

		virtual void ZiZuo(void)
		{
			cout << "2Fe + Co ==����== Java" << endl;
		}

		virtual void ZhuanYi(void)
		{
			cout << "�鿧�Ȼ�װ���ɫ���" << endl;
		}

		virtual void ZhuoLiao(void)
		{
			cout << "�����ϰ˲���˳���õ�����" << endl;
		}
	};

	class Juice : public ZhiZuoYinPin
	{
	public:
		virtual void yeiTi(void)
		{
			cout << "��ƻ���ֻ�����ե֭��" << endl;
		}

		virtual void ZiZuo(void)
		{
			cout << "Apple ==ե֭��== App + LE" << endl;
		}

		virtual void ZhuanYi(void)
		{
			cout << "�Ž�����" << endl;
		}

		virtual void ZhuoLiao(void)
		{
			cout << "������������˳���õ�����" << endl;
		}
	};
}

static void _text_040_eat(ZhiZuoYinPin *Z)
{
	Z->MakeDrink();
	delete Z;
}

void text_040(void)
{	
	// ע���麯��������д��Ŷ!
	_text_040_eat(new Coffee());
	cout << endl;
	_text_040_eat(new Juice());
}