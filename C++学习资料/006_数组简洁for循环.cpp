#include <iostream>

using namespace std;

void text_006(void)
{
	int arr[] = { 1,4,3,3,2,2,3 };
	for (auto i : arr)
	{
		// auto �����������Ӧ����, ���͸��� arr
		// i ��������, ���Ǵ� arr[0] ��ʼ��ÿһ��, ��Խ�������ֵ
		cout << i << endl;
	}
}