#include <iostream>
#include <array>
using namespace std;

static void _text_008(array<int, 3> a)
{
	for (auto& it : a)
	{
		cout << it << " ";
	}
}

void new_cpp11_008(void)
{
	array<int, 3> arr_1 = {};

	_text_008(arr_1);
}