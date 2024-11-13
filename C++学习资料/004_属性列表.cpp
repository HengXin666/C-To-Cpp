#include <iostream>
using namespace std;

[[deprecated("这个函数已经被废弃了")]]
static void oldFunction() {};

[[nodiscard]] int calculate() { return 0; };

[[maybe_unused]] void unusedFunction() {};

void new_cpp17_004(void)
{
	//oldFunction();
	calculate();
}