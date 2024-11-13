#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <functional>
using namespace std;

struct Counter
{
	void increment()
	{
		for (int i = 0; i < 10; ++i)
		{
			m_value += m_value + 1;
			cout << "increment number: " << m_value.load()
				<< ", theadID: " << this_thread::get_id() << endl;
			//this_thread::sleep_for(chrono::milliseconds(500));
		}
	}

	void decrement()
	{
		for (int i = 0; i < 10; ++i)
		{
			m_value -= 1;
			cout << "decrement number: " << m_value.load()
				<< ", theadID: " << this_thread::get_id() << endl;
			//this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
	// atomic<int> == atomic_int
	atomic_int m_value = 10;
};

// ----------------------------------------------------------------

struct CounterText
{
	void increment()
	{
		for (int i = 0; i < 10; ++i)
		{
			//lock_guard<mutex> locker(m_mutex);
			m_mutex.lock();
			m_value++;
			cout << "increment number: " << m_value
				<< ", theadID: " << this_thread::get_id() << endl;
			m_mutex.unlock();
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}

	void decrement()
	{
		for (int i = 0; i < 10; ++i)
		{
			//lock_guard<mutex> locker(m_mutex);
			m_mutex.lock();
			m_value--;
			cout << "decrement number: " << m_value
				<< ", theadID: " << this_thread::get_id() << endl;
			m_mutex.unlock();
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}

	int m_value = 0;
	mutex m_mutex;
};

// -------------- 互斥锁版本 ----------------
static void _thread_004_text(void)
{
	CounterText c;
	auto increment = bind(&CounterText::increment, &c);
	auto decrement = bind(&CounterText::decrement, &c);
	thread t1(increment);
	thread t2(decrement);

	t1.join();
	t2.join();
}

// -------------- 原子变量版本 ----------------
static void _thread_004_nb(void)
{
	Counter c;
	auto increment = bind(&Counter::increment, &c);
	auto decrement = bind(&Counter::decrement, &c);
	thread t1(increment);
	thread t2(decrement);

	t1.join();
	t2.join();
}

void thread_004(void)
{
	_thread_004_text();
	_thread_004_nb();
}