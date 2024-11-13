export module my_module;

// 只能使用 import 导入头文件， 不能 #include
import <iostream>;

// 需要写 export 关键字 才可以被外界使用, 不然只能内部调用
export void my_function() {
	std::cout << "这是模块的 my_function() 函数!" << std::endl;
}

// 不能使用 导出内部链接属性的东西
// export static int c = 1;

// 但链接属性在文件内部是可以用的，只是不能导出
static int c = 1;
// 因为模块也是可以分文件的!, 所以可以在这里声明， 在那里实现


// 外界不可见
int b = 2;

export class MyHXClass {
public:
	MyHXClass(void) {};
	void putText(void);

	// 静态函数可以导出
	static void out(void);

	// 受保护
protected:
	void fun_pro(void) {

	};

	// 私有
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