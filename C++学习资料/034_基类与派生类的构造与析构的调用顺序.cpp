#include <iostream>

using namespace std;

static class Zoo
{
public:
	Zoo()
	{
		cout << "{ // Zoo" << endl;
	}

	~Zoo()
	{
		cout << "} // Kill Zoo" << endl;
	}
};

static class Cat:public Zoo
{
public:
	Cat()
	{
		cout << "\t{ // Cat" << endl;
	}

	Cat(string name)
	{
		cout << "\t{ // Cat" << endl;
		cout << "\t\t\t[init]: �������� ?" << endl;
	}

	~Cat()
	{
		cout << "\t} // Kill Cat" << endl;
	}
};

static class NbCat :public Cat
{
public:
	NbCat(string name)
	{
		cout << "\t\t{ // NbCat" << endl;
		this->name = name;
		cout << "\t\t\t[init]: �������� " << this->name << " �Ǥ�~" << endl;
	}

	NbCat()
	{
		cout << "\t\t{ // NbCat" << endl;
	}

	~NbCat()
	{
		cout << "\t\t} // Kill NbCat" << endl;
	}

	void maimai(void)
	{
		cout << "\t\t\t[NbNeKo]: giao ~ !" << endl;
	}
private:
	string name;
};

static void _text_034(void);
void text_034(void)
{
	// ��һ�������౻ʵ����Ϊ����ʱ, ���ȵ��û���Ĺ��캯��, �ٵ���������Ĺ��캯��
	// �������ʱ��, ���ȵ������������������, �ٵ��û������������, ������ �ݹ��<��>
	// ֵ��ע�����: ���õĻ���ĺ�����Ĭ�ϵĹ��캯��, ���û����ᱨ��
	// ��Ȼͨ�����������ǿ�����û��Ĭ�Ϲ��캯���������, ����������඼�����������ô������Ĺ��캯��
	{
		NbCat awa("��");
		awa.maimai();
	}
	cout << endl;
	_text_034();	// <--- ��������
}

// ʹ��һ�����������ռ�, ������������Ҳ���ļ���
namespace {
	class _Zoo {
	public:
		_Zoo(int x) {
			cout << "{ // Zoo" << endl;
		}

		~_Zoo() {
			cout << "} // Kill Zoo" << endl;
		}
	};

	class _Cat : public _Zoo {
	public:
		_Cat(string name) : _Zoo(1) {
			cout << "\t{ // Cat" << endl;
			cout << "\t\t\t[init]: �������� " << name << " �Ǥ�~" << endl;
		}

		~_Cat() {
			cout << "\t} // Kill Cat" << endl;
		}

		void maimai() {
			cout << "\t\t\t[NbNeKo]: giao ~ !" << endl;
		}
	};

	class _NbCat : public _Cat {
	public:
		_NbCat(string name) : _Cat(name) {
			cout << "\t\t{ // NbCat" << endl;
			cout << "\t\t\t[init]: �������� " << name << " �Ǥ�~" << endl;
		}

		~_NbCat() {
			cout << "\t\t} // Kill NbCat" << endl;
		}
	};
}

static void _text_034(void)
{
	// ������ǲ���Ĭ�ϵĹ��캯��, Ҳ��д By GPT-3.5
	_NbCat awa("������~");
	awa.maimai();
}