#include <iostream>

void BUG_01(void)
{
	int arr[] = { sizeof(int) , sizeof(arr[6]), /* sizeof(arr) / sizeof(arr[0]), */ 2, 3 };
	std::cout << sizeof(arr) / sizeof(arr[0]);
	// �˴��� sizeof(arr[6]) �����Ƿ��� arr[6], ���Ƿ���arr������ --> int
	// ʵ������ sizeof(int)
}