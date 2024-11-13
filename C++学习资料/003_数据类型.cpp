#include <iostream>

void text_003(void)
{
	int a;
	float f;
	double d;
	char c;
	//_Bool az; 这个是C99的, 不是c++的
	bool b;
	b = true;	// 1
	b = false;	// 0


	wchar_t w;		// 宽字符类型 支持汉字
	void *v = NULL;	// 无类型类型 一般是用来被强制转换的

	signed int si;	// 有符号
	unsigned int ua;// 无符号
	short s;		// 短int
	long l;			// 长int
	/*long doble ld;	没有长双精度浮点*/
	long long ll;
}