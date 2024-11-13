#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void file_02(void)
{
	fstream f;
	f.open("file_01.txt", ios::in);

	// �ж��Ƿ��
	if (!f.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}

	char c;
	char buf[1024] = { 0 };

	/* ===������=== */
	cout << "\n========����һ========" << endl;
	// ����һ: Ч�ʵ�, ������ʹ��
	// ѧϰ�� B-��, B+���Ķ�֪��, cpu���ļ�ioʱ��ɱ���, �㻹һ���ַ�һ���ַ���ȡ...
	while ((c = f.get()) != EOF)
	{
		cout << c;
	}

	f.clear(); // ��� eof��ǵ�true
	// �ļ�ָ��: ��λ�� f �Ŀ�ͷ
	f.seekg(0, ios::beg);
	cout << "\n========������========" << endl;
	// ������: 
	while (f >> buf)
	{
		cout << buf << endl;
	}

	f.clear(); // ��� eof��ǵ�true
	f.seekg(0, ios::beg);
	cout << "\n========������========" << endl;
	// ������:
	while (f.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	f.clear(); // ��� eof��ǵ�true
	f.seekg(0, ios::beg);
	cout << "\n========������========" << endl;
	// ������:
	string string_obj;				// ��Ҫ string ����
	while (getline(f, string_obj))	// getline ��Ҫ<string>
	{
		cout << string_obj << endl;
	}

	f.close();
}