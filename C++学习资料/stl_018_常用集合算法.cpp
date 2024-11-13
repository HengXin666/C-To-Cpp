#include <iostream>
#include <vector>
#include <algorithm> // ���ü����㷨

using namespace std;

void stl_018(void)
{
	vector<int> v1 = { 1, 2, 3, 7 },
				v2 = { 2, 4, 6 },
				v3;

	// �� (��)
	{
		// --- ������������[����]�洢���������������ؽ��������1��Ԫ�صĵ�����λ�� set_intersection() ---
		// v1 �� v2 --> v3
		v3.resize(min(v1.size(), v2.size()));	// ע����������Ҫ��ǰ���ٿռ�

		// ע��Ϊʲô�����ǵ�����, ������ֱ��end()����, ��Ϊ���ٵĿռ���û�����ϵ�, Ϊ init_var = 0
		auto pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
		// ���� �������� A B ������, �Լ������ż��� C �Ŀ�ʼλ��

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}

	// �� (+)
	{
		// --- �����������Ĳ����洢���������������ز��������1��Ԫ�صĵ�����λ�� set_union() ---
		// v1 �� v2 --> v3
		v3.resize(v1.size() + v2.size());

		auto pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}

	// �� (-)
	{
		// --- �����������Ĳ�洢���������������ز�����1��Ԫ�صĵ�����λ�� set_difference() ---
		// A - B --> C
		// [!]ע��: �����Ⱥ�����˽��! A - B != B - A
		v3.resize(max(v1.size(), v2.size()));	// MAX ����Ϊ�������� A �� B ������û��Ԫ����ͬ

		auto pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		
		// ******************* ע�� �� �� ���� *******************

		pos = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());

		cout << "{ ";
		for (auto i = v3.begin(); i != pos; ++i)
		{
			printf("%d ", *i);
		}

		cout << "}" << endl;
		vector<int>().swap(v3);
	}
}