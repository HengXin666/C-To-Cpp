#include <iostream>

void BUG_01(void)
{
	int arr[] = { sizeof(int) , sizeof(arr[6]), /* sizeof(arr) / sizeof(arr[0]), */ 2, 3 };
	std::cout << sizeof(arr) / sizeof(arr[0]);
	// 此处的 sizeof(arr[6]) 并不是访问 arr[6], 而是访问arr的类型 --> int
	// 实际上是 sizeof(int)
}