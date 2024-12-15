/*
给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共两行，第一行输出所求的商，第二行输出所求余数。

数据范围
1≤A的长度≤100000
1≤B≤10000
BB 一定不为 0
*/

/*
大整数相除
加减乘除的统一写法 就是将所有的ABC数组都是低位在前、高位在后
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//高精度（大整数）相除模板
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;//定义一个商
    r = 0;        //余数先初始化为0
    for (int i = A.size() - 1; i >= 0; i -- )//只有除法是从最高位开始的，但是模板依旧按照前面的模板，反序输入
    {
        r = r * 10 + A[i]; //每一次都有的被除数 = 上一位的余数乘以10加上A[i]
        C.push_back(r / b);//每一次都有的被除数 除以b，不过第一位可能是0
        r %= b;            //当前位的余数更新为 = 每一次都有的被除数 除以  b 的余数，然后下一位计算的时候补上去继续用
    }
    reverse(C.begin(), C.end());//需要对高位在前的C反序，符合加减乘除的统一写法 就是将所有的ABC数组都是低位在前、高位在后
    while (C.size() > 1 && C.back() == 0) C.pop_back();//去前导零
    return C;
}

int main()
{
    string a;
    vector<int> A;//被除数、大整数
    int b;//除数
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');//反序，从个位（低位）开始输入

    int r;
    auto C = div(A, b, r);
    //同步计算后结果也是低位在前，高位在后，需要输出的时候就需要还原成高位在前、低位在后，就倒着输出
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];//再反序，从高位开始输出

    cout << endl << r << endl;//这是第二行输出的余数，上一行代码就是上一行输出的商

    return 0;
}