#include <iostream>
#include <vector>
#include <ranges>
using namespace std;

void new_cpp20_003(void)
{
	auto ints = views::iota(0, 10);//Éú³É0-9
	auto even = [](int i) { return 0 == i % 2; };
	auto square = [](int i) { return i * i; };

	for (int i : ints | views::filter(even) | views::transform(square))
		cout << i << ' ';
}