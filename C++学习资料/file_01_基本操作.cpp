#include <iostream>
#include <fstream>

using namespace std;

void file_01(void)
{
	ofstream f;			// һ��ֻ��������ܶ�ȡ����
	f.open("file_01.txt", ios::out | ios::trunc); // w+
	f << "��˿��ͩ�Ÿ���," << endl;
	f << "��ɽ�����ǲ���." << endl;
	f << "�߿����������!" << endl;
	f.close(); // ����Ҫ�ر��ļ�

	cout << "д�����" << endl;
	cout << "��ȡ�ļ�..." << endl;

	char str[128];
	string str_2;
	ifstream infile;	// һ��ֻ�����벻��д�����
	infile.open("file_01.txt", ios::in);
	infile >> str >> str_2;	// ���Զ�ȡ�� char �� string ������
							// ���� ">>" �����ֻ�ܶ�ȡһ��������, ��������ո���߻���, ���޷���ȡ��!
	cout << str << str_2 << endl;
	f.close();
}