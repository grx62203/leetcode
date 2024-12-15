/*
给定两个正整数（不含前导 0），计算它们的和。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的和。

数据范围
1≤整数长度≤100000
*/

/*
大整数相加不压位
加减乘除的统一写法 就是将所有的ABC数组都是低位在前、高位在后
*/
#include <iostream>
#include <vector>
using namespace std;
//高精度（大整数）相加模板
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size()) return add(B, A);//为了使长的在前，这样子方便加多出来的一部分

    vector<int> C;// C = A + B;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ )//此时数组存放的大整数 地位在前、高位在后，从前往后算，传递进位
    {
        t += A[i];
        if (i < B.size()) t += B[i];//已经保证A更长，所以加B的时候需要判断
        C.push_back(t % 10);        //三个数相加除以10的商是结果
        t /= 10;                    //三个数相加除以10的余数是进位
    }

    if (t) C.push_back(t);//AB相加结束后，有超出的进位，要加到最前面，此时高位在前、地位在后
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b; // a = "123456"
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');//反序，从个位（低位）开始输入
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');//字符串字符变成数字减去 ‘0’

    auto C = add(A, B);
	//同步计算后结果也是低位在前，高位在后，需要输出的时候就需要还原成高位在前、低位在后，就倒着输出
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}