#include <iostream>

void text_002(void)
{
	int a, b, c;
	using namespace std;
	cin >> a >> b >> c;	// 意思是输入到 a , b , c 这三个变量里面, 可以使用 空格 或者 '\n' 隔开接受
	// 接受字符串也是不能接受空格!!!
	cout << a << " " << b << " " << c << endl;
}