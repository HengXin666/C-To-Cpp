// C++ѧϰ����.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
// ͨ����, ����Ĵ���ע��Ӧ��ռԴ����� 1/3 ����
#include <iostream>

/* ѧϰ��: �����C����һ���� <<���ظ�>> ��! */
    /* --- ����ƪ --- */
void text_000(void);    // ��һ��C++����    cout
void text_001(void);    // �����ռ�         using
void text_002(void);    // ����             cin
void text_003(void);    // �������� || ������������
void text_004(void);    // ǿ������ת��
void text_005(void);    // �����
void text_006(void);    // ������forѭ��
void text_007(void);    // ����, ��������Ϊ�ո���ض� gtes() std::getline()Ҳ������'\0'�Ż�ֹͣ
void text_008(void);    // string �Ĳ���

    /* --- ����ƪ --- */
void text_009(void);    // ����
void text_010(void);    // ���õ�ʹ�ó���
void text_011(void);    // �������ε�Ĭ�ϲ���
void text_012(void);    // �����βοɱ����
void text_013(void);    // ��������
void text_014(void);    // ��������

    /* --- ָ��ƪ --- */
void text_015(void);    // �ַ���Ҫ�ó���ָ��
                        // ����ָ����� void *
void text_016(void);    // C++11���� NULL ---> nullptr �����⺯�����صȳ����Ĵ���
                        // ע��: ָ�������õ����� (���ʼ�)

    /* --- �ṹ�� --- */
void text_017(void);    // C++11����ṹ�嶨��ʱ, ��Ĭ��ֵ
                        // C++ �Ľṹ����Բ�д struct
void text_018(void);    // �ṹ���Ա�����Ǻ���!!! + �ṹ��ָ��

    /* --- ������ || ö������ --- */
                        // ��
    
    /* --- typedef --- */
                        // ��

    /* --- Ԥ���� || �������� --- */
                        // �� (���ʼ�)

    /* --- λ���� --- */
void text_019(void);    // &(��λ��) ��Ӧ��, �ж���ż��
                        // |(��λ��) ~(��λȡ��) ^(��λ��� (��ͬΪ0, ��ͬΪ1))

    /* --- �� Class --- */
void text_020(void);    // ��Ķ��� �� ʹ��
void text_021(void);    // ��Ĺ��캯��
void text_022(void);    // ��ĸ�ֵ���캯�� / ��Ŀ������캯��
void text_023(void);    // �����������
void text_024(void);    // ��̬�ڴ���� new �� delete ������ <-- �ɶ�ʹ��!!! (��ֻ�������ʹ��, ��ͨ��ָ�붼����ʹ��)
void text_025(void);    // ��Ա�������Ա����
void text_026(void);    // ��̬��Ա�����뷽��
void text_027(void);    // ����Ա����
void text_028(void);    // this ָ��
void text_029(void);    // ��Ԫ����
void text_030(void);    // ��Ԫ��
void text_031(void);    // ���������
void text_032(void);    // �̳������� �Լ����ּ̳еķ�ʽ
void text_033(void);    // �̳еĹ��������� �Լ�using��ʹ��
void text_034(void);    // ������������Ĺ����������ĵ���˳��
void text_035(void);    // ��̳� ��̳й��캯�� ��̳����ֳ�ͻ
void text_036(void);    // ���μ̳��Լ���� �� ��̳�
void text_037(void);    // ��̬���� ��̬�������� ָ��, ����ʵ�ֶ�̬
void text_038(void);    // �麯�� ������
void text_039(void);    // �麯���� ��ζ�̬�� �����ǲ����Ա�
void text_040(void);    // �������ʹ��麯��
void text_043(void);    // Ƕ����(�ڲ���) �� �ֲ���

// [����]: �쳣������ģ�濴�ƱȽϼ��, ������ʵ�ʹ�����ʵ�������õıȽ϶��!
    /* --- �쳣���� --- */
void text_041(void);    // �쳣����ؼ��� try catch throw
void text_042(void);    // �Զ����쳣 + ö�����͵�Ӧ��(��߿ɶ���)

    /* --- ģ�� --- */ 
void text_044(void);    // ����ģ��
void text_045(void);    // ��ģ�� + ģ�����(typedef �� using) 

    /* --- STL �� --- */
                        // string���� ��������ת�� void text_008(void) �鿴
