#include <iostream>

using namespace std;

static class HengXin
{
public:
	int arg;
	string name;

	HengXin()
	{
		cout << "������Ա!" << endl;
	}

	HengXin(string _name, int _arg)
	{
		name = _name;	// ����βα��������ܺ����Աһ��
		arg = _arg;		// ��Ȼ�Ͷ����βε���, (�����򸲸�)
		cout << "������Ա���ҳ�ʼ��!" << endl;
	}

	~HengXin()
	{
		cout << "��Ա�ͷ�!" << endl;
	}

	void print_name(string name, int arg)
	{
		cout << name << " " << arg << "����~" << endl;
	}

	void print_name(void)
	{
		cout << name << " " << arg << "����~" << endl;
	}
};

void text_025(void)
{
	HengXin hx_1 = { "loli", 13 };
	HengXin hx_2;
	hx_1.name = "LOLI";
	hx_1.print_name();
	hx_2.print_name("loli", 14);
}