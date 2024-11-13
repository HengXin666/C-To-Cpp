#include <iostream>
#include <list>

using namespace std;

static void _putList(list <int> L)
{
	cout << "[info]: ";
	// ---��--- �������� L[i] || at(i)
	for (auto i = L.begin(); i != L.end(); ++i)
		cout << *i << " ";

	cout << endl;
}

void stl_007(void)
{
	list <int> list = {0};

	// �ж��Ƿ�Ϊ��
	cout << "Ϊ: " << (list.empty() ? "��" : "����") << endl;

	// ---��---
	list.push_front(1);	// ͷ�����
	list.push_back(2);	// β�����

	// ָ��λ�����
	list.insert(list.begin(), 2, 66);

	// ���� list.begin() + 1, ������ ++list.begin ���� ++++++list.begin

	_putList(list);

	// ---ɾ---
	list.pop_front();	// ͷ��ɾ��
	list.pop_back();	// β��ɾ��
	_putList(list);

	list.erase(list.begin(), ++++++list.begin());
	_putList(list);
	cout << "Ϊ: " << (list.empty() ? "��" : "����") << endl;
}