#include <iostream>
#include <fstream>

using namespace std;

void file_01(void)
{
	ofstream f;			// 一个只能输出不能读取的类
	f.open("file_01.txt", ios::out | ios::trunc); // w+
	f << "吴丝蜀桐张高秋," << endl;
	f << "空山凝云颓不流." << endl;
	f << "高考结束忘光光!" << endl;
	f.close(); // 还是要关闭文件

	cout << "写入完毕" << endl;
	cout << "读取文件..." << endl;

	char str[128];
	string str_2;
	ifstream infile;	// 一个只能输入不能写入的类
	infile.open("file_01.txt", ios::in);
	infile >> str >> str_2;	// 可以读取到 char 与 string 容器中
							// 但是 ">>" 运算符只能读取一部分内容, 如果遇到空格或者换行, 就无法读取了!
	cout << str << str_2 << endl;
	f.close();
}