#include <iostream>

using namespace std;

static class ClassName
{
public:		// �������η� (���е�)
	void printput(string str)
	{
		cout << str << endl;
	}
protected:	// �ܱ�����
private:	// ˽�е�

};

void text_020(void)
{
	// ��Ķ���������
	ClassName cn;			// �������˶��� cn
	cn.printput("14333");	// ʹ���෽��
}