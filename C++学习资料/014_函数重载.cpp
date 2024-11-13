#include <iostream>

static int _text_014_sum(int a, int b)
{
	return a + b;
}

static double _text_014_sum(double a, double b)
{
	return a + b;
}

void text_014(void)
{
	std::cout << _text_014_sum(1, 2) << " " << _text_014_sum(3.14, 13.1) << std::endl;
}