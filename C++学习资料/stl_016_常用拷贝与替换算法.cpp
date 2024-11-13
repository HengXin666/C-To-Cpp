#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void stl_016(void)
{
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    vector<int> v2(v1.size());          // ע����ҪԤ�ȷ���ռ�

    // ---copy---
    // ��v1�е�Ԫ�ظ��Ƶ�v2��
    copy(v1.begin(), v1.end(), v2.begin());

    cout << "v2 after copy: ";
    for (auto num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---replace---
    // ��v2�е�Ԫ���е�2�滻Ϊ9
    replace(v2.begin(), v2.end(), 2, 9);

    cout << "v2 after replace: ";
    for (auto num : v2)
    {
        cout << num << " ";
    }
    cout << endl;

    // ---replace_if---
    // ��v2�д��ڵ���4��Ԫ���滻Ϊ0
    replace_if(v2.begin(), v2.end(), [](int num) { return num >= 4; }, 0);
        // ���� [](int num) { return num >= 4; } ʵ������һ�� Lambda���ʽ

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

    // ����v1��v3������
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