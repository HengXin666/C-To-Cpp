#include <iostream>

using namespace std;

static class Person
{
public:
	string name;
protected:
	int age;
private:
	double height;

public:
	void setName(string name)
	{
		this->name = name;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	void setHeight(double height)
	{
		this->height = height;
	}

	void printData(void)
	{
		cout << "����: " << name << " ����: " << age << " �߶�: " << height << endl;
	}
};
					// protected �ܱ���: �̳еĶ��� �޷��ڶ���ͨ�� "." ��ʹ�ó�Ա����/����, ֻ���� �������� �� ��Ԫ����ʹ��
					// private	 ˽�е�: �̳еĶ��� ���� <�ܱ���> ��, �������ٱ��̳�
static class Student: public Person
{
public:
	void setFenSu(int fensu)
	{
		this->fensu = fensu;
	}

	void showData(void)
	{
		// ���ۼ̳з�ʽ���, �����඼���޷����ʻ����˽�г�Ա��
		cout << "����: " << name << " ����: " << age << " �߶�: ���� ����: " << /*height*/ fensu << endl;
	}
private:
	int fensu;
};

void text_032(void)
{
	// �������ǲ���ʹ�û����˽�г�Ա��, ���ǿ���ͨ������Ĺ��г�Ա������ʹ��˽�г�Ա����
	Student sut;
	sut.name = "����";
	sut.setAge(21);
	sut.setHeight(1.82);
	sut.setFenSu(60);
	sut.printData();
	sut.showData();
}