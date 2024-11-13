#include <iostream>

using namespace std;

namespace
{
	template <typename T, class H>
	class MyClass
	{
	public:
		void printT(T p);

		void putH(H p)	// ������ʵ�־Ͳ���Ҫ
		{
			cout << "[putH]: p == " << p << endl;
		}

		T a;
	};

	// ������ʵ�ַ���, ��Ҫ����������
	template <typename T, class H>	// ģ��
	void MyClass<T, H>::printT(T p)	// ��ҲҪ�ǵø��� "<>�����б�"
	{
		cout << "[printT]: p == " << p << endl;
	}
}

typedef MyClass<int, char> M;

// ���� template Ҫд�ں�������, �ǵ�!
template <typename T, class H>
using t = MyClass<int, char>;

void text_045(void)
{
	MyClass<int, char> a;	// ���ʵ����ҲҪ���� "<>�����б�"
	a.putH('G');
	a.printT(1433223);

	// ģ�����
	M b; // ͨ���׶�, ���Ƕ�������ı���������ͻ�������...

	// ������using�ı���

	t<int, double> t1;	// �����<>�б�Ͳ���Ҫ��, ����Ҫ��using t���Ĳ��ǶԵ� ?
						// ���� using t = MyClass<T, H>;
	t1.printT(123);
	t1.putH('A');
}