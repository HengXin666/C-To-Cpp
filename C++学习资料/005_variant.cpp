#include <iostream>
#include <variant>
using namespace std;

void new_cpp17_005(void)
{
	variant<int, double, string> d;
	cout << d.index() << endl;

	d = 3.14;
	cout << d.index() << endl;

	d = "string";
	cout << d.index() << endl;

	cout << holds_alternative<int>(d) << endl;

	std::cout << std::get<string>(d) << std::endl;
}