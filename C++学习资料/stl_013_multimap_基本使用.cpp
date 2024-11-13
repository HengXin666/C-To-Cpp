#include <iostream>
#include <map>

using namespace std;

static void _putMultimap(multimap<int, int>& m)
{
	cout << "{ ";
	for (auto& it : m)
	{
		cout << "{ " << it.first << " : " << it.second << " }, ";
	}
	cout << "\b\b };" << endl;
}

void stl_013(void)
{
	// ---����---
	multimap<int, int> m1 = { {1, 11}, {2, 22} , {3, 33} };

	multimap<int, int> m2(m1);	// Ĭ�Ϲ��캯��
	multimap<int, int> m3 = m1; // ���������(=)
	
	_putMultimap(m1);

	// ---����---(ֻչʾ���õ�)
	m1.insert(make_pair(6, 616));
	m1.insert(make_pair(6, 626));
	m1.insert(make_pair(6, 636));
	m1.insert(make_pair(6, 646));
	m1.insert(make_pair(6, 656));
	m1.insert(make_pair(6, 666));
	m1.insert(make_pair(7, 77));
	m1.insert(make_pair(7, 77));
	_putMultimap(m1);

	// ---ɾ��---
	m1.erase(1);				// ɾ����
	_putMultimap(m1);

	m1.erase(--m1.end());		// ɾ��������
	_putMultimap(m1);

	auto pos = m1.find(6);		// ɾ������������
	m1.erase(m1.begin(), pos);
	_putMultimap(m1);

	// ---����---
	if (m1.empty())
	{
		cout << "Ϊ��" << endl;
	}
	else
	{
		cout << "�ǿ�" << endl;
	}
	cout << "size:" << m1.size() << endl;

	// ���, ���� ����

	// ����ж��ٸ�����(ͬһ����)
	cout << m1.count(6) << endl;;

	// ---multiϵ��---
	auto p1 = m1.lower_bound(6);	// ���Ҵ��ڵ��� key ������
	auto p2 = m1.upper_bound(6);	// ���Ҵ��� key ������
	cout << (*p1).first << " " << (*p1).second << endl;
	cout << (*p2).first << " " << (*p2).second << endl;

	// ���ҳ����м��� key ������, ������һ�� ���������� �ṹ�� [, )��
	auto range = m1.equal_range(6);
	for (auto i = range.first; i != range.second; ++i)
	{
		cout << "{ " << (*i).first << " : " << (*i).second << " }, ";
	}
}