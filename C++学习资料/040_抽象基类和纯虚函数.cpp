#include <iostream>

using namespace std;

namespace
{
	class ZhiZuoYinPin	// [制作饮品] 抽象基类 (可以将抽象基类理解为架构/函数声明, 实现是在派生类里面的)
	{
	public:
		// 这个是纯虚函数, 只是提供一个模版, 需要在派生类中实现
		virtual void yeiTi(void) = 0;	// 液体
		virtual void ZiZuo(void) = 0;	// 制作
		virtual void ZhuanYi(void) = 0;	// 转移
		virtual void ZhuoLiao(void) = 0;// 佐料

		void MakeDrink(void)	// 规定制作过程 取液体-->制作-->装好-->放药
		{
			yeiTi();
			ZiZuo();
			ZhuanYi();
			ZhuoLiao();
		}
	};

	class Coffee : public ZhiZuoYinPin
	{
	public:
		virtual void yeiTi(void)
		{
			cout << "从猫猫河里面取水, 并且进行二次蒸馏" << endl;
		}

		virtual void ZiZuo(void)
		{
			cout << "2Fe + Co ==加热== Java" << endl;
		}

		virtual void ZhuanYi(void)
		{
			cout << "抽咖啡机装入粉色麻袋" << endl;
		}

		virtual void ZhuoLiao(void)
		{
			cout << "放入老八餐厅顺手拿的佐料" << endl;
		}
	};

	class Juice : public ZhiZuoYinPin
	{
	public:
		virtual void yeiTi(void)
		{
			cout << "将苹果手机放入榨汁机" << endl;
		}

		virtual void ZiZuo(void)
		{
			cout << "Apple ==榨汁机== App + LE" << endl;
		}

		virtual void ZhuanYi(void)
		{
			cout << "放进杯子" << endl;
		}

		virtual void ZhuoLiao(void)
		{
			cout << "放入老六餐厅顺手拿的佐料" << endl;
		}
	};
}

static void _text_040_eat(ZhiZuoYinPin *Z)
{
	Z->MakeDrink();
	delete Z;
}

void text_040(void)
{	
	// 注意虚函数名不能写错哦!
	_text_040_eat(new Coffee());
	cout << endl;
	_text_040_eat(new Juice());
}