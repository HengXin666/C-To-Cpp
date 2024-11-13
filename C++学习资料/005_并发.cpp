#include <iostream>
#include <future>
#include <format>
using namespace std;

// 定义一个函数，接受两个整数参数，并通过promise传递它们的积
void product(promise<int>&& intPromise, int v1, int v2)
{
	intPromise.set_value(v1 * v2);  // 将v1和v2的积设置为promise的值
}

void getAnswer(promise<int> intPromise)
{
	this_thread::sleep_for(2s); // 模拟耗时操作
	intPromise.set_value(100); // 设置promise的值为100
}

static void _005_new_text(void)
{
	promise<int> answerPromise; // 创建一个promise对象
	auto fut = answerPromise.get_future(); // 获取与promise关联的future对象
	jthread productThread(getAnswer, move(answerPromise)); // 创建一个新线程，并将promise对象作为参数传递给getAnswer函数

	future_status status{};
	do
	{
		status = fut.wait_for(0.5s); // 等待0.5秒，检查异步计算是否完成
		cout << "结果未准备完成 " << endl;
	} while (status != future_status::ready); // 循环等待，直到异步计算完成

	cout << format("answer is {}\n", fut.get()); // 输出异步计算的结果
}


// 主函数
void new_cpp20_005(void)
{
	int num1 = 200;
	int num2 = 300;

	// 创建一个promise对象，并获取与之关联的future对象
	promise<int> productPromise;
	future<int> productResult = productPromise.get_future();

	// 创建一个新的线程，调用product()函数，并将promise对象作为参数传递给该函数
	jthread productThread(product, move(productPromise), num1, num2);

	// 等待异步计算完成，并输出结果到控制台
	cout << format("product is {}", productResult.get()) << endl;

	// -----
	_005_new_text();
}
