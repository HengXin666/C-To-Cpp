#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

static void _putDeque(deque <int> d)
{
	cout << "[info]: ";
	for (auto i = d.begin(); i != d.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

void stl_006(void)
{
	// ����
	deque <int> dQ(10);	// ����һ������Ϊ10��int��˫�˶���, ��Ϊû��ָ����ֵ, ����Ĭ�ϳ�ʼ��Ϊ 0
	dQ.push_front(1);	// ͷ�����
	_putDeque(dQ);
	dQ.pop_front();		// ͷ��ɾ��
	_putDeque(dQ);		

	dQ.push_back(2);	// β�����
	_putDeque(dQ);
	dQ.pop_back();		// β��ɾ��
	_putDeque(dQ);

	dQ.insert(dQ.begin() + 1, 2, 1);	// ָ�� ������λ��, ���뼸(2)��, 1
	_putDeque(dQ);

	// ˫�˶��п���ͨ����������
	cout << dQ[1] << " == " << dQ.at(1) << endl;

	// ���ʵ�һ��Ԫ��			   // �������һ��Ԫ��
	cout << dQ.front() << " " << dQ.back() << endl;

	dQ.erase(dQ.begin() + 1, dQ.begin() + 3);	// ����ָ������������ [a, b) ������
	_putDeque(dQ);

	dQ.clear();	// ���
	_putDeque(dQ);

	dQ = { 1, 2, 5, -1, 3, 3 };

	sort(dQ.begin(), dQ.end());

	for (auto& it : dQ)
		cout << it << " ";


	try
	{
		// at�ķ��ʺ� [] һ��, ������Խ���
		cout << dQ.at(314) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}