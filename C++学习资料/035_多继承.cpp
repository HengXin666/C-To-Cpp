#include <iostream>

using namespace std;

namespace
{
	class Zoo
	{
	public:
		Zoo()
		{
			cout << "The Zoo Good" << endl;
		}

		void printInfo(void)
		{

		}
	};

	class Cat
	{
	public:
		Cat()
		{
			cout << "Cat Cat kawaii ~" << endl;
		}

		void printInfo(void)
		{

		}
	};

	// ��������[��̳�], �����Ǽ̳е���ͬ��λ��<�������η�>
	class CatInZoo : public Zoo, public Cat	// ���캯��/���������ĵ���˳���Ƕ�̳д�����������, �����������˳���޹�
	{				// ����˳����: Zoo --> Cat (--> CatInZoo) ������ 
	public:
		CatInZoo(void) : Cat(), Zoo(){}		// �Ҿ��������Ǹ��������Ǹ�...
											// Cat(), Zoo() ��˳�򲻻�Թ���/������˳�����Ӱ��

		void fun(void)
		{
			// <��̳����Ƴ�ͻ���>
			// �������� ����ͬ�����������ͻ
			Zoo::printInfo();
			Cat::printInfo();
		}
	};
}

void text_035(void)
{
	CatInZoo awa;
	awa.fun();		// ������
}