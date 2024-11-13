#include <iostream>
#include <string>	// string.h �� c���Ե�ͷ�ļ�

using namespace std;

static void _text_string_01(void);			// string ���������ʼ���븴��
static void _text_string_02(void);			// string �ĳ��Ȼ�ȡ
static void _text_string_03(void);			// string ��ƴ�� ( ����ƴ��string Ҳ����ƴ��c���Է����ַ���(�ַ�����))
static void _text_string_04(void);			// string �ıȽ�
											// string ����
static void _text_string_05(void);			// string ��ȡ
static void _text_string_06(void);			// string ����
static void _text_string_07(void);			// string ����

static void _text_string_01(void)
{
	// �ַ������������ʼ��
	string str_0 = "����!";			// �Ⱥ�Ҳ��
	cout << str_0 << endl;

	string str_1("�ַ���������");	// �ַ��������� --> string
	cout << str_1 << endl;

	string str_2(10, 'F');			// ����len = 10 ���ַ���, ���ҳ�ʼ��Ϊ'F'
	cout << str_2 << endl;

	// ���Ʒ���һ
	string str_3("1433223");
	string str_4(str_3);			// string --����--> string
	cout << str_3 << " " << str_4 << endl;

	// ���Ʒ�����
	str_1 = str_4;
	cout << str_1 << endl;

	string str_5();	// û�в���, ��ô����Ϊ 0, ����Ϊ0����cout�����!
					// string ���Զ������ַ����ĳ���, ���Ӱ�ȫ
}

static void _text_string_02(void)
{
	string str = "0721";

	//		c���������			���stl�����ķ�����
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

	str_1.append("C���Է���ַ���, ");
	cout << str_1 << endl;

	str_1.append(str_2);
	cout << str_1 << endl;

	// ƴ�ӵ����ַ�
	str_1.push_back('G');
	cout << str_1 << endl;
}

static void _text_string_04(void)
{
	string str_1 = "hellow";
	string str_2 = "hellow";

	cout << (str_1 == str_2 ? "���" : "�����") << endl;

	// �����ıȽϷ������ʼ�
	// str_1.compare(str_2) ��
}

static void _text_string_05(void)
{
	string s1 = "123456789";
	string s2 = s1.substr(3, 2);	// (������ ��ʼλ��)��ʼλ��(��������), ��ȡ����
									// Ҳ��������Ǵ�����Ϊ3��λ�ÿ�ʼ(������ǰ)
	cout << s2 << endl;
}

static void _text_string_06(void)
{
	string s1 = "123456789";

	// ���������һ��, ����������
	cout << s1[0] << endl;
	cout << s1.at(0) << endl;
}

static void _text_string_07(void)
{
	string s1 = "abcdefg";
	s1.insert(1, "123");
	cout << s1 << endl;

	// begin() �ǵ�����, �ַ���ʼ���Ǹ�����(0)
	s1.insert(s1.begin() + 2, 3, 'G');	// ����3���ַ� 'G'
	cout << s1 << endl;
}

void text_008(void)
{
	// �ܲ���
	_text_string_07();
}