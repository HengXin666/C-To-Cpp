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
		// �ж���������ǲ����Ѿ�����
		while (m_queue.size() == m_maxSize)
		{
			cout << "�����������, �����ĵȴ�..." << endl;
			// �����߳�
			m_notFull.wait(locker);
		}
		// ��������뵽���������
		m_queue.push_back(x);
		cout << x << " ������" << endl;
		// ֪ͨ������ȥ����
		m_notEmpty.notify_one();
	}

	int take()
	{
		unique_lock<mutex> locker(m_mutex);
		while (m_queue.empty())
		{
			cout << "��������ѿգ������ĵȴ�������" << endl;
			m_notEmpty.wait(locker);
		}
		// �����������ȡ������(����)
		int x = m_queue.front();
		m_queue.pop_front();
		// ֪ͨ������ȥ����
		m_notFull.notify_one();
		cout << x << " ������" << endl;
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
	list<int> m_queue;     // �洢��������
	mutex m_mutex;         // ������
	condition_variable m_notEmpty;   // ��Ϊ�յ���������
	condition_variable m_notFull;    // û��������������
	int m_maxSize;         // ������е�����������
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