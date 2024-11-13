#include <iostream>

using namespace std;

void text_006(void)
{
	int arr[] = { 1,4,3,3,2,2,3 };
	for (auto i : arr)
	{
		// auto 可以理解自适应类型, 类型跟随 arr
		// i 不是索引, 而是从 arr[0] 开始的每一个, 不越界数组的值
		cout << i << endl;
	}
}