#include <iostream>
#include <queue>

using namespace std;

// ��ϰ
static void _demo_(void)
{
	// ����n����, ����ǵ�����������������Ҳ��Ż�, ����Żض�β
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
		if ((cs & 1) == 1) // ����
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
	// ���� �� �����������
	queue <int> q;

	// ���Ԫ��
	q.push(1);
	q.push(2);	// ��ǰ�ṹ:
	q.push(3);	// ��ͷ <-- 1 2 3 <-- ��β

	// ��ջһ�� û�б���
	// ֻ��ȡ Ԫ��
	cout << q.back() /* ��ȡ��βԪ�� */ << " " << q.front() /* ��ȡ��ͷԪ�� */ << endl;

	// ��ȡ����Ԫ�ظ���
	cout << "��ǰ����Ԫ�ظ���: " << q.size() << endl;

	// �Ӷ�ͷ����һ��Ԫ��
	q.pop();	

	cout << "��ǰ����Ԫ�ظ���: " << q.size() << endl;


	while (!q.empty())	// �ж϶����Ƿ�Ϊ��, 1�ǿ�, 0�ǿ� (��֮ǰ������һ��)
	{
		cout << q.front() << " ";
		q.pop();
	}

	// ��ϰ
	_demo_();
}