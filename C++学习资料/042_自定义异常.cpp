#include <iostream>
#include <exception>

using namespace std;

namespace
{
	class MyException : public exception
	{
	public:
		// what��exception�ṩ�Ĺ�������, ���ڷ����쳣ԭ��
		// throw() �� C++11 ��׼���Ѿ������ã�����ʹ�� noexcept �ؼ��������档
		// ��Щ�ؼ�����������߳���Ľ�׳�ԺͰ�ȫ�ԣ���������ڳ����쳣ʱ��������δ������Ϊ
		const char* what() const noexcept
		{
			return "My text exception";
		}

		// 01:
		//const char* what() const throw()// ��ʾ�ú��������׳��κ��쳣��
		//								// ע�⣬����ؼ����� C++11 ���Ѿ������ã�ȡ����֮���� noexcept �ؼ���
		//{
		//	return "My text exception";
		//}
	};
}


static enum index { xiaBiaoTaiXiao, xiaBiaoTaiDa };	// ö�����͵�Ӧ��
static int _text_042_get_arr(int* arr, int index, int arrLen)
{
	if (index < 0)
	{
		throw xiaBiaoTaiXiao;
	}
	else if (index >= arrLen)
	{
		throw xiaBiaoTaiDa;
	}
	return arr[index];
}

void text_042(void)
{
	char a = 0;
	try
	{
		if (a == 0)
		{
			MyException myex;
			throw myex;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	int b[] = { 1,1,4,5,1,4 };
	try
	{
		_text_042_get_arr(b, 6, 6);
	}
	catch (index e)
	{
		switch (e)
		{
		case xiaBiaoTaiXiao:
			cout << "�±�̫С��" << endl;
			break;
		case xiaBiaoTaiDa:
			cout << "�±�̫����" << endl;
			break;
		default:
			break;
		}
	}
}