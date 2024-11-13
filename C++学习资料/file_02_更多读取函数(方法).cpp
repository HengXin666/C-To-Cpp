#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void file_02(void)
{
	fstream f;
	f.open("file_01.txt", ios::in);

	// 判断是否打开
	if (!f.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}

	char c;
	char buf[1024] = { 0 };

	/* ===读数据=== */
	cout << "\n========方法一========" << endl;
	// 方法一: 效率低, 不建议使用
	// 学习过 B-树, B+树的都知道, cpu与文件io时间成本高, 你还一个字符一个字符读取...
	while ((c = f.get()) != EOF)
	{
		cout << c;
	}

	f.clear(); // 清除 eof标记的true
	// 文件指针: 定位到 f 的开头
	f.seekg(0, ios::beg);
	cout << "\n========方法二========" << endl;
	// 方法二: 
	while (f >> buf)
	{
		cout << buf << endl;
	}

	f.clear(); // 清除 eof标记的true
	f.seekg(0, ios::beg);
	cout << "\n========方法三========" << endl;
	// 方法三:
	while (f.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	f.clear(); // 清除 eof标记的true
	f.seekg(0, ios::beg);
	cout << "\n========方法四========" << endl;
	// 方法四:
	string string_obj;				// 需要 string 容器
	while (getline(f, string_obj))	// getline 需要<string>
	{
		cout << string_obj << endl;
	}

	f.close();
}