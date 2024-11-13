#include <iostream>
#include <list>

using namespace std;

static void _putList(list <int> L)
{
	cout << "[info]: ";
	// ---查--- 好像不能用 L[i] || at(i)
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
		cout << (*i).name << " " << (*i).arg << "岁 " << (*i).len << "cm" << endl;
	}

}

static bool _demo_cmp_arg(const Person& a, const Person& b)
{
	return a.arg < b.arg ? true : a.arg == b.arg ? a.len > b.len ? true : false : false;
}

static void _demo(void)
{

	list<Person> L = {		{"张三", 23, 171},
							{"李四", 18, 167},
							{"王五", 17, 164},
							{"老六", 14, 154},
							{"小七", 17, 178},
							{"老八", 17, 159} 
					};

	// 按年龄从小到大, 如果年龄相同, 则按身高由大到小
	L.push_front({"大纲", 17, 144});
	L.sort(_demo_cmp_arg);
	_putDemo(L);
}	

void stl_008(void)
{
	list<int> L = { 1,4,3,3,2,6,7,9,-1 };
	_putList(L);

	L.sort();		// 排序, 默认是从小到大
	_putList(L);

	L.sort(cmp);	// 自定义排序方式, 从大到小
	_putList(L);

	// 翻转list
	L.reverse();
	_putList(L);

	// 练习
	_demo();
}