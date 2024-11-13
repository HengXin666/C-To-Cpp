#include <forward_list>
#include <iostream>

using namespace std;

void new_cpp11_009(void)
{
	forward_list<int> list_1{4, 3, 3, 2, 2, 3};
	list_1.push_front(1);

	

	for (auto& it : list_1)
	{
		cout << it << " ";
	}
}