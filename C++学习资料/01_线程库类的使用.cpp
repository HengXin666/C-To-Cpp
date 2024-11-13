#include <iostream>
#include <cstdio>
#include <thread>

using namespace std;

void fun(int a, int b) {
	printf("a + b = %d\n", a + b);
}

void thread_001(void)
{
	thread th(fun, 10, 20);
	printf("运行的子线程id: %ld\n", th.get_id());
	th.join();

	cout << "CPU number: " << thread::hardware_concurrency() << endl;
}