#include <iostream>

using namespace std;

template <typename T>
void PrintValue(T value)
{
	if constexpr (std::is_integral_v<T>)
	{
		std::cout << "�������ͣ�" << value << std::endl;
	}
	else if constexpr (std::is_floating_point_v<T>)
	{
		std::cout << "�������ͣ�" << value << std::endl;
	}
	else
	{
		std::cout << "��������" << std::endl;
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
	PrintValue(10); // ������������ͣ�10
	PrintValue(3.14); // ������������ͣ�3.14
	PrintValue("Hello"); // �������������

	cout << endl;

	syszuxPrint("0721", 114514, 0.721);
}