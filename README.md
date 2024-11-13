# C To C++
> [!TIP]
> 这个是一个个人向的学习笔记, 主要记录了我在有C语言的基础上, 转入C++的时候记录的学习笔记.

## 食用方法

1. 克隆仓库或者下载仓库压缩包, 解压

2. 双击`C++学习资料.sln`文件, 理论上系统会使用VS2022打开

3. 找到`C++学习资料.cpp`文件, (即`main`函数所在文件), 其中包含了文件函数的声明与注释, 内容如下:

4. 需要学习什么可以点击跳转到对应的文件, (本项目不全面, 因为有一些内容在我的笔记上面, 由于格式的原因, 此处无法分享, 只提供了代码; 作为了解, 理论上够用了)

5. 特别的, 本项目的命名可能很抽象和随意, 因为它本身只是我的个人笔记, 我的错qwq... (但是我不改了..., 因为实际上它并不是非常现代的C++!!!, ~~当时的我可不懂, 纯萌新~~)

6. 不足之处, 请见谅, 可能会有错误, 请自行甄别! 我只能保证大部分是正确的...

```C++
// C++学习资料.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 通常的, 合理的代码注释应该占源代码的 1/3 左右
#include <iostream>

/* 学习区: 如果和C语言一样就 <<不重复>> 了! */
    /* --- 基础篇 --- */
void text_000(void);    // 第一个C++程序    cout
void text_001(void);    // 命名空间         using
void text_002(void);    // 输入             cin
void text_003(void);    // 数据类型 || 其他数据类型
void text_004(void);    // 强制类型转换
void text_005(void);    // 随机数
void text_006(void);    // 数组简洁for循环
void text_007(void);    // 输入, 但不会因为空格而截断 gtes() std::getline()也是遇到'\0'才会停止
void text_008(void);    // string 的操作

    /* --- 函数篇 --- */
void text_009(void);    // 引用
void text_010(void);    // 引用的使用场景
void text_011(void);    // 函数传参的默认参数
void text_012(void);    // 函数形参可变参数
void text_013(void);    // 内联函数
void text_014(void);    // 函数重载

    /* --- 指针篇 --- */
void text_015(void);    // 字符串要用常量指针
                        // 万用指针就是 void *
void text_016(void);    // C++11引入 NULL ---> nullptr 来避免函数重载等场景的错误
                        // 注意: 指针与引用的区别 (见笔记)

    /* --- 结构体 --- */
void text_017(void);    // C++11允许结构体定义时, 有默认值
                        // C++ 的结构体可以不写 struct
void text_018(void);    // 结构体成员可以是函数!!! + 结构体指针

    /* --- 共用体 || 枚举类型 --- */
                        // 爬
    
    /* --- typedef --- */
                        // 爬

    /* --- 预处理 || 条件编译 --- */
                        // 爬 (见笔记)

    /* --- 位运算 --- */
void text_019(void);    // &(按位与) 的应用, 判断奇偶数
                        // |(按位或) ~(按位取反) ^(按位异或 (相同为0, 不同为1))

    /* --- 类 Class --- */
void text_020(void);    // 类的定义 和 使用
void text_021(void);    // 类的构造函数
void text_022(void);    // 类的赋值构造函数 / 类的拷贝构造函数
void text_023(void);    // 类的析构函数
void text_024(void);    // 动态内存管理 new 与 delete 操作符 <-- 成对使用!!! (不只是类可以使用, 普通的指针都可以使用)
void text_025(void);    // 成员变量与成员函数
void text_026(void);    // 静态成员变量与方法
void text_027(void);    // 常成员函数
void text_028(void);    // this 指针
void text_029(void);    // 友元函数
void text_030(void);    // 友元类
void text_031(void);    // 运算符重载
void text_032(void);    // 继承与派生 以及三种继承的方式
void text_033(void);    // 继承的构造与析构 以及using的使用
void text_034(void);    // 基类与派生类的构造与析构的调用顺序
void text_035(void);    // 多继承 多继承构造函数 多继承名字冲突
void text_036(void);    // 菱形继承以及解决 与 虚继承
void text_037(void);    // 多态概念 多态构成条件 指针, 引用实现多态
void text_038(void);    // 虚函数 虚析构
void text_039(void);    // 虚函数表 如何动态绑定 即覆盖操作对比
void text_040(void);    // 抽象基类和纯虚函数
void text_043(void);    // 嵌套类(内部类) 与 局部类

// [警告]: 异常处理与模版看似比较简短, 但是在实际工作中实际上是用的比较多的!
    /* --- 异常处理 --- */
void text_041(void);    // 异常处理关键字 try catch throw
void text_042(void);    // 自定义异常 + 枚举类型的应用(提高可读性)

    /* --- 模版 --- */ 
void text_044(void);    // 函数模版
void text_045(void);    // 类模版 + 模版别名(typedef 与 using) 

    /* --- STL 库 --- */
                        // string容器 内容请跳转到 void text_008(void) 查看
void stl_001(void);     // string容器 迭代(遍历) / 拷贝函数 substr insert
void stl_002(void);     // vector(向量/动态数组, 内容类型需要一样)容器 定义与初始化 增加函数
void stl_003(void);     // vector容器 删除 判断 大小 等函数
void stl_004(void);     // stack(栈)容器 概念 初始化 常用方法
void stl_005(void);     // queue(队列)容器 初始化 常用方法 と练习
void stl_006(void);     // deque(双端队列)容器 初始化 常用方法
void stl_007(void);     // list(双向链表)容器 初始化 增删改查
void stl_008(void);     // list容器 排序 と练习
void stl_009(void);     // set(集合)容器 基本使用
void stl_010(void);     // multiset(可重复的元素的set)容器 基本使用
void stl_011(void);     // pair(对组)容器 基本使用
void stl_012(void);     // map(字典)容器 基本使用
void stl_013(void);     // multimap(可重复的元素的map)容器 基本使用
void stl_0144(void);    // priority_queue(优先队列)

// STL的常用算法
void stl_014(void);     // for_each transform 遍历容器 算法
void stl_015(void);     // 常用查找算法
void stl_016(void);     // 常用拷贝与替换算法
void stl_017(void);     // 常用算数生成算法
void stl_018(void);     // 常用集合算法

    /* --- C++ 文件操作 --- */
void file_01(void);     // 基本操作: 打开文件 读写文件 关闭文件
void file_02(void);     // 更多读取函数(方法)
                        // 二进制读取 / 文件指针 / 获取文件字节大小 见笔记
    
    /* --- C++ 字符串流 --- */
void stringstream_01(void); // 字符串流 常用操作
    
    /* --- C++11 新特性 --- */
void new_cpp11_001(void);   // auto 关键字
void new_cpp11_002(void);   // decltype 操作符
void new_cpp11_003(void);   // 右值引用
void new_cpp11_004(void);   // 匿名函数
void new_cpp11_005(void);   // 智能指针
void new_cpp11_006(void);   // 可变参数模版
void new_cpp11_007(void);   // 默认成员函数控制
void new_cpp11_008(void);   // STL array
void new_cpp11_009(void);   // STL forward_list 单向链表

// C++ 多线程 C++11 thread 线程库
void thread_001(void);      // 线程库类的使用
void thread_002(void);      // 互斥锁
void thread_003(void);      // 条件变量
void thread_004(void);      // 原子变量

    /* --- C++17 新特性 --- */
void new_cpp17_001(void);   // 折叠表达式
void new_cpp17_002(void);   // 编译期if表达式
void new_cpp17_003(void);   // auto 占位的非类型模板形参
void new_cpp17_004(void);   // 属性列表
void new_cpp17_005(void);   // std::variant
void new_cpp17_006(void);   // std::optional
void new_cpp17_007(void);   // std::filesystem

    /* --- C++20 新特性 --- */
void new_cpp20_001(void);   // 模块
void new_cpp20_002(void);   // 三路比较运算符
void new_cpp20_003(void);   // 范围 ranges
void new_cpp20_004(void);   // 格式化 (变量放入字符串)
void new_cpp20_005(void);   // 并发

/* 练习区 */
void demo_01(void);     // 求两个数的差, 结果总是为大的数减去小的数 <三目运算符>
void demo_02(void);     // while循环打印 0 - 5 的数字
void demo_03(void);     // 嵌套循环
void demo_04(void);     // 使用 do...while, 求所有三位数的水仙花数
void demo_05(void);     // 在1-100之间取个数字，然后输入数字进行猜测，直到猜对了为止。
void demo_06(void);     // 定义一个一维数组, 存放体重, 找出体重最大的那个, 并且打印输出
void demo_07(void);     // 实现一个冒泡排序
void demo_08(void);     // 判断字符串的数字个数
void demo_09(void);     // 给定一个字符串, 寻找第一个仅出现一次的字符, 没有则输出no
void demo_10(void);     // 汉诺塔
void demo_11(void);     // 利用位运算, 输出一个整数的二进制
void demo_12(void);     // 实现洗牌发牌(斗地主) <带动画的>
void demo_13(void);     // 创建一个矩形类，成员变量有长和宽，成员函数有判断是否是正方形和输出矩形的面积
void demo_14(void);     // 通过友元函数重载运算符, 判断动物类的年龄
void demo_15(void);     // 动物类 多继承
void demo_16(void);     // 面向对象<多态>练习: 实现一个计算器
void demo_17(void);     // 编写一个函数模版, 分别求出一个组数里面数据的最大值,最小值和平均值
void demo_18(void);     // 利用lambda完成：输入一个字符串，统计字符串的某个字符的个数

void BUG_01(void);      // sizeof 的厉害

int main()
{
                        // By Heng_Xin
    system("cls");      // 清屏
    system("color a");  // 可以使用cmd
    demo_12();          // 此处调用代码, 以测试/查看运行结果

    std::cout << std::endl << "--- The World ---" << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
```

感谢您的观看qwq...