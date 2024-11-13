#include <iostream>
#include <ctime>
#include <filesystem>
using namespace std;

void new_cpp17_007(void)
{
	namespace fs = std::filesystem;

	cout << "��ǰ����Ŀ¼��: " << fs::current_path() << endl;

	auto x64 = fs::path("./x64");

	if (!fs::exists(x64))
	{
		cout << "��·��������!" << endl;
	}
	else
	{
		cout << "���ڶ� [" << x64 << "] ·�� ���в���..." << endl;
	}

	// ����һ�� fs::directory_options ���� opt��ʹ��Ĭ��ѡ�� none����ʾ�����������ӣ�Ȩ�޾ܾ�������Ϊ����
	fs::directory_options opt(fs::directory_options::none);

	// ����һ�� fs::directory_entry ���� dir����ʾָ����Ŀ¼ x64
	fs::directory_entry dir(x64);

	/************************************************************************/
	/* ����һ��(һ��)Ŀ¼ʾ��                                                 */
	/************************************************************************/

	// �����ǰĿ¼������
	std::cout << "������� [x64]:\t-->" << dir.path().filename() << endl;

	// ʹ�� fs::directory_iterator ����������ָ��Ŀ¼ x64 �µ������ļ�����Ŀ¼��opt �ǿ�ѡ�ģ�����ָ������ѡ��
	for (fs::directory_entry const& entry : fs::directory_iterator(x64, opt))
	{
		// ��鵱ǰ��������·�� entry �Ƿ�Ϊ�����ļ�
		if (entry.is_regular_file())
		{
			// ����ļ������ƺʹ�С��
			cout << entry.path().filename() << "\t size: " << entry.file_size() << endl;
		}
		// �����ǰ��������·�� entry ��һ��Ŀ¼����ִ�и÷�֧
		else if (entry.is_directory())
		{
			// ���Ŀ¼�����ơ�
			cout << entry.path().filename() << "\t dir" << endl;
		}
	}

	cout << endl;

	/************************************************************************/
	/* �ݹ����ʾ��                                                          */
	/************************************************************************/
	// �����ǰĿ¼������
	cout << "x64 all:\t-->" << dir.path().filename() << endl;

	// ʹ�� fs::recursive_directory_iterator �������ݹ����ָ��Ŀ¼ x64 �µ������ļ�����Ŀ¼��opt �ǿ�ѡ�ģ�����ָ������ѡ��
	for (fs::directory_entry const& entry : fs::recursive_directory_iterator(x64, opt))
	{
		// ��鵱ǰ��������·�� entry �Ƿ�Ϊ�����ļ�
		if (entry.is_regular_file())
		{
			// ����ļ������ơ���С�͸�Ŀ¼·��
			cout << entry.path().filename() << "\t size: " << entry.file_size() << "\t parent: " << entry.path().parent_path() << endl;
		}
		// �����ǰ��������·�� entry ��һ��Ŀ¼����ִ�и÷�֧
		else if (entry.is_directory())
		{
			// ���Ŀ¼������
			cout << entry.path().filename() << "\t dir" << endl;
		}
	}
}