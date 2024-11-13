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
	Person(){}
	Person(string name, int age, double height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}

	// �ȼ�ʹ��this ָ���, C++11 �������Ժ���
	Person(string name, int age) : name(name), age(age){}	// ʵ�����Ǹ�����Ŷ, {}չ��

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

static class Student: public Person
{
public:
	using Person::Person;	// �ѻ���Ĺ��캯�����ù���, �������ע�͵�, �Ϳ��Կ��� <ŷ��>��һ�� ������

	Student() {};

	// ���캯��											    : ί�л���Ĺ��캯��(�ǵô���), ��������
	Student(string name, int age, double height, int fensu) : Person(name, age, height), fensu(fensu)
	{
		; // Ҳ����д���
	}

	// ���� �ȼ�
	Student(string name, int age, int fensu)
	{
		Person(name, age);
		this->fensu = fensu;
	}

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

void text_033(void)
{
	Student stu("����", 24, 1.72, 80);
	stu.printData();

	Student s("ŷ��", 14);	// ������캯���� Person��
	s.setFenSu(90);
	s.showData();
}