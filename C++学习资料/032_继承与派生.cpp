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
		cout << "姓名: " << name << " 年龄: " << age << " 高度: " << height << endl;
	}
};
					// protected 受保护: 继承的东西 无法在对象处通过 "." 来使用成员变量/方法, 只能在 类内自用 或 友元函数使用
					// private	 私有的: 继承的东西 除了 <受保护> 外, 还不能再被继承
static class Student: public Person
{
public:
	void setFenSu(int fensu)
	{
		this->fensu = fensu;
	}

	void showData(void)
	{
		// 无论继承方式如何, 派生类都是无法访问基类的私有成员的
		cout << "姓名: " << name << " 年龄: " << age << " 高度: 不明 分数: " << /*height*/ fensu << endl;
	}
private:
	int fensu;
};

void text_032(void)
{
	// 派生类是不能使用基类的私有成员的, 但是可以通过基类的公有成员函数来使用私有成员变量
	Student sut;
	sut.name = "张三";
	sut.setAge(21);
	sut.setHeight(1.82);
	sut.setFenSu(60);
	sut.printData();
	sut.showData();
}