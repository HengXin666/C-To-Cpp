#include <iostream>
#include <set>

using namespace std;

static void _putSet(set<int> s)
{
	cout << "[info]: ";
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_009(void)
{
	// ����
	set<int> s = { 4,6,7,1,2,2,3 };	// set���Զ���Ԫ����С��������, ���Ҳ������ظ�Ԫ��
	_putSet(s);

	// ����(ֻ�ܲ���һ��Ԫ��, ������Ϊ�Զ�����, ����û��λ��ѡ��)
	s.insert(12);
	_putSet(s);

	// ɾ��
	s.erase(s.begin());						// ɾ����������ָλ��
	_putSet(s);

	s.erase(++++s.begin(), ----s.end());	// ɾ������������ [a, b)
	_putSet(s);

	s.erase(2);								// ɾ�� ָ��ֵ��Ԫ��
	_putSet(s);

	// ��ռ���
	s.clear();

	// ���÷���
	if (s.empty())	// �ж��Ƿ�Ϊ��
	{
		cout << "Ϊ��" << endl;
	}
	else
	{				// ���ؼ���Ԫ�ظ���
		cout << "����Ϊ: " << s.size() << endl;
	}

	// ����
	auto p = s.find(3);	// ����ֵΪ3��Ԫ��, ���ҷ����������, ����Ҳ���, ��ô���� ������s.end()
	if (p != s.end())
	{
		cout << *p << endl;
	}
	else
	{
		cout << "û���ҵ�!" << endl;
	}
}