#include <iostream>
#include <queue>
#include <vector>
#include <utility>

void stl_0144(void)
{
	{
		//std::priority_queue<int> pq{ 1,4,3,2,3,-1,2 }; // ��֧��ֱ�ӳ�ʼ��
		std::priority_queue<int> pq; // Ĭ���Ǵ���� (����ȳ�)
		pq.push(2);
		pq.push(-2);
		pq.push(21);
		pq.push(5);

		while (pq.size())
		{
			std::cout << pq.top() << " ";
			pq.pop();
		}
	}
	std::cout << "\n\n";
	{
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // ָ��ΪС����
		pq.push(2);
		pq.push(-2);
		pq.push(21);
		pq.push(5);

		while (pq.size())
		{
			std::cout << pq.top() << " ";
			pq.pop();
		}
	}
	std::cout << "\n\n";
	{
		auto fun = [](const std::pair<const char*, int>& f1, const std::pair<const char*, int>& f2) {
			return f1.second > f2.second; // f1 > f2 (true) �򽻻� (����)
			};
		std::priority_queue<std::pair<const char*, int>, std::vector<std::pair<const char*, int>>, decltype(fun)> pq(fun);
		pq.push({"a", 2});
		pq.push({"b", -2});
		pq.push({"c", 21}); 
		pq.push({"d", 5});

		while (pq.size())
		{
			std::cout << pq.top().first << " " << pq.top().second << "\n";
			pq.pop();
		}
	}
}