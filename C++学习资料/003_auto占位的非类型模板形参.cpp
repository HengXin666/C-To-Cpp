#include <iostream>
using namespace std;

template <auto Value>
void print(int number) {
	cout << Value << endl;
	if (number == Value) {
		std::cout << "Match!" << std::endl;
	}
	else {
		std::cout << "No match." << std::endl;
	}
}


void new_cpp17_003(void)
{
	print<1>(1);
	print<1.1>(2);
}