#include <iostream>

using namespace std;

template <typename T>
void PrintValue(T value)
{
	if constexpr (std::is_integral_v<T>)
	{
		std::cout << "整数类型：" << value << std::endl;
	}
	else if constexpr (std::is_floating_point_v<T>)
	{
		std::cout << "浮点类型：" << value << std::endl;
	}
	else
	{
		std::cout << "其他类型" << std::endl;
	}
}

template<typename T, typename... Ts>
void syszuxPrint(T arg1, Ts... arg_left) {
	std::cout << arg1 << ", ";
	if constexpr (sizeof...(arg_left) > 0) {
		syszuxPrint(arg_left...);
	}
}

void new_cpp17_002(void)
{
	PrintValue(10); // 输出：整数类型：10
	PrintValue(3.14); // 输出：浮点类型：3.14
	PrintValue("Hello"); // 输出：其他类型

	cout << endl;

	syszuxPrint("0721", 114514, 0.721);
}