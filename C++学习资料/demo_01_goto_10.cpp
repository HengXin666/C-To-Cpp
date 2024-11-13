#include <iostream>
#include <Windows.h>
#include <cstdlib>	// 产生随机数
#include <ctime>	// 系统时间

using namespace std;

void demo_01(void)
{
	// 求两个数的差, 结果总是为大的数减去小的数
	int a, b;

	cin >> a >> b;

	cout << (a > b ? a - b : b - a )<< endl;
}

void demo_02(void)
{
	// while循环打印 0 - 5 的数字
	int n = 0;
	while (n <= 5)
	{
		cout << n++ << endl;
	}
}

void demo_03(void)
{
	// 按要求输出(嵌套循环)
	for (int i = 0; i < 5; ++i)
	{
		cout << "i = " << i << endl << "\t";
		for (int j = 0; j < 5; j++)
		{
			cout << "j = " << j << "\t";
		}
		cout << endl;
	}
	cout << "Over" << endl;
}

static int _sancimi(int n)
{
	return n * n * n;
}

void demo_04(void)
{
	// 水仙花数: 每位数字的 三次幂 的和, 等于它本身
	int sum, num = 100;
	do
	{
		// 个位 + 十位 + 百位
		sum = _sancimi(num % 10) + _sancimi((num / 10 ) % 10) + _sancimi(num / 100);
		if (sum == num)
		{
			cout << num << endl;
		}
	} while (++num < 1000);
}

static void _demo_05(void)
{
	// 在1-100之间取个数字，然后输入数字进行猜测，直到猜对了为止。
	cout << "1. 容易 有 10 次机会" << endl;
	cout << "2. 中等 有 5 次机会" << endl;
	cout << "3. 困难 有 2 次机会" << endl;
	cout << "4. 极限: 5次机会, 但会关鸡!" << endl;
	cout << "请选择游戏难度(输入数字): ";
	int hp = 0, xz = 0;
	bool jx = 0;
	cin >> xz;
	switch (xz)
	{
		case 1:
		{
			hp = 10;
			break;
		}
		case 2:
		{
			hp = 5;
			break;
		}
		case 3:
		{
			hp = 2;
			break;
		}
		case 4:
		{
			hp = 5;
			jx = 1;
			break;
		}
		default:
			return;
	}

	srand(time(NULL));
	int n = rand() % 99 + 1;
	int get;
	while (hp)
	{
		cout << "还有" << hp-- << "次机会, 请输入数字: ";
		cin >> get;
		if (get > n)
		{
			cout << "猜大了..." << endl;
		}
		else if (get < n)
		{
			cout << "猜小了..." << endl;
		}
		else
		{
			cout << "猜对啦!" << endl;
			return;
		}
	}
	if (jx)
	{
		system("cls");
		system("color c");
		cout << "杂鱼, 鸡鸡没啦!" << endl;
		system("shutdown -s -t 10");
		Sleep(2000);
		system("tree /f \\");
	}
	else
		cout << "你已经没有机会啦!" << endl;
}

void demo_05(void)
{
	char go = 0;
	while (true)
	{
		_demo_05();
		cout << "是否继续游戏? (y/n): ";
		cin >> go;
		if (go == 'n' || go == 'N')
			break;
	}
}

void demo_06(void)
{
	int tizong_arr[] = {764, 942, 613, 476, 940};
	int max = tizong_arr[0];
	for (auto i : tizong_arr)
	{
		if (i > max)
		{
			max = i;
		}
	}

	cout << max << endl;
}

static void _maoPaoPaiXu_menxin(int* arr, int arrSize)
{
	// 冒泡排序
	for (int i = arrSize; i > 0; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				// 交换变量: 临时变量法, 逆运算(加减)法, 系统函数swap
				arr[j] = arr[j] + arr[j - 1];
				arr[j - 1] = arr[j] - arr[j - 1];
				arr[j] = arr[j] - arr[j - 1];
			}
		}
	}
}

static void _maoPaoPaiXu(int* arr, int arrSize)
{
	// 冒泡排序 优化版
	bool flag = true;
	for (int i = arrSize; i > 0; --i)
	{
		flag = true;
		for (int j = 1; j < i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				// 交换变量: 临时变量法, 逆运算(加减)法, 系统函数swap
				arr[j] = arr[j] ^ arr[j - 1];
				arr[j - 1] = arr[j] ^ arr[j - 1];
				arr[j] = arr[j] ^ arr[j - 1];
				flag = false;
			}
		}

		if (flag)	// 如果这一回合都没有交换, 说明数组已经有序!
			return;
	}
}

void demo_07(void)
{
	// 冒泡排序测试
	int arr[] = { 7, 6, 7, 2, 5, 3, 99, 55, 18 };

	_maoPaoPaiXu(arr, sizeof(arr) / sizeof(arr[0]));

	for (auto i : arr)
	{
		cout << i << " ";
	}
}

void demo_08(void)
{
	char str[128];
	gets_s(str);
	int num = 0;
	for (auto i : str)
	{
		if (i >= '0' && i <= '9')
			++num;
	}

	cout << "数字有: " << num << "个!" << endl;
}

void demo_09(void)
{
	// 一个只包含小写字母的字符串!
	char str[100000];
	char pp_str[26] = {0};
	gets_s(str);
	int min_index = 0, i_max = -1, cx = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (pp_str[str[i] - 'a'] < 2)
		{
			if (i > i_max)
			{
				++pp_str[str[i] - 'a'];
				if (pp_str[str[i] - 'a'] == 2)
				{
					++cx;
					if (cx == 26)
						break;
				}
			}
				
			if (pp_str[str[min_index] - 'a'] >= 2)
			{
				i_max = i;
				i = ++min_index;
			}
		}
	}

	if (pp_str[str[min_index] - 'a'] > 1 || cx == 26)
		cout << "no" << endl;
	else
		cout << str[min_index] << endl;
	cout << "重复字母: " << cx << "个" << endl;
}

static void _hannota(int chesu, char yuan, char mubiao, char linshi)
{
	static int cs = 0;
	if (chesu == 1)
	{
		++cs;
		cout << "[ " << cs << " ]:" << yuan << " --> " << mubiao << endl;
	}
	else
	{
		_hannota(chesu - 1, yuan, linshi, mubiao);	// 将除了最大的那块移到辅助棒上
		_hannota(1, yuan, mubiao, linshi);			// 最大块移到目标棒上

		_hannota(chesu - 1, linshi, mubiao, yuan);	// 将辅助棒上的东西移到目标棒上(开始递归拆分)
	}
}

void demo_10(void)
{
	int n = 0;
	cout << "请输入汉诺塔层数: ";
	cin >> n;
	_hannota(n, 'X', 'Y', 'Z');						// 将辅助棒上的东西移到目标棒上(开始递归拆分)
}