/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cba mod (109+7) 的值。。这里mod了一个质数，所以可以用快速幂

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

1≤n≤10000,
1≤b≤a≤105    //a、b范围更大
*/
//1、a、b较大的时候用这个公式，小费马 C ab = fact(a!) * infact((a-b)!) * infact(b!)    ps：infact是逆元
//2、小费马预处理C ab 的原始三个元素分别mod的结果，-1次幂的结果就是逆元
//3、新的mod是防止溢出



#include <iostream> 
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;


int fact[N], infact[N];

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
    //小费马的预处理
    //预处理Cab 的原始三个元素分别mod的结果，-1次幂的结果就是逆元
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }


    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);//Cab % mod的公式演化，新的mod是防止溢出
    }

    return 0;
}