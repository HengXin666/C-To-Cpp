#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void stl_016(void)
{
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    vector<int> v2(v1.size());          // 注意需要预先分配空间

    // ---copy---
    // 将v1中的元素复制到v2中
    copy(v1.begin(), v1.end(), v2.begin());

    cout << "v2 after copy: ";
    for (auto num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---replace---
    // 将v2中的元素中的2替换为9
    replace(v2.begin(), v2.end(), 2, 9);

    cout << "v2 after replace: ";
    for (auto num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---replace_if---
    // 将v2中大于等于4的元素替换为0
    replace_if(v2.begin(), v2.end(), [](int num) { return num >= 4; }, 0);
        // 对于 [](int num) { return num >= 4; } 实际上是一个 Lambda表达式

    cout << "v2 after replace_if: ";
    for (auto num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---swap---
    vector<int> v3 = { 6, 7, 8, 9, 10 };

    cout << "Before swap:" << endl;
    cout << "v1: ";
    for (auto num : v1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "v3: ";
    for (auto num : v3)
    {
        cout << num << " ";
    }
    cout << endl;

    // 交换v1和v3的内容
    swap(v1, v3);

    cout << "After swap:" << endl;
    cout << "v1: ";
    for (auto num : v1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "v3: ";
    for (auto num : v3)
    {
        cout << num << " ";
    }
    cout << endl;
}