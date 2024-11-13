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
	// 共享指针 //
	// 创建
	shared_ptr<int> sp_1;			// 不传入任何实参
	shared_ptr<int> sp_2(nullptr);  // 传入空指针
	// 空的 shared_ptr 指针，其初始引用计数为 0，而不是 1。
	
	// 在构建 shared_ptr 智能指针，也可以明确其指向
	shared_ptr<int> sp_3(new int(5));

	// 智能指针的使用不用看它如此声明, 当成指针使用就行了, 或者说看做是容器, (本质是一个类)
	cout << "sp_3 the var: " << *sp_3 << endl;
	cout << "sp_3 the %x: " << sp_3.get() << endl; // get()方法可以获得其地址
	int *x = new int(6);
	shared_ptr<int> sp_err(x);

	shared_ptr<_Text_Class> sh_t(new _Text_Class(1));

	sh_t->show();

	cout << "什么也没有用" << endl;

	//{
	//	unique_ptr<string> p1;
	//	string* str = new string("智能指针的内存管理陷阱");
	//	p1.reset(str);	// p1托管str指针
	//	{
	//		unique_ptr<string> p2;
	//		p2.reset(str);	// p2接管str指针时，会先取消p1的托管，然后再对str的托管
	//	}

	//	// 此时p1已经没有托管内容指针了，为NULL，在使用它就会内存报错！
	//	cout << "str:" << *p1 << endl;
	//}
}