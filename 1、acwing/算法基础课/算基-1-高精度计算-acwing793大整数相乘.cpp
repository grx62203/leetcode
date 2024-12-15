/*
给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

输入格式
共两行，第一行包含整数 A，第二行包含整数 BB。

输出格式
共一行，包含 A×B的值。

数据范围
1≤A的长度≤100000
0≤B≤10000
*/

/*
大整数相乘
加减乘除的统一写法 就是将所有的ABC数组都是低位在前、高位在后
*/

#include <iostream>
#include <vector>

using namespace std;

//高精度（大整数）相乘模板
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )//包括判断一次有没有进位，有进位再处理最高的进位
    {
        if (i < A.size()) t += A[i] * b;//相乘得一个结果
        C.push_back(t % 10);            //结果除以10的余数是当前位
        t /= 10;                        //结果除以10的商是进位
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();//如果 b = 0，结果都是0需要弹出前导0，保留一个0

    return C;
}

int main()
{
    string a;
    vector<int> A;//大整数
    int b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');//反序，从个位（低位）开始输入

    auto C = mul(A, b);
    //同步计算后结果也是低位在前，高位在后，需要输出的时候就需要还原成高位在前、低位在后，就倒着输出
    for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);

    return 0;
}