void stl_001(void);     // string���� ����(����) / �������� substr insert
void stl_002(void);     // vector(����/��̬����, ����������Ҫһ��)���� �������ʼ�� ���Ӻ���
void stl_003(void);     // vector���� ɾ�� �ж� ��С �Ⱥ���
void stl_004(void);     // stack(ջ)���� ���� ��ʼ�� ���÷���
void stl_005(void);     // queue(����)���� ��ʼ�� ���÷��� ����ϰ
void stl_006(void);     // deque(˫�˶���)���� ��ʼ�� ���÷���
void stl_007(void);     // list(˫������)���� ��ʼ�� ��ɾ�Ĳ�
void stl_008(void);     // list���� ���� ����ϰ
void stl_009(void);     // set(����)���� ����ʹ��
void stl_010(void);     // multiset(���ظ���Ԫ�ص�set)���� ����ʹ��
void stl_011(void);     // pair(����)���� ����ʹ��
void stl_012(void);     // map(�ֵ�)���� ����ʹ��
void stl_013(void);     // multimap(���ظ���Ԫ�ص�map)���� ����ʹ��
void stl_0144(void);    // priority_queue(���ȶ���)

// STL�ĳ����㷨
void stl_014(void);     // for_each transform �������� �㷨
void stl_015(void);     // ���ò����㷨
void stl_016(void);     // ���ÿ������滻�㷨
void stl_017(void);     // �������������㷨
void stl_018(void);     // ���ü����㷨

    /* --- C++ �ļ����� --- */
void file_01(void);     // ��������: ���ļ� ��д�ļ� �ر��ļ�
void file_02(void);     // �����ȡ����(����)
                        // �����ƶ�ȡ / �ļ�ָ�� / ��ȡ�ļ��ֽڴ�С ���ʼ�
    
    /* --- C++ �ַ����� --- */
void stringstream_01(void); // �ַ����� ���ò���
    
    /* --- C++11 ������ --- */
void new_cpp11_001(void);   // auto �ؼ���
void new_cpp11_002(void);   // decltype ������
void new_cpp11_003(void);   // ��ֵ����
void new_cpp11_004(void);   // ��������
void new_cpp11_005(void);   // ����ָ��
void new_cpp11_006(void);   // �ɱ����ģ��
void new_cpp11_007(void);   // Ĭ�ϳ�Ա��������
void new_cpp11_008(void);   // STL array
void new_cpp11_009(void);   // STL forward_list ��������

// C++ ���߳� C++11 thread �߳̿�
void thread_001(void);      // �߳̿����ʹ��
void thread_002(void);      // ������
void thread_003(void);      // ��������
void thread_004(void);      // ԭ�ӱ���

    /* --- C++17 ������ --- */
void new_cpp17_001(void);   // �۵����ʽ
void new_cpp17_002(void);   // ������if���ʽ
void new_cpp17_003(void);   // auto ռλ�ķ�����ģ���β�
void new_cpp17_004(void);   // �����б�
void new_cpp17_005(void);   // std::variant
void new_cpp17_006(void);   // std::optional
void new_cpp17_007(void);   // std::filesystem

    /* --- C++20 ������ --- */
void new_cpp20_001(void);   // ģ��
void new_cpp20_002(void);   // ��·�Ƚ������
void new_cpp20_003(void);   // ��Χ ranges
void new_cpp20_004(void);   // ��ʽ�� (���������ַ���)
void new_cpp20_005(void);   // ����

/* ��ϰ�� */
void demo_01(void);     // ���������Ĳ�, �������Ϊ�������ȥС���� <��Ŀ�����>
void demo_02(void);     // whileѭ����ӡ 0 - 5 ������
void demo_03(void);     // Ƕ��ѭ��
void demo_04(void);     // ʹ�� do...while, ��������λ����ˮ�ɻ���
void demo_05(void);     // ��1-100֮��ȡ�����֣�Ȼ���������ֽ��в²⣬ֱ���¶���Ϊֹ��
void demo_06(void);     // ����һ��һά����, �������, �ҳ����������Ǹ�, ���Ҵ�ӡ���
void demo_07(void);     // ʵ��һ��ð������
void demo_08(void);     // �ж��ַ��������ָ���
void demo_09(void);     // ����һ���ַ���, Ѱ�ҵ�һ��������һ�ε��ַ�, û�������no
void demo_10(void);     // ��ŵ��
void demo_11(void);     // ����λ����, ���һ�������Ķ�����
void demo_12(void);     // ʵ��ϴ�Ʒ���(������) <��������>
void demo_13(void);     // ����һ�������࣬��Ա�����г��Ϳ���Ա�������ж��Ƿ��������κ�������ε����
void demo_14(void);     // ͨ����Ԫ�������������, �ж϶����������
void demo_15(void);     // ������ ��̳�
void demo_16(void);     // �������<��̬>��ϰ: ʵ��һ��������
void demo_17(void);     // ��дһ������ģ��, �ֱ����һ�������������ݵ����ֵ,��Сֵ��ƽ��ֵ
void demo_18(void);     // ����lambda��ɣ�����һ���ַ�����ͳ���ַ�����ĳ���ַ��ĸ���

void BUG_01(void);      // sizeof ������

int main()
{
                        // By Heng_Xin
    system("cls");      // ����
    system("color a");  // ����ʹ��cmd
    demo_12();

    std::cout << std::endl << "--- The World ---" << std::endl;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

