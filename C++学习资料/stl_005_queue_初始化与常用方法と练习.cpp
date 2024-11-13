#include <iostream>
#include <queue>

using namespace std;

// 练习
static void _demo_(void)
{
	// 输入n张牌, 如果是第奇数张牌则输出并且不放回, 否则放回队尾
	int n;
	cin >> n;
	queue <int> s;
	for (int i = 0, tmp; i < n; ++i)
	{
		cin >> tmp;
		s.push(tmp);
	}

	int cs = 1;
	while (!s.empty())
	{
		if ((cs & 1) == 1) // 奇数
		{
			cout << s.front() << " ";
			s.pop();
		}
		else
		{
			int tmp = s.front();
			s.pop();
			s.push(tmp);
		}
		++cs;
	}
}

void stl_005(void)
{
	// 声明 和 其他容器差不多
	queue <int> q;

	// 添加元素
	q.push(1);
	q.push(2);	// 当前结构:
	q.push(3);	// 队头 <-- 1 2 3 <-- 队尾

	// 和栈一样 没有遍历
	// 只有取 元素
	cout << q.back() /* 获取队尾元素 */ << " " << q.front() /* 获取队头元素 */ << endl;

	// 获取队列元素个数
	cout << "当前队列元素个数: " << q.size() << endl;

	// 从队头出队一个元素
	q.pop();	

	cout << "当前队列元素个数: " << q.size() << endl;


	while (!q.empty())	// 判断队列是否为空, 1是空, 0非空 (和之前的容器一样)
	{
		cout << q.front() << " ";
		q.pop();
	}

	// 练习
	_demo_();
}