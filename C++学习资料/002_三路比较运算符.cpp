#include <iostream>

using namespace std;

void new_cpp20_002(void)
{
	int a = 1, b = 2;
	if ((a <=> b) > 0)
	{
		cout << "a > b" << endl;
	}
	else if ((a <=> b) < 0)
	{
		cout << "a < b" << endl;
	}
	else
	{
		cout << "a == b" << endl;
	}
}