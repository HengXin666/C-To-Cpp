#include <iostream>
#include <string>

using namespace std;

void stl_001(void)
{
	string s = "hello hx";
	// --- 迭代 || 遍历 ---
	// C++11的新特性
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
	// 索引访问
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	// 迭代器(本质是指针)访问 (可以理解为 s.begin()是第一个元素的地址, 然后 s.end()是最后一个元素的后一个元素的地址)
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	// --- 插入 ---
	s.insert(s.begin(), 'a');			// 在 开头 处 插入 1 个 'a'
	s.insert(s.begin(), 6, 'w');		// 在 开头 处 插入 6 个 'w'
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
	s.insert(s.begin(), s.begin(), ++s.begin());	// 摊牌了这个不会了, 晕了艹, 反之支持 + 号连接符, 自己实现算了!?
	s.insert(s.end(), {'s','i','s'});	// 在 末尾 处 插入 1 个 字符数组// 不能使用字符串(因为字符串是会默认添加'\0'结尾)
	for (auto myIndex : s)
	{
		cout << myIndex << " ";
	}
	cout << endl;
}