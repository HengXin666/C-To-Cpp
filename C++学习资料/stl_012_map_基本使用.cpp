#include <iostream>
#include <map>

using namespace std;

void stl_012(void)
{
	// ����
	map<const char*, int> map = { {"����", 12}, {"����", 24}, {"�ֵ�", 36} };	// �ڲ��Զ������
	// ��ӡ
	auto a = map.begin();
	cout << a->first << " " << a->second << endl;
	cout << map["����"] << endl;
}