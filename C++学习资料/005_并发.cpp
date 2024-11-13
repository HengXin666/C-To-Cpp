#include <iostream>
#include <future>
#include <format>
using namespace std;

// ����һ����������������������������ͨ��promise�������ǵĻ�
void product(promise<int>&& intPromise, int v1, int v2)
{
	intPromise.set_value(v1 * v2);  // ��v1��v2�Ļ�����Ϊpromise��ֵ
}

void getAnswer(promise<int> intPromise)
{
	this_thread::sleep_for(2s); // ģ���ʱ����
	intPromise.set_value(100); // ����promise��ֵΪ100
}

static void _005_new_text(void)
{
	promise<int> answerPromise; // ����һ��promise����
	auto fut = answerPromise.get_future(); // ��ȡ��promise������future����
	jthread productThread(getAnswer, move(answerPromise)); // ����һ�����̣߳�����promise������Ϊ�������ݸ�getAnswer����

	future_status status{};
	do
	{
		status = fut.wait_for(0.5s); // �ȴ�0.5�룬����첽�����Ƿ����
		cout << "���δ׼����� " << endl;
	} while (status != future_status::ready); // ѭ���ȴ���ֱ���첽�������

	cout << format("answer is {}\n", fut.get()); // ����첽����Ľ��
}


// ������
void new_cpp20_005(void)
{
	int num1 = 200;
	int num2 = 300;

	// ����һ��promise���󣬲���ȡ��֮������future����
	promise<int> productPromise;
	future<int> productResult = productPromise.get_future();

	// ����һ���µ��̣߳�����product()����������promise������Ϊ�������ݸ��ú���
	jthread productThread(product, move(productPromise), num1, num2);

	// �ȴ��첽������ɣ���������������̨
	cout << format("product is {}", productResult.get()) << endl;

	// -----
	_005_new_text();
}
