#include <iostream>
#include <Windows.h>
#include <cstdlib>	// ���������
#include <ctime>	// ϵͳʱ��

using namespace std;

void demo_01(void)
{
	// ���������Ĳ�, �������Ϊ�������ȥС����
	int a, b;

	cin >> a >> b;

	cout << (a > b ? a - b : b - a )<< endl;
}

void demo_02(void)
{
	// whileѭ����ӡ 0 - 5 ������
	int n = 0;
	while (n <= 5)
	{
		cout << n++ << endl;
	}
}

void demo_03(void)
{
	// ��Ҫ�����(Ƕ��ѭ��)
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
	// ˮ�ɻ���: ÿλ���ֵ� ������ �ĺ�, ����������
	int sum, num = 100;
	do
	{
		// ��λ + ʮλ + ��λ
		sum = _sancimi(num % 10) + _sancimi((num / 10 ) % 10) + _sancimi(num / 100);
		if (sum == num)
		{
			cout << num << endl;
		}
	} while (++num < 1000);
}

static void _demo_05(void)
{
	// ��1-100֮��ȡ�����֣�Ȼ���������ֽ��в²⣬ֱ���¶���Ϊֹ��
	cout << "1. ���� �� 10 �λ���" << endl;
	cout << "2. �е� �� 5 �λ���" << endl;
	cout << "3. ���� �� 2 �λ���" << endl;
	cout << "4. ����: 5�λ���, ����ؼ�!" << endl;
	cout << "��ѡ����Ϸ�Ѷ�(��������): ";
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
		cout << "����" << hp-- << "�λ���, ����������: ";
		cin >> get;
		if (get > n)
		{
			cout << "�´���..." << endl;
		}
		else if (get < n)
		{
			cout << "��С��..." << endl;
		}
		else
		{
			cout << "�¶���!" << endl;
			return;
		}
	}
	if (jx)
	{
		system("cls");
		system("color c");
		cout << "����, ����û��!" << endl;
		system("shutdown -s -t 10");
		Sleep(2000);
		system("tree /f \\");
	}
	else
		cout << "���Ѿ�û�л�����!" << endl;
}

void demo_05(void)
{
	char go = 0;
	while (true)
	{
		_demo_05();
		cout << "�Ƿ������Ϸ? (y/n): ";
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
	// ð������
	for (int i = arrSize; i > 0; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				// ��������: ��ʱ������, ������(�Ӽ�)��, ϵͳ����swap
				arr[j] = arr[j] + arr[j - 1];
				arr[j - 1] = arr[j] - arr[j - 1];
				arr[j] = arr[j] - arr[j - 1];
			}
		}
	}
}

static void _maoPaoPaiXu(int* arr, int arrSize)
{
	// ð������ �Ż���
	bool flag = true;
	for (int i = arrSize; i > 0; --i)
	{
		flag = true;
		for (int j = 1; j < i; ++j)
		{
			if (arr[j - 1] > arr[j])
			{
				// ��������: ��ʱ������, ������(�Ӽ�)��, ϵͳ����swap
				arr[j] = arr[j] ^ arr[j - 1];
				arr[j - 1] = arr[j] ^ arr[j - 1];
				arr[j] = arr[j] ^ arr[j - 1];
				flag = false;
			}
		}

		if (flag)	// �����һ�غ϶�û�н���, ˵�������Ѿ�����!
			return;
	}
}

void demo_07(void)
{
	// ð���������
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

	cout << "������: " << num << "��!" << endl;
}

void demo_09(void)
{
	// һ��ֻ����Сд��ĸ���ַ���!
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
	cout << "�ظ���ĸ: " << cx << "��" << endl;
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
		_hannota(chesu - 1, yuan, linshi, mubiao);	// �����������ǿ��Ƶ���������
		_hannota(1, yuan, mubiao, linshi);			// �����Ƶ�Ŀ�����

		_hannota(chesu - 1, linshi, mubiao, yuan);	// ���������ϵĶ����Ƶ�Ŀ�����(��ʼ�ݹ���)
	}
}

void demo_10(void)
{
	int n = 0;
	cout << "�����뺺ŵ������: ";
	cin >> n;
	_hannota(n, 'X', 'Y', 'Z');						// ���������ϵĶ����Ƶ�Ŀ�����(��ʼ�ݹ���)
}