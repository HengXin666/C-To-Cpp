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
		name = _name;
		arg = _arg;
		cout << "������Ա���ҳ�ʼ��!" << endl;
	}

	~HengXin()
	{
		cout << "��Ա�ͷ�!" << endl;
	}
	
	void getStr(void)
	{
		cin >> this->name;
	}

	void putStr(void) const	// ����Ա����
	{
		cout << this->name << endl;
	}

	const string* getName() const;
};

void text_027(void)
{
	HengXin hx;
	hx.getStr();
	hx.putStr();

	string* s = (string *)hx.getName();
	*s = "awa";
	cout << *s << endl;
	hx.putStr();
}

const string* HengXin::getName() const
{
	return &this->name;
}
