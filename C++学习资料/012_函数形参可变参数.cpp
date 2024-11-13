#include <iostream>
#include <cstdarg>	// �ɱ����


static int _n_sums(int n, ...)
{
	int sum = 0;
	va_list argptr;
	va_start(argptr, n);	// ��ʼ��argptr
	for (int i = 0; i < n; ++i)
	{
		sum += va_arg(argptr, int);
	}
	va_end(argptr);
	return sum;
}


void text_012(void)
{
	std::cout << _n_sums(5, 1, 2, 3, 4, 5) << std::endl;
}