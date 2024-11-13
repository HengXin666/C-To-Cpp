#include <iostream>
#include <vector>

using namespace std;

static void _print(vector<int> v)
{
	cout << "[info]: ";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_003(void)
{
	vector <int> v({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	_print(v);

	// --- ɾ��Ԫ�� ---
	v.erase(v.begin() + 1);				// ɾ��������ָ���Ԫ��
	_print(v);

	v.erase(v.end() - 4, v.end() - 1);	// ɾ���ӵ����� [a, b) ֮���Ԫ��
	_print(v);

	v.pop_back();						// ɾ��ĩβ��Ԫ��
	_print(v);

	v.clear();							// ���������Ԫ��
	_print(v);

	// --- �жϺ��� ---
	cout << v.empty() << endl;			// �ж������Ƿ�Ϊ��, ���Ϊ���򷵻�1, ����0

	// --- ��С���� ---
	// ������size��ָ���Ѿ������Ԫ�ص���Ŀ����capacity�����ڲ������µ��ڴ�ռ��ǰ�����������Ա������Ԫ�ء�
	cout << v.size() << endl;			// ����[��ǰ]������Ԫ�ظ���
	cout << v.capacity() << endl;		// ����[�ڲ�����ռ�������]�����������ɵ�Ԫ�ظ���
	cout << v.max_size() << endl;		// ���ص�ǰ�����������ɵ����Ԫ�ظ���

	// -- �������� ---
	vector <int> v1({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	v.swap(v1);	// ��������������ֵ
	_print(v);
	_print(v1);

	v1 = v;

	v.assign(3, 2233);	// ����ǰ 3 �� Ԫ�ص�ֵΪ 2233
	_print(v);			// ע���� [����] �������/����, �������������

	v1.assign(v1.begin() + 1, v1.begin() + 2);	// ���������� [����] Ϊ������ [v1.begin() + 1, v1.begin() + 2) ������
	_print(v1);
}