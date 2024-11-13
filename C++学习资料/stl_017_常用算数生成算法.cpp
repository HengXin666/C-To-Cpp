#include <iostream>
#include <vector>
#include <numeric> // �������������㷨 ͷ�ļ�

using namespace std;

void stl_017(void)
{
	vector<int> v;
	for (int i = 1; i <= 100; ++i)
	{
		v.push_back(i);
	}

	// --- accumulate �������ĵ���������ָ����������� ---
	int a = 0;
	cout << "��� + a:" << a << " = " << accumulate(v.begin(), v.end(), a) << endl;

	// --- fill �������ĵ������������ֵ���
	vector<int> arr;

	// ע����ҪԤ�ȷ���ռ�, ��Ϊû�з���������������� [a, a) ���
	// ��Ȼ�ﲻ��Ŀ��
	arr.resize(10);
	fill(arr.begin(), arr.end(), 100);

	for (auto it : arr)
	{
		cout << it << " ";
	}
}