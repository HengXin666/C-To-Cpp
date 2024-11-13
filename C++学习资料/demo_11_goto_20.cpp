#include <iostream>
#include <cstdlib>	// 产生随机数
#include <ctime>	// 系统时间

using namespace std;

void demo_11(void)
{
	int put = 0;
	cout << "请输入一个整数:";
	cin >> put;

	for (int i = 31; i >= 0; --i)
	{
		if ((i + 1) % 4 == 0)
			cout << " ";
		cout << ((put >> i) & 1);
	}
}

#define DECK 54				// 一副牌的牌的数量
#define PLAYER_NUM 3		// 玩家数量
#define LICENSING_DELAY 200 // 发牌延迟 (单位 ms)
static struct PlayerData
{
	char name[36] = "未命名用户";	// 玩家名
	char brand[17];					// 牌
	bool tag = 0;					// 0是农民, 1是地主 (现在没什么用)
};

static const char* str[] = { "黑桃", "红桃", "梅花", "方块", "大王", "小王" };

static PlayerData* _demo_12_playerData(int num);
static void _demo_12_playerData_free(PlayerData** res);
static char* _demo_12_xiPai(void);																			// 洗牌
static void _demo_12_xianshiPaiData(char data);																// 显示牌
static void _demo_12_printPai(PlayerData playerMen[PLAYER_NUM], int play_id, int pai_position);				// 显示全部玩家的牌
static void _demo_12_faPai(char* res, PlayerData playerMen[PLAYER_NUM]);									// 发牌
static void _demo_12_xiPai_free(char** res);

static void _demo_12_xianshiPaiData(char data)
{
	char ch;
	if (data <= 51)
	{
		ch = data % 13;
		cout << str[data % 4];
		if (ch < 10 && ch > 0)	// 不包含 A JQK
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
		cout << "请输入玩家 " << i + 1 << " 的名字:";
		cin >> res[i].name;
	}

	return res;
}

static void _demo_12_playerData_free(PlayerData** res)
{
	free(*res);
	*res = nullptr;
}

static char* _demo_12_xiPai(void)	// 洗牌
{
	// 返回一个 值为 0 - 53 的, 不重复的字符数组
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

static void _demo_12_printPai(PlayerData playerMen[PLAYER_NUM], int play_id, int pai_position)				// 显示全部玩家的牌
{
	char ch;
	system("cls");
	for (int i = 0, j, k; i < PLAYER_NUM; ++i)
	{	
		cout << "玩家 [" << playerMen[i].name << "] 的牌:";
		k = pai_position + (i <= play_id);
		for (j = 0; j < k ; ++j)
		{
			cout << " ";
			_demo_12_xianshiPaiData(playerMen[i].brand[j]);
		}
		cout << endl;
	}
}

static void _demo_12_faPai(char* res, PlayerData playerMen[PLAYER_NUM])		// 发牌
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

	cout << endl << "地主牌: ";
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
	// 实现洗牌发牌(斗地主)
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
				cout << "正方形" << endl;
			else
				cout << "不是正方形" << endl;
		}

		void put_S(void)
		{
			cout << "面积是: " << a * b << endl;
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
	MyZoo cat = { "猫猫", 2 };
	MyZoo deg = { "狗哥", 3 };
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
			cout << "名称: " << name << " 质量: " << zhiLian << " 磅" << endl;
		}

		Animal(string name, int zhiLian): name(name), zhiLian(zhiLian){}

	private:
		string name;
		int zhiLian;	// 质量
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
	/* 练习题:
	定义一个基类Animal，它包含两个私有数据成员，
			一个是string,存储动物的名称（例如"Fido"或"Yogi" )，
			另一个是整数成员weight, 包含该动物的重量（单位是磅)。
	该类还包含一个公共成员函数who()，
			它可以显示一个消息，给出Animal对象的名称和重量。

	把Animal用作公共基类，派生两个类Lion和Aardvark。
		再编写一个main()函数，创建Lion和Aardvark对象("Leo"，400磅; "Algernon", 50磅）。
		为派生类对象调用who()成员，
		
	说明who()成员在两个派生类中是继承得来的。
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

		// [批改]: 完全可以不需要区分两个函数, 只需要一个就行了, 用a就行了嘛~ 艹, 忘记改回来了...
		virtual double shuanMuYunShuan(void) = 0;	// 双目运算
		virtual double danMuYunShuan(void) = 0;		// 单目运算

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
				cout << "请输入待计算的两个数 a, b: " << endl;
				cin >> this->a >> this->b;
				cout << "[Info]: 计算结果是 " << shuanMuYunShuan() << endl;
				break;
			case '6':	// 平方
			case '7':	// 阶层
				cout << "请输入待计算的一个数 a: " << endl;
				cin >> a;
				cout << "[Info]: 计算结果是 " << danMuYunShuan() << endl;
				break;
			default:
				cout << "请输入正确的内容!" << endl;
				break;
			}
		}

	public:
		double a, b;
		char xz;
	};

	class MiYunSuan : public JiShuanQi
	{
		// 幂运算
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
		// 加法
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
		// 减法
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
		// 乘法
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
		// 除法
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
		// 取余
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
		// 平方
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
		// 阶层
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
		<< "=   1. 加法     =" << endl
		<< "=   2. 减法     =" << endl
		<< "=   3. 乘法     =" << endl
		<< "=   4. 除法     =" << endl
		<< "=   5. 取余     =" << endl
		<< "=   6. 平方     =" << endl
		<< "=   7. 阶层     =" << endl
		<< "=   8. 求幂     =" << endl
		<< "=   Q. 退出     =" << endl
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
	cout << "请选择一个序号" << endl;
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
	case '6':	// 平方
		_demo_16_class_main(new PingFan(xz));
		break;
	case '7':	// 阶层
		_demo_16_class_main(new JieChen(xz));
		break;
	case 'Q':
	case 'q':
		exit(0);
		break;
	default:
		cout << "请输入正确的内容!" << endl;
		goto A;
	}
}

void demo_16(void)
{
	// 实现一个计算器
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
		<< "平均值 = " << pinJun / arrSize << endl << endl;
}

void demo_17(void)
{
	// 编写一个函数模版, 分别求出一个组数里面数据的最大值,最小值和平均值
	int int_arr[] = { 12, 34, 56, 11, 33, 90, 88 };
	double d_arr[] = { 3.14, 4.55, 7.88 };
	_demo_17_get<int>(int_arr, 7);	// 当然指定模版也行
	_demo_17_get(d_arr, 3);
}

void demo_18(void)
{
	// 利用lambda完成：输入一个字符串，统计字符串的某个字符的个数
	// 输入 abcdabc
	// 输入 a
	// 输出 2
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
