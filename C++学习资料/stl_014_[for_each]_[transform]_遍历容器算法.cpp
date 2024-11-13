#include <iostream>
#include <vector>
#include <algorithm> // !!!

using namespace std;

// ��ͨ����
static void _print(int var)
{
	cout << var << " ";
}

static int _copy(int var)
{
	return var * var;
}

// �º���
static class _Print
{
public:

	// ������(), const˵�����ǲ���ı䴫�������
	void operator() (int var) const
	{
		cout << var << " ";
	}
};

static class _Copy
{
public:

	// ������(), const˵�����ǲ���ı䴫�������
	int operator() (int var) const
	{
		return var >> 1;
	}
};

void stl_014(void)
{
	vector<int> v = { 4,3,2,1,3,4,7 };

	// --- for_each --- <�Զ����ӡ>
	cout << "����ָ��: ";
	for_each(v.begin(), v.end(), _print);
	cout << endl << "�º���: ";
	for_each(v.begin(), v.end(), _Print());
	cout << endl;
	
	// --- transform --- <�Զ��忽��>

	vector<int> w;		// Ŀ������
	w.resize(v.size());	// Ŀ��������Ҫ��ǰ���ٿռ�, ��� Ŀ��������ԭ����ֱ�Ӹ���, ������Ҫ���ٿռ�ſ��Ը���
	transform(v.begin(), v.end(), w.begin(), _copy);
	for_each(w.begin(), w.end(), _print);
	cout << endl;
	transform(v.begin(), v.end(), w.begin(), _Copy());
	for_each(w.begin(), w.end(), _print);
}