#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

static int num = 0;
static mutex fun_mutex;

void fun(int id)
{
	for (int i = 0; i < 100000; ++i)
	{
		fun_mutex.lock();
		++num;
		printf("id = %d, say: %d\n", id, num);
		fun_mutex.unlock();
	}
}

void thread_002(void)
{
	thread th(fun, 1), th_2(fun, 2);
	th.join();
	th_2.join();
}