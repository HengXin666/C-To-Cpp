#include <iostream>

using namespace std;

static class ClassName
{
public:		// 属性修饰符 (共有的)
	void printput(string str)
	{
		cout << str << endl;
	}
protected:	// 受保护的
private:	// 私有的

};

void text_020(void)
{
	// 类的定义在上面
	ClassName cn;			// 现在有了对象 cn
	cn.printput("14333");	// 使用类方法
}