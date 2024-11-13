#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool _find_if_fun(int var)
{
	return var == 9;
}

static bool _count_if_fun(int var)
{
	return var >= 8;
}


class _Find_if_class
{
public:
	// ������, ����bool�ķº��� ��Ϊ "ν��"
	bool operator() (int var) const
	{
		return var == 9;
	}
};

void stl_015(void)
{
	vector<int> v = { 1,2,3,4,4,5,6,7,8,9,9,9,9,9,9,9,9,9,9,9,9,-1, };
	
	// ---find---
	// ���� Ԫ��9 �����ǵ�����, ʧ�ܾͷ��� .end() ������
	cout << *find(v.begin(), v.end(), 9) << endl;

	// ---find_if--- <�Զ������>
	cout << *find_if(v.begin(), v.end(), _find_if_fun) << endl;
	cout << *find_if(v.begin(), v.end(), _Find_if_class()) << endl;

	// ---adjacent_find--- <���������ظ�Ԫ��>
	cout << *adjacent_find(v.begin(), v.end()) << endl; // ���ص�һ�������ظ�Ԫ�صĵ�����

	// ---binary_search--- ͨ�����ֲ���, �ж������Ƿ���ڸ�Ԫ�� ����bool, ǰ����ԭ�������������!
	cout << binary_search(v.begin(), v.end(), -1) << endl;

	// ---count--- ����
	cout << "�ظ���: " << count(v.begin(), v.end(), 9) << endl;

	// ---count_id--- <�Զ�����������>
	cout << count_if(v.begin(), v.end(), _count_if_fun) << endl;
		// һ����, ����ָ�� ���� ν�� ����, ͳ������������Ԫ�ظ���
}