#include <iostream>

using namespace std;

void text_019(void)
{
	cout << "������һ������:";
	int x;
	cin >> x;
	if ((x & 1) == 0)
		cout << "ż��!" << endl;
	else
		cout << "����!" << endl;
}