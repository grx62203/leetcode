/*
给定 n 组询问，每组询问给定三个整数 a,b,p，其中 p 是质数，请你输出 Cba mod p 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a,b,p。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤20,
1≤b≤a≤1018, //a、b范围更更大
1≤p≤105
*/
//1、a、b很大的时候用这个公式，卢卡斯 C ab = lucas(LL a, LL b, int p) = (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p
//2、类小费马，直接公式算C ab
//3、快速幂求逆元模板（p是质数）


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


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

//类小费马，直接公式算C ab
//分子分母约掉了（a-b）！，然后计算a-b+1到a的mod p，再计算 1 到 b 的逆元
int C(int a, int b, int p)
{
    if (b > a) return 0;

    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )//循环b次
    {
        res = (LL)res * j % p;                //范围是a 到  a-b+1
        res = (LL)res * qmi(i, p - 2, p) % p; //范围是1 到  b
    }
    return res;
}

//卢卡斯
int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;//防止溢出可以mod
}


int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }

    return 0;
}