#include <iostream>
using namespace std;

static class MyClass_ByCpp11_007 {
public:
	// ͨ����Ĭ�Ϲ��캯������Ϊdelete�����ǽ����˸����Ĭ�Ϲ��캯��������ζ���޷�ͨ���޲η�ʽ��������Ķ���, ��ͬ
	MyClass_ByCpp11_007() = delete;                          // ����Ĭ�Ϲ��캯��
	MyClass_ByCpp11_007(const MyClass_ByCpp11_007&) = delete;            // ���ÿ������캯��
	MyClass_ByCpp11_007& operator=(const MyClass_ByCpp11_007&) = delete; // ���ÿ�����ֵ�����

	// ���ƶ����캯�����ƶ���ֵ���������Ϊdefault��������ʽ������Ĭ�ϵ��ƶ�������
	// ����������ȷ����������Ҫ�����ƶ����������¿��Ը�Ч�ؽ�����Դת�ơ�
	MyClass_ByCpp11_007(MyClass_ByCpp11_007&&) = default;                // ��ʽ����Ĭ���ƶ����캯��

	~MyClass_ByCpp11_007();
	MyClass_ByCpp11_007& operator=(MyClass_ByCpp11_007&&);
};

MyClass_ByCpp11_007::~MyClass_ByCpp11_007() = default;
MyClass_ByCpp11_007& MyClass_ByCpp11_007::operator=(MyClass_ByCpp11_007&&) = default;     // ��ʽ����Ĭ���ƶ���ֵ�����

void new_cpp11_007(void)
{
	// �����氡
}