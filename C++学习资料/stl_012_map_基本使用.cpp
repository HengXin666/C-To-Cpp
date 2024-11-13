#include <iostream>
#include <map>

using namespace std;

void stl_012(void)
{
	// 声明
	map<const char*, int> map = { {"阿哲", 12}, {"宁这", 24}, {"字典", 36} };	// 内部自动排序的
	// 打印
	auto a = map.begin();
	cout << a->first << " " << a->second << endl;
	cout << map["阿哲"] << endl;
}