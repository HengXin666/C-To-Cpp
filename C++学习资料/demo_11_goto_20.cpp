#include <iostream>
#include <cstdlib>	// ���������
#include <ctime>	// ϵͳʱ��

using namespace std;

void demo_11(void)
{
	int put = 0;
	cout << "������һ������:";
	cin >> put;

	for (int i = 31; i >= 0; --i)
	{
		if ((i + 1) % 4 == 0)
			cout << " ";
		cout << ((put >> i) & 1);
	}
}

#define DECK 54				// һ���Ƶ��Ƶ�����
#define PLAYER_NUM 3		// �������
#define LICENSING_DELAY 200 // �����ӳ� (��λ ms)
static struct PlayerData
{
	char name[36] = "δ�����û�";	// �����
	char brand[17];					// ��
	bool tag = 0;					// 0��ũ��, 1�ǵ��� (����ûʲô��)
};

static const char* str[] = { "����", "����", "÷��", "����", "����", "С��" };

static PlayerData* _demo_12_playerData(int num);
static void _demo_12_playerData_free(PlayerData** res);
static char* _demo_12_xiPai(void);																			// ϴ��
static void _demo_12_xianshiPaiData(char data);																// ��ʾ��
static void _demo_12_printPai(PlayerData playerMen[PLAYER_NUM], int play_id, int pai_position);				// ��ʾȫ����ҵ���
static void _demo_12_faPai(char* res, PlayerData playerMen[PLAYER_NUM]);									// ����
static void _demo_12_xiPai_free(char** res);

static void _demo_12_xianshiPaiData(char data)
{
	char ch;
	if (data <= 51)
	{
		ch = data % 13;
		cout << str[data % 4];
		if (ch < 10 && ch > 0)	// ������ A JQK
		{
			cout << char('0' + ch);
		}
		else
		{
			switch (ch)
			{
			case 0:
			{
				cout << 'A';
				break;
			}
			case 10:
			{
				cout << 'J';
				break;
			}
			case 11:
			{
				cout << 'Q';
				break;
			}
			case 12:
			{
				cout << 'K';
				break;
			}
			default:
				break;
			}
		}
	}
	else
	{
		if (data == 52)
		{
			cout << str[4];
		}
		else
		{
			cout << str[5];
		}
	}
}

static PlayerData* _demo_12_playerData(int num)
{
	PlayerData* res = (PlayerData*)malloc(sizeof(PlayerData) * num);
	for (int i = 0; i < num; ++i)
	{
		system("cls");
		cout << "��������� " << i + 1 << " ������:";
		cin >> res[i].name;
	}

	return res;
}

static void _demo_12_playerData_free(PlayerData** res)
{
	free(*res);
	*res = nullptr;
}

static char* _demo_12_xiPai(void)	// ϴ��
{
	// ����һ�� ֵΪ 0 - 53 ��, ���ظ����ַ�����
	char* res = (char*)malloc(sizeof(char) * DECK);
	srand(time(NULL));
	for (int i = 0, j, k; i < DECK; ++i)
	{
		while (true)
		{
			j = rand() % DECK;
			for (k = 0; k < i; ++k)
			{
				if (res[k] == j)
					break;
			}

			if (k == i)
			{
				break;
			}
		}
		res[i] = j;
	}

	return res;
}

static void _demo_12_printPai(PlayerData playerMen[PLAYER_NUM], int play_id, int pai_position)				// ��ʾȫ����ҵ���
{
	char ch;
	system("cls");
	for (int i = 0, j, k; i < PLAYER_NUM; ++i)
	{	
		cout << "��� [" << playerMen[i].name << "] ����:";
		k = pai_position + (i <= play_id);
		for (j = 0; j < k ; ++j)
		{
			cout << " ";
			_demo_12_xianshiPaiData(playerMen[i].brand[j]);
		}
		cout << endl;
	}
}

static void _demo_12_faPai(char* res, PlayerData playerMen[PLAYER_NUM])		// ����
{
	time_t if_time = clock() + LICENSING_DELAY;
	for (int i = 0, j, k = 0; i < DECK - 3; i += 3, ++k)
	{
		for (j = 0; j < PLAYER_NUM; ++j)
		{
			playerMen[j].brand[k] = res[i + j];
			while (clock() - if_time < LICENSING_DELAY)
				;
			if_time = clock();
			_demo_12_printPai(playerMen, j, k);
		}
	}

	cout << endl << "������: ";
	for (int i = DECK - 3; i < DECK; ++i)
	{
		cout << " ";
		while (clock() - if_time < LICENSING_DELAY * 2)
			;
		if_time = clock();
		_demo_12_xianshiPaiData(res[i]);
	}
	cout << endl;
}

static void _demo_12_xiPai_free(char** res)
{
	free(*res);
	*res = nullptr;
}

