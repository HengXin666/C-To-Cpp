#include <iostream>
#include <memory>

using namespace std;

static class _Text_Class
{
public:
	int qwq;

public:
	_Text_Class(int awa)
	{
		this->qwq = awa;
		cout << "do _Text_Class" << endl;
	}

	~_Text_Class()
	{
		cout << "fuck _Text_Class" << endl;
	}

	void show(void)
	{
		cout << this->qwq << endl;
	}
};

void new_cpp11_005(void)
{
	// ����ָ�� //
	// ����
	shared_ptr<int> sp_1;			// �������κ�ʵ��
	shared_ptr<int> sp_2(nullptr);  // �����ָ��
	// �յ� shared_ptr ָ�룬���ʼ���ü���Ϊ 0�������� 1��
	
	// �ڹ��� shared_ptr ����ָ�룬Ҳ������ȷ��ָ��
	shared_ptr<int> sp_3(new int(5));

	// ����ָ���ʹ�ò��ÿ����������, ����ָ��ʹ�þ�����, ����˵����������, (������һ����)
	cout << "sp_3 the var: " << *sp_3 << endl;
	cout << "sp_3 the %x: " << sp_3.get() << endl; // get()�������Ի�����ַ
	int *x = new int(6);
	shared_ptr<int> sp_err(x);

	shared_ptr<_Text_Class> sh_t(new _Text_Class(1));

	sh_t->show();

	cout << "ʲôҲû����" << endl;

	//{
	//	unique_ptr<string> p1;
	//	string* str = new string("����ָ����ڴ��������");
	//	p1.reset(str);	// p1�й�strָ��
	//	{
	//		unique_ptr<string> p2;
	//		p2.reset(str);	// p2�ӹ�strָ��ʱ������ȡ��p1���йܣ�Ȼ���ٶ�str���й�
	//	}

	//	// ��ʱp1�Ѿ�û���й�����ָ���ˣ�ΪNULL����ʹ�����ͻ��ڴ汨��
	//	cout << "str:" << *p1 << endl;
	//}
}