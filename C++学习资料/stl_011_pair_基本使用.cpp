#include <iostream>
#include <utility>

using namespace std;

std::pair<const char*, int> _demo_get(int a, const char* b)
{
	return make_pair(b, a);
}

void stl_011(void)
{
	// ����
	pair<int, const char*> p(123, "��?");

	// ����
	cout << p.first << " " << p.second << endl;

	// ��Ϊ�������ǽṹ��, ������, ����û��ʲô����
	p = make_pair(456, "��...");
	cout << p.first << " " << p.second << endl;

	// ����Ǻ�������ֵ, ����ʹ��stl::tie����
	int ages;
	const char* name;
	std::tie(name, ages) = _demo_get(p.first, p.second);
}