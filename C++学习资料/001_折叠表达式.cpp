#include <iostream>
using namespace std;

template<class ...T>
static int sum_fun_By17(T... num)
{
	//return (num + ...);
	int cs = 1;
	return ([&] {
		cout << "[" << num;
		if (sizeof...(T) > 2)
			cout << " + ";
		else
			cout << " = ";

		cout << ++cs << "]";

		return num;
		}() + ...);
	//return ((std::cout << num << " + "), ...) + (sizeof...(num) > 0 ? 0 : (std::cout << "= ", 0));
}

void new_cpp17_001(void)
{
	cout << sum_fun_By17(1, 2, 3, 4, 5, 6, 7, 8, 9);
	cout << endl << sum_fun_By17(1);
}