void demo_12(void)
{
	// ʵ��ϴ�Ʒ���(������)
	PlayerData* arr = _demo_12_playerData(PLAYER_NUM);
	
	char* pai = _demo_12_xiPai();
	_demo_12_faPai(pai, arr);
	_demo_12_xiPai_free(&pai);
	_demo_12_playerData_free(&arr);
}

void demo_13(void)
{
	class JuiXin
	{
	public:
		int a, b;
		JuiXin(int _a, int _b)
		{
			a = _a;
			b = _b;
		}

		void put_if_ZhenFanXin(void)
		{
			if (a == b)
				cout << "������" << endl;
			else
				cout << "����������" << endl;
		}

		void put_S(void)
		{
			cout << "�����: " << a * b << endl;
		}
	};

	JuiXin x(4, 4);
	JuiXin y(3, 4);
	x.put_if_ZhenFanXin();
	x.put_S();

	y.put_if_ZhenFanXin();
	y.put_S();
}

static class MyZoo
{
public:
	MyZoo() {

	}

	MyZoo(string name, int arg)
	{
		this->name = name;
		this->arg = arg;
	}

	~MyZoo() {

	}

	friend bool operator < (MyZoo& C_1, MyZoo& C_2);
	friend bool operator <= (MyZoo& C_1, MyZoo& C_2);
	friend bool operator >= (MyZoo& C_1, MyZoo& C_2);
	friend bool operator > (MyZoo& C_1, MyZoo& C_2);

private:
	string name;
	int arg;
};

static bool operator<(MyZoo& C_1, MyZoo& C_2)
{
	return C_1.arg < C_2.arg ? 1 : 0;
}

static bool operator <= (MyZoo& C_1, MyZoo& C_2)
{
	return C_1.arg <= C_2.arg ? 1 : 0;
}

static bool operator >= (MyZoo& C_1, MyZoo& C_2)
{
	return C_1.arg >= C_2.arg ? 1 : 0;
}

static bool operator > (MyZoo& C_1, MyZoo& C_2)
{
	return C_1.arg > C_2.arg ? 1 : 0;
}

void demo_14(void)
{
	MyZoo cat = { "èè", 2 };
	MyZoo deg = { "����", 3 };
	if (cat > deg)
		cout << " ";
	else
		cout << "xiao" << endl;
}

namespace
{
	class Animal
	{
	public:
		void who()
		{
			cout << "����: " << name << " ����: " << zhiLian << " ��" << endl;
		}

		Animal(string name, int zhiLian): name(name), zhiLian(zhiLian){}

	private:
		string name;
		int zhiLian;	// ����
	};

	class Lion : public Animal
	{
		using Animal::Animal;
	};

	class Aardvark : public Animal
	{
		using Animal::Animal;
	};
}

void demo_15(void)
{
	/* ��ϰ��:
	����һ������Animal������������˽�����ݳ�Ա��
			һ����string,�洢��������ƣ�����"Fido"��"Yogi" )��
			��һ����������Աweight, �����ö������������λ�ǰ�)��
	���໹����һ��������Ա����who()��
			��������ʾһ����Ϣ������Animal��������ƺ�������

	��Animal�����������࣬����������Lion��Aardvark��
		�ٱ�дһ��main()����������Lion��Aardvark����("Leo"��400��; "Algernon", 50������
		Ϊ������������who()��Ա��
		
	˵��who()��Ա���������������Ǽ̳е����ġ�
	*/
	Lion l("Leo", 400);
	l.who();

	Aardvark a("Algernon", 50);
	a.who();
}

namespace
{
	class JiShuanQi
	{
	public:
		virtual ~JiShuanQi() {}
		JiShuanQi(){}
		JiShuanQi(char xz) : xz(xz){}

		// [����]: ��ȫ���Բ���Ҫ������������, ֻ��Ҫһ��������, ��a��������~ ܳ, ���ǸĻ�����...
		virtual double shuanMuYunShuan(void) = 0;	// ˫Ŀ����
		virtual double danMuYunShuan(void) = 0;		// ��Ŀ����

		void putReturn(void)
		{
			switch (this->xz)
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '8':
				cout << "������������������ a, b: " << endl;
				cin >> this->a >> this->b;
				cout << "[Info]: �������� " << shuanMuYunShuan() << endl;
				break;
			case '6':	// ƽ��
			case '7':	// �ײ�
				cout << "������������һ���� a: " << endl;
				cin >> a;
				cout << "[Info]: �������� " << danMuYunShuan() << endl;
				break;
			default:
				cout << "��������ȷ������!" << endl;
				break;
			}
		}

