#include <iostream>
#include <cstdlib>	// ���������
#include <ctime>	// ϵͳʱ��

using namespace std;

void text_005(void)
{
	cout << "����������ֵ��: " << RAND_MAX << endl;
	
	cout << "��ʹ�ö�̬������Ϊ����:" << endl;

	srand(666);

	for (int i = 0; i < 5; ++i)
	{
		// ÿ����������: 13 34 92 52 49
		cout << rand() % 100 << " ";
	}

	cout << endl << "ʹ��ϵͳʱ����Ϊ����:" << endl;

	srand(time(NULL));	// �� 1970.1.1 00:00:00 �� ��ǰ������

	for (int i = 0; i < 5; ++i)
	{
		cout << rand() % 100 << " ";
	}

	cout << endl << "ʹ��ϵͳʱ����Ϊ����, ����λ�ô���:" << endl;

	for (int i = 0; i < 5; ++i)
	{
		srand(time(NULL));
		cout << rand() % 100 << " ";
		// ֵ��ͬ����Ϊ:
		// ÿ�����������ʱ���������������ӣ�����ѭ���ڲ�ʹ��srand(time(NULL))��
		// ����ʱ�侫��̫�ߣ�ѭ���ڲ����������Ӳ���������ͬһ������ɣ��������ɵ������������ͬ
	}

	// ���Կ���, ����������ʼ, ÿ�ε��� srand(num), �������β����� num �йص���ֵͬ
}