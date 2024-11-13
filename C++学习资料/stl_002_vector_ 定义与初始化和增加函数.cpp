#include <iostream>
#include <vector>

using namespace std;

void stl_002(void)
{
	// 定义
	vector <int> v = { 1, 2, 3, 4, 5 };
	vector <string> v2 = { "啊啊", "呃呃", "失败的" };
	vector <vector <int>> vv(2, v);	// 含有2个元素, 均是 v	 // 二维向量
	vector <double> vb(v.begin(), v.end());	// 复制从 v的开始 到 v的结束 位置的内容到 vb中

	// 遍历
	cout << v.at(0) << " == " << v[0] << endl;		// .at(索引) 与 [索引] 一样
	cout << v.front() << " " << v.back() << endl;	// 获取 .front()头 .back()尾 元素

	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << endl;			// 使用迭代器
	}

	// 添加
	v2.push_back("阿哲的");			// 在尾部添加
	cout << v2.back() << endl;

	vb.insert(vb.begin() + 1, 2);	// 在指定 迭代器位置 添加元素
	for (auto i = vb.begin(); i != vb.end(); ++i) cout << *i << " ";

	// insert还有多种函数重载, 不多演示
}