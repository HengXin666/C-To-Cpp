#include <iostream>
#include <string>	// string.h 是 c语言的头文件

using namespace std;

static void _text_string_01(void);			// string 的声明与初始化与复制
static void _text_string_02(void);			// string 的长度获取
static void _text_string_03(void);			// string 的拼接 ( 可以拼接string 也可以拼接c语言风格的字符串(字符数组))
static void _text_string_04(void);			// string 的比较
											// string 查找
static void _text_string_05(void);			// string 截取
static void _text_string_06(void);			// string 访问
static void _text_string_07(void);			// string 插入

static void _text_string_01(void)
{
	// 字符串的声明与初始化
	string str_0 = "报错!";			// 等号也行
	cout << str_0 << endl;

	string str_1("字符串的声明");	// 字符常量数组 --> string
	cout << str_1 << endl;

	string str_2(10, 'F');			// 申请len = 10 的字符串, 并且初始化为'F'
	cout << str_2 << endl;

	// 复制方法一
	string str_3("1433223");
	string str_4(str_3);			// string --拷贝--> string
	cout << str_3 << " " << str_4 << endl;

	// 复制方法二
	str_1 = str_4;
	cout << str_1 << endl;

	string str_5();	// 没有参数, 那么长度为 0, 长度为0不能cout输出哇!
					// string 会自动调整字符串的长度, 更加安全
}

static void _text_string_02(void)
{
	string str = "0721";

	//		c语言留存的			配合stl容器的方法名
	cout << str.length() << " " << str.size() << endl;
}

static void _text_string_03(void)
{
	string str_1 = "3.14";
	string str_2 = "15926";
	string str_3 = "535114514";

	cout << str_1 + str_2 << endl;

	str_1 += str_2;
	str_3 = str_1 + str_3;
	cout << str_1 << endl << str_3 << endl;

	str_1.append("C语言风格字符串, ");
	cout << str_1 << endl;

	str_1.append(str_2);
	cout << str_1 << endl;

	// 拼接单个字符
	str_1.push_back('G');
	cout << str_1 << endl;
}

static void _text_string_04(void)
{
	string str_1 = "hellow";
	string str_2 = "hellow";

	cout << (str_1 == str_2 ? "相等" : "不相等") << endl;

	// 函数的比较方法见笔记
	// str_1.compare(str_2) 等
}

static void _text_string_05(void)
{
	string s1 = "123456789";
	string s2 = s1.substr(3, 2);	// (不包含 开始位置)开始位置(不是索引), 截取长度
									// 也可以理解是从索引为3的位置开始(包含当前)
	cout << s2 << endl;
}

static void _text_string_06(void)
{
	string s1 = "123456789";

	// 像访问数组一样, 数字是索引
	cout << s1[0] << endl;
	cout << s1.at(0) << endl;
}

static void _text_string_07(void)
{
	string s1 = "abcdefg";
	s1.insert(1, "123");
	cout << s1 << endl;

	// begin() 是迭代器, 字符开始的那个索引(0)
	s1.insert(s1.begin() + 2, 3, 'G');	// 插入3个字符 'G'
	cout << s1 << endl;
}

void text_008(void)
{
	// 总测试
	_text_string_07();
}