#include <iostream>

using namespace std;

void text_009(void)
{
	cout << "\tһ��:" << endl;
	{
		int num1 = 100;
		int num2 = num1;
		num1 += 100;
		num2 -= 50;
		cout << "num1, num2 �ֱ���: " << num1 << " " << num2 << endl;
	}

	cout << "\t����:" << endl;
	{
		int num1 = 100;
		int &num2 = num1;
		num1 += 100;
		num2 -= 50;
		cout << "num1, num2 �ֱ���: " << num1 << " " << num2 << endl;
	}
	// ���ò�ռ�ڴ�, ���ñ����ʼ��, ��������NULL
}