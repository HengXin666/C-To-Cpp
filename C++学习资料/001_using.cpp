#include <iostream>

void text_001(void)
{
	int xz;
	std::cin >> xz;
	switch (xz)
	{
		// �﷨(�ؼ���) using
		case 1:
		{
			// namespace <...> ��ȫ���� �����ռ�<...> ��ȫ������
			using namespace std;
			cout << "����ֱ��ʹ��cout �� endl" << endl;
			break;
		}
		case 2:
		{
			// ���������� �����ռ�std �� cout
			using std::cout;
			cout << "����ֱ��ʹ��cout ������ʹ�� endl" << std::endl;
			break;
		}
		case 3:
		{
			// ��ʽ����
			std::cout << "��ʹ��using���������ռ�, ��ô�Ͳ���ʹ������!" << std::endl;
			break;
		}
	default:
		std::cout << "������˼, ����ǲ��Դ���! ����Ҫ�鿴Դ��������!\n";
		break;
	}
}