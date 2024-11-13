#include <iostream>
#include <set>	// ע��ͷ�ļ�

using namespace std;

static void _putMultiset(multiset<int> m)
{
	cout << "[info]: ";
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_010(void)
{
	// ����
	multiset <int> set = { 1, 4, 5, 7, 7, 2, 3, 3 };
	_putMultiset(set);


	// ��� (ʵ���ϲ���������������, �Ͼ����ϻ��Զ�����)
	set.insert(123);
	_putMultiset(set);

	// ����һ������
	multiset <int> set_2 = { 0, 7, 2, 1, 233 };
	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);

	// ��ռ���
	set.clear();

	// ���÷���
	if (set.empty())	// �ж��Ƿ�Ϊ��
	{
		cout << "Ϊ��" << endl;
	}
	else
	{				// ���ؼ���Ԫ�ظ���
		cout << "����Ϊ: " << set.size() << endl;
	}

	// ����
	auto p = set.find(3);	// ����ֵΪ3��Ԫ��, ���ҷ����������, ����Ҳ���, ��ô���� ������s.end()
	if (p != set.end())
	{
		cout << *p << endl;
	}
	else
	{
		cout << "û���ҵ�!" << endl;
	}

	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);

	// ͳ��λ��
	int pos = 0;
	for (auto i = set.begin(); i != set.find(2); ++i, ++pos)
		;
	cout << "2����λ��������: " << pos << endl;

	set.insert(set_2.begin(), set_2.end());
	_putMultiset(set);
	// �������õ�
	// ͳ��Ԫ�ظ���
	cout << "3�� " << set.count(3) << " ��, 0 �� " << set.count(0) << " ��" << endl;

	// ����: ����һ������ķ�����������
	cout << "���ڵ���2������ " << *set.lower_bound(2) << endl;

	cout << "����2������ " << *set.upper_bound(2) << endl;
}