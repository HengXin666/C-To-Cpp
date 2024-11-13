#include <iostream>
#include <optional>
using namespace std;

void new_cpp17_006(void)
{
	optional<int> o1(666);
	o1 = 233;
	cout << o1.value() << endl;
	o1.reset();

	cout << o1.value_or(1) << endl;
}