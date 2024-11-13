#include <iostream>

using namespace std;

void text_009(void)
{
	cout << "\t一般:" << endl;
	{
		int num1 = 100;
		int num2 = num1;
		num1 += 100;
		num2 -= 50;
		cout << "num1, num2 分别是: " << num1 << " " << num2 << endl;
	}

	cout << "\t引用:" << endl;
	{
		int num1 = 100;
		int &num2 = num1;
		num1 += 100;
		num2 -= 50;
		cout << "num1, num2 分别是: " << num1 << " " << num2 << endl;
	}
	// 引用不占内存, 引用必需初始化, 不能引用NULL
}