#include <iostream>

using namespace std;

static double _myDiv(double a, double b)
{
	/*
	* ���Խ�try������if, ��������������쳣, ��throw���ִ��
	* ��ô�������ж� catch(���ʽ) �ı��ʽ�Ƿ�Ϊ�� ������ if {}else if{}else if{}
	* �� (const char* mag) �������throw������, (...) �ǲ���ȫ���쳣���Ҵ���, ���ǲ�֪�����Ǹ��쳣, ���Ƕ��൱�� else
	* ���, ����ʹ�� const char* mag
	* C++ �ƺ�������pyһ��, ����Ҫ�ֶ���дȫ�����쳣, �����ݽ����޶� [?]
	* */
	try							// �����ǿ��ܳ���BUG�Ĵ��� 
	{
		if (b == 0)				// �����쳣
		{
			throw "���ܳ�����!";	// ����쳣, ������쳣����Ҫ���д���
		}
		return a / b;
	}
	catch (const char* mag)		// ���throw ������
	{
		cerr << mag << endl;
	}
	catch (...)					// �����쳣�����Լ�����, ���쳣���д���
	{
		cout << "������!" << endl;
		return -1;
	}
}

void text_041(void)
{
	// C++ �� ������������᷵��inf �������ķ�Χ, 0����0�᷵��-nan(inf) -δ������Ϊ(������Χ)
	cout << _myDiv(0, 0) << endl;;
}