	public:
		double a, b;
		char xz;
	};

	class MiYunSuan : public JiShuanQi
	{
		// ������
	public:
		MiYunSuan(char xz) : JiShuanQi(xz){}

		virtual double shuanMuYunShuan(void)
		{
			double res = 1;
			for (int(this->b); this->b > 1; --this->b)
			{
				res *= this->a;
			}
			
			return res;
		}
		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class JiaFa : public JiShuanQi
	{
		// �ӷ�
	public:
		JiaFa(char xz) : JiShuanQi(xz) {}
		virtual double shuanMuYunShuan(void)
		{
			return this->a + this->b;
		}

		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class JianFa : public JiShuanQi
	{
		// ����
	public:
		JianFa(char xz) : JiShuanQi(xz) {}
		virtual double shuanMuYunShuan(void)
		{
			return this->a - this->b;
		}

		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class ChenFa : public JiShuanQi
	{
		// �˷�
	public:
		ChenFa(char xz) : JiShuanQi(xz) {}
		virtual double shuanMuYunShuan(void)
		{
			return this->a * this->b;
		}

		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class CuFa : public JiShuanQi
	{
		// ����
	public:
		CuFa(char xz) : JiShuanQi(xz) {}
		virtual double shuanMuYunShuan(void)
		{
			return this->a / this->b;
		}

		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class QiuYu : public JiShuanQi
	{
		// ȡ��
	public:
		QiuYu(char xz) : JiShuanQi(xz) {}
		virtual double shuanMuYunShuan(void)
		{
			return int(this->a) % int(this->b);
		}

		virtual double danMuYunShuan(void) {
			return -1;
		}
	};

	class PingFan : public JiShuanQi
	{
		// ƽ��
	public:
		PingFan(char xz) : JiShuanQi(xz) {}
		virtual double danMuYunShuan(void)
		{
			return this->a * this->a;
		}

		virtual double shuanMuYunShuan(void)
		{
			return -1;
		}
	};

	class JieChen : public JiShuanQi
	{
		// �ײ�
	public:
		JieChen(char xz) : JiShuanQi(xz) {}
		virtual double danMuYunShuan(void)
		{
			int sun = 1;
			for (int(this->a); this->a > 1; --this->a)
			{
				sun *= this->a;
			}

			return sun;
		}

		virtual double shuanMuYunShuan(void)
		{
			return -1;
		}
	};
}

static void _demo_16_printChaiDan(void)
{
	cout << "=-=-=-=-=-=-=-=-=" << endl
		<< "=   1. �ӷ�     =" << endl
		<< "=   2. ����     =" << endl
		<< "=   3. �˷�     =" << endl
		<< "=   4. ����     =" << endl
		<< "=   5. ȡ��     =" << endl
		<< "=   6. ƽ��     =" << endl
		<< "=   7. �ײ�     =" << endl
		<< "=   8. ����     =" << endl
		<< "=   Q. �˳�     =" << endl
		<< "=-=-=-=-=-=-=-=-=" << endl;
}

static void _demo_16_class_main(JiShuanQi* J)
{
	J->putReturn();
	delete J;
}

static void _demo_16_getReturn(void)
{
	char xz;
	A:
	cout << "��ѡ��һ�����" << endl;
	cin >> xz;
	switch (xz)
	{
	case '1':
		_demo_16_class_main(new JiaFa(xz));
		break;
	case '2':
		_demo_16_class_main(new JianFa(xz));
		break;
	case '3':
		_demo_16_class_main(new ChenFa(xz));
		break;
	case '4':
		_demo_16_class_main(new CuFa(xz));
		break;
	case '5':
		_demo_16_class_main(new QiuYu(xz));
		break;
	case '8':
		_demo_16_class_main(new MiYunSuan(xz));
		break;
	case '6':	// ƽ��
		_demo_16_class_main(new PingFan(xz));
		break;
	case '7':	// �ײ�
		_demo_16_class_main(new JieChen(xz));
		break;
	case 'Q':
	case 'q':
		exit(0);
		break;
	default:
		cout << "��������ȷ������!" << endl;
		goto A;
	}
}

void demo_16(void)
{
	// ʵ��һ��������
	while (true)
	{
		system("cls");
		_demo_16_printChaiDan();
		_demo_16_getReturn();
		system("pause");
	}
}

template <class T>
static void _demo_17_get(T arr[], int arrSize)
{
	T max = arr[0], min = arr[0];
	double pinJun = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		pinJun += arr[i];
	}
	cout << "Max = " << max << endl
		<< "Min = " << min << endl
		<< "ƽ��ֵ = " << pinJun / arrSize << endl << endl;
}

void demo_17(void)
{
	// ��дһ������ģ��, �ֱ����һ�������������ݵ����ֵ,��Сֵ��ƽ��ֵ
	int int_arr[] = { 12, 34, 56, 11, 33, 90, 88 };
	double d_arr[] = { 3.14, 4.55, 7.88 };
	_demo_17_get<int>(int_arr, 7);	// ��Ȼָ��ģ��Ҳ��
	_demo_17_get(d_arr, 3);
}

void demo_18(void)
{
	// ����lambda��ɣ�����һ���ַ�����ͳ���ַ�����ĳ���ַ��ĸ���
	// ���� abcdabc
	// ���� a
	// ��� 2
	string str;
	char ch;
	cin >> str >> ch;
	cout << [=]{
		int cs = 0;
		for (char it : str)
		{
			if (it == ch)
				++cs;
		}
		return cs;
	}();
}
