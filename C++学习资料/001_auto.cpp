#include <iostream>
#include <vector>

using namespace std;

// �䵱��������ֵ
static auto sum(int a, int b)
{
	return a + b;
}

static class Demo
{
public:
	//auto a = 1; �����
	//static auto a = 1; �����
	static const auto a = 1;
};


void new_cpp11_001(void)
{
	// 1. auto���������
	vector<int> arr = { 1,2,3,4,5 };
	for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;
	}

	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;
	}

	// 2. �����Ƶ�, ע�� const �� auto, ��&����const
	// 3. �������

	// ��������ģ��
	//vector<auto> awa = { 1,2,3,4 };

	// �����Ƶ�Ϊ��������, ����Ƶ���ָ��
	int array[] = { 1,2,3,4 };
	auto list = array;
	auto op = array[2];
}