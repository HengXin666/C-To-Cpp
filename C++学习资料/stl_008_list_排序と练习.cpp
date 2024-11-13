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

static bool cmp(const int& a, const int& b)
{
	return a > b;
}
static struct Person
{
	const char* name;
	int arg;
	int len;
};

static void _putDemo(list<Person> L)
{
	cout << "---demo---"<< endl;
	for (auto i = L.begin(); i != L.end(); ++i)
	{
		cout << (*i).name << " " << (*i).arg << "�� " << (*i).len << "cm" << endl;
	}

}

static bool _demo_cmp_arg(const Person& a, const Person& b)
{
	return a.arg < b.arg ? true : a.arg == b.arg ? a.len > b.len ? true : false : false;
}

static void _demo(void)
{

	list<Person> L = {		{"����", 23, 171},
							{"����", 18, 167},
							{"����", 17, 164},
							{"����", 14, 154},
							{"С��", 17, 178},
							{"�ϰ�", 17, 159} 
					};

	// �������С����, ���������ͬ, ������ɴ�С
	L.push_front({"���", 17, 144});
	L.sort(_demo_cmp_arg);
	_putDemo(L);
}	

void stl_008(void)
{
	list<int> L = { 1,4,3,3,2,6,7,9,-1 };
	_putList(L);

	L.sort();		// ����, Ĭ���Ǵ�С����
	_putList(L);

	L.sort(cmp);	// �Զ�������ʽ, �Ӵ�С
	_putList(L);

	// ��תlist
	L.reverse();
	_putList(L);

	// ��ϰ
	_demo();
}