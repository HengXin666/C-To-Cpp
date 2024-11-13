#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <functional>
#include <condition_variable>
using namespace std;

class SyncQueue
{
public:
	SyncQueue(int maxSize) : m_maxSize(maxSize) {}

	void put(const int& x)
	{
		unique_lock<mutex> locker(m_mutex);
		// 判断任务队列是不是已经满了
		while (m_queue.size() == m_maxSize)
		{
			cout << "任务队列已满, 请耐心等待..." << endl;
			// 阻塞线程
			m_notFull.wait(locker);
		}
		// 将任务放入到任务队列中
		m_queue.push_back(x);
		cout << x << " 被生产" << endl;
		// 通知消费者去消费
		m_notEmpty.notify_one();
	}

	int take()
	{
		unique_lock<mutex> locker(m_mutex);
		while (m_queue.empty())
		{
			cout << "任务队列已空，请耐心等待。。。" << endl;
			m_notEmpty.wait(locker);
		}
		// 从任务队列中取出任务(消费)
		int x = m_queue.front();
		m_queue.pop_front();
		// 通知生产者去生产
		m_notFull.notify_one();
		cout << x << " 被消费" << endl;
		return x;
	}

	//bool empty()
	//{
	//	lock_guard<mutex> locker(m_mutex);
	//	return m_queue.empty();
	//}

	//bool full()
	//{
	//	lock_guard<mutex> locker(m_mutex);
	//	return m_queue.size() == m_maxSize;
	//}

	//int size()
	//{
	//	lock_guard<mutex> locker(m_mutex);
	//	return m_queue.size();
	//}

private:
	list<int> m_queue;     // 存储队列数据
	mutex m_mutex;         // 互斥锁
	condition_variable m_notEmpty;   // 不为空的条件变量
	condition_variable m_notFull;    // 没有满的条件变量
	int m_maxSize;         // 任务队列的最大任务个数
};

void thread_003(void)
{
	SyncQueue taskQ(50);
	auto produce = bind(&SyncQueue::put, &taskQ, placeholders::_1);
	auto consume = bind(&SyncQueue::take, &taskQ);
	thread t1[3];
	thread t2[3];
	for (int i = 0; i < 3; ++i)
	{
		t1[i] = thread(produce, i + 100);
		t2[i] = thread(consume);
	}

	for (int i = 0; i < 3; ++i)
	{
		t1[i].join();
		t2[i].join();
	}
}