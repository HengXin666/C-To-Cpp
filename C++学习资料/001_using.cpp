#include <iostream>

void text_001(void)
{
	int xz;
	std::cin >> xz;
	switch (xz)
	{
		// 语法(关键字) using
		case 1:
		{
			// namespace <...> 完全导入 命名空间<...> 的全部内容
			using namespace std;
			cout << "可以直接使用cout 和 endl" << endl;
			break;
		}
		case 2:
		{
			// 仅仅导入了 命名空间std 的 cout
			using std::cout;
			cout << "可以直接使用cout 但不能使用 endl" << std::endl;
			break;
		}
		case 3:
		{
			// 显式引用
			std::cout << "不使用using导入命名空间, 那么就不能使用它们!" << std::endl;
			break;
		}
	default:
		std::cout << "不好意思, 这个是测试代码! 您需要查看源码来运行!\n";
		break;
	}
}