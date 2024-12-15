/*
给定 n 个 0 和 n 个 1，它们将按照某种顺序排成长度为 2n 的序列，求它们能排列成的所有序列中，能够满足任意前缀序列中 0 的个数都不少于 1 的个数的序列有多少个。

输出的答案对 109+7 取模。

输入格式
共一行，包含整数 n。

输出格式
共一行，包含一个整数，表示答案。

数据范围
1≤n≤105
*/
/*
1、卡特兰数
 C 2a b / a+1
先求分子C a b mod，再求分母逆元
2、类小费马，直接公式算C a b mod
*/




#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;

//快速幂求逆元模板（p是质数）
//a * b % m = 1,则我们称b为a关于模为m的乘法逆元，当m为质数的时候，a关于m的乘法逆元 为 b = a^(m-2)
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int main()
{
    int n;
    cin >> n;

	//1、类小费马，直接公式算C ab
	//分子分母约掉了（a-b）！，然后计算a-b+1到a的mod p，再计算 1 到 b 的逆元
    int a = n * 2, b = n;
    int res = 1;
    for (int i = a; i > a - b; i -- ) res = (LL)res * i % mod;                   //范围是a 到  a-b+1 
    for (int i = 1; i <= b; i ++ )    res = (LL)res * qmi(i, mod - 2, mod) % mod;//范围是1 到  b     的逆元

    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;                               //卡特兰数的分母 a+1，也就是逆元

    cout << res << endl;

    return 0;
}