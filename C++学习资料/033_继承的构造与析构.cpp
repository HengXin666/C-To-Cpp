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

	// 等价使用this 指针的, C++11 的新特性好像
	Person(string name, int age) : name(name), age(age){}	// 实际上是个函数哦, {}展开

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

static class Student: public Person
{
public:
	using Person::Person;	// 把基类的构造函数都拿过来, 你把这行注释掉, 就可以看到 <欧赔>那一行 报错了

	Student() {};

	// 构造函数											    : 委托基类的构造函数(记得传参), 其他参数
	Student(string name, int age, double height, int fensu) : Person(name, age, height), fensu(fensu)
	{
		; // 也可以写语句
	}

	// 上下 等价
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
		// 无论继承方式如何, 派生类都是无法访问基类的私有成员的
		cout << "姓名: " << name << " 年龄: " << age << " 高度: 不明 分数: " << /*height*/ fensu << endl;
	}
private:
	int fensu;
};

void text_033(void)
{
	Student stu("阿哲", 24, 1.72, 80);
	stu.printData();

	Student s("欧赔", 14);	// 这个构造函数是 Person的
	s.setFenSu(90);
	s.showData();
}