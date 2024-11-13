#include <iostream>
#include <ctime>
#include <filesystem>
using namespace std;

void new_cpp17_007(void)
{
	namespace fs = std::filesystem;

	cout << "当前工作目录是: " << fs::current_path() << endl;

	auto x64 = fs::path("./x64");

	if (!fs::exists(x64))
	{
		cout << "该路径不存在!" << endl;
	}
	else
	{
		cout << "正在对 [" << x64 << "] 路径 进行操作..." << endl;
	}

	// 创建一个 fs::directory_options 对象 opt，使用默认选项 none，表示跳过符号链接，权限拒绝将被视为错误
	fs::directory_options opt(fs::directory_options::none);

	// 创建一个 fs::directory_entry 对象 dir，表示指定的目录 x64
	fs::directory_entry dir(x64);

	/************************************************************************/
	/* 遍历一级(一层)目录示例                                                 */
	/************************************************************************/

	// 输出当前目录的名称
	std::cout << "单层遍历 [x64]:\t-->" << dir.path().filename() << endl;

	// 使用 fs::directory_iterator 迭代器遍历指定目录 x64 下的所有文件和子目录。opt 是可选的，用于指定遍历选项
	for (fs::directory_entry const& entry : fs::directory_iterator(x64, opt))
	{
		// 检查当前迭代到的路径 entry 是否为常规文件
		if (entry.is_regular_file())
		{
			// 输出文件的名称和大小。
			cout << entry.path().filename() << "\t size: " << entry.file_size() << endl;
		}
		// 如果当前迭代到的路径 entry 是一个目录，则执行该分支
		else if (entry.is_directory())
		{
			// 输出目录的名称。
			cout << entry.path().filename() << "\t dir" << endl;
		}
	}

	cout << endl;

	/************************************************************************/
	/* 递归遍历示例                                                          */
	/************************************************************************/
	// 输出当前目录的名称
	cout << "x64 all:\t-->" << dir.path().filename() << endl;

	// 使用 fs::recursive_directory_iterator 迭代器递归遍历指定目录 x64 下的所有文件和子目录。opt 是可选的，用于指定遍历选项
	for (fs::directory_entry const& entry : fs::recursive_directory_iterator(x64, opt))
	{
		// 检查当前迭代到的路径 entry 是否为常规文件
		if (entry.is_regular_file())
		{
			// 输出文件的名称、大小和父目录路径
			cout << entry.path().filename() << "\t size: " << entry.file_size() << "\t parent: " << entry.path().parent_path() << endl;
		}
		// 如果当前迭代到的路径 entry 是一个目录，则执行该分支
		else if (entry.is_directory())
		{
			// 输出目录的名称
			cout << entry.path().filename() << "\t dir" << endl;
		}
	}
}