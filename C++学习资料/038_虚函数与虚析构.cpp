#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		/*~A()
		{
			cout << "call ~A" << endl;
		}*/

		// �볢��ע������ ���������� Ȼ������, ������ʲôЧ��
		virtual ~A()
		{
			cout << "call virtual ~A" << endl;
		}
	};

	class B :public A
	{
	public:
		~B()
		{
			cout << "call ~B" << endl;
		}
	};
}

void text_038(void)
{
	// �麯����Ҫ��Ϊ��ʵ�ֶ�̬
	// �� virtual �ؼ��־����麯��

	// ��������Ϊ���� new ���� �� delete ����ʱ��, ����û���� ��������
	// ����:
	A* p = new B;
	delete p;

	// ���԰�A���ڴ�ռ俴����ƻ��, Ȼ��B��ƻ����, ���delete p
	// Ȼ���������û����������������������, ֻ�ǻ��ͷ�ƻ����,����ƻ������? --�ǵ�
}