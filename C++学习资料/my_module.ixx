export module my_module;

// ֻ��ʹ�� import ����ͷ�ļ��� ���� #include
import <iostream>;

// ��Ҫд export �ؼ��� �ſ��Ա����ʹ��, ��Ȼֻ���ڲ�����
export void my_function() {
	std::cout << "����ģ��� my_function() ����!" << std::endl;
}

// ����ʹ�� �����ڲ��������ԵĶ���
// export static int c = 1;

// �������������ļ��ڲ��ǿ����õģ�ֻ�ǲ��ܵ���
static int c = 1;
// ��Ϊģ��Ҳ�ǿ��Է��ļ���!, ���Կ��������������� ������ʵ��


// ��粻�ɼ�
int b = 2;

export class MyHXClass {
public:
	MyHXClass(void) {};
	void putText(void);

	// ��̬�������Ե���
	static void out(void);

	// �ܱ���
protected:
	void fun_pro(void) {

	};

	// ˽��
private:
	void fun_pri(void) {

	}
};

void MyHXClass::out(void) {
	std::cout << "static" << std::endl;
}

void MyHXClass::putText(void) {
	std::cout << "The MyClass" << std::endl;
}

export int my_variable;