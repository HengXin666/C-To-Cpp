#include <iostream>

using namespace std;

namespace
{
	class A
	{
	public:
		int m_a;
	};

	class B : public A
	{
	public:
		int m_b;
	};

	class C : public A
	{
	public:
		int m_c;
	};

	class D : public B, public C
	{
	public:
		void getA(int a)
		{
			// this->m_a = a;	// 不明确
			// this->D::m_a = a;// 不明确

			// 可行
			this->A::m_a = a;

			// 可以
			this->B::m_a = a + 1;
			this->C::m_a = a + 2;

			// 这样就产生了三分成员变量m_a, 内存不堪重负... 除非某些场景有需求吧
		}

		void putA(int xz)
		{
			switch (xz)
			{
			case 1:
				cout << A::m_a << endl;
				break;
			case 2:
				cout << B::m_a << endl;
				break;
			case 3:
				cout << C::m_a << endl;
				break;
			default:
				break;
			}
		}
	public:
		int m_d;
	};
}

static void _text_036(void);
void text_036(void)
{
	/*	菱形继承效果图:
	*			A		基类
	*		   / \
	*		  B	  C		继承基类A的派生类B, C
	*		   \ /
	*			D		继承基类B, C的派生类D
	* 
	*	危害: 如果 A中的成员变量被B, C继承并且继承到D, 那么若 调用A的变量, 就不知道是 B的基类A的 还是 C的基类A的 (变量冗余)
	* 
	*	解决方法:	1. 设计严密的继承属性 后续又有需求怎么办?我就是要用啊		[Pass]
	*				2. 如上, 显式要求使用 A::变量	, 可是还是会有一份的变量冗余	[Warning]
	*				3. 改为使用虚继承 见 _text_036();							[Info]
	*
	*	值得注意的是:
	*		"使用虚继承会增加运行时的开销，需要额外的虚指针和虚表来管理虚基类。"
	*
	* 因此，在设计类的继承结构时，只有在存在菱形继承的情况下或确实需要使用虚继承解决[二义性问题]时，才推荐使用虚继承。
	* 对于其他情况，普通的继承即可满足需求。
	*	<<值得注意>> By GPT-3.5 
	* */
	D d;
	d.getA(123);
	d.putA(1);
	d.putA(2);
	d.putA(3);
	_text_036();
}


namespace
{
	class X_A
	{
	public:
		int m_a;
	};

	class X_B : virtual public X_A
	{
	public:
		int m_b;
	};

	class X_C : virtual public X_A
	{
	public:
		int m_c;
	};

	class X_D : virtual public X_B, virtual public X_C
	{
	public:
		void getA(int a)
		{
			this->m_a = a;
		}

		void putA(void)
		{
			cout << m_a << endl;
		}

	public:
		int m_d;
	};
}

static void _text_036(void)
{
	X_D xd;
	xd.getA(114514);
	xd.putA();
}