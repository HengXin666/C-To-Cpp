#include <iostream>
#include <vector>

using namespace std;

void stl_002(void)
{
	// ����
	vector <int> v = { 1, 2, 3, 4, 5 };
	vector <string> v2 = { "����", "����", "ʧ�ܵ�" };
	vector <vector <int>> vv(2, v);	// ����2��Ԫ��, ���� v	 // ��ά����
	vector <double> vb(v.begin(), v.end());	// ���ƴ� v�Ŀ�ʼ �� v�Ľ��� λ�õ����ݵ� vb��

	// ����
	cout << v.at(0) << " == " << v[0] << endl;		// .at(����) �� [����] һ��
	cout << v.front() << " " << v.back() << endl;	// ��ȡ .front()ͷ .back()β Ԫ��

	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << endl;			// ʹ�õ�����
	}

	// ���
	v2.push_back("���ܵ�");			// ��β�����
	cout << v2.back() << endl;

	vb.insert(vb.begin() + 1, 2);	// ��ָ�� ������λ�� ���Ԫ��
	for (auto i = vb.begin(); i != vb.end(); ++i) cout << *i << " ";

	// insert���ж��ֺ�������, ������ʾ
}