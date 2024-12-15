/*
输入一个整数 n ，求斐波那契数列的第 n 项。

假定从 0 开始，第 0 项为 0。

数据范围
0≤n≤39
*/
//动态规划=递推
class Solution {
public:
    int Fibonacci(int n) {
        int a[110];
        a[0] = 0;
        a[1] = 1;
        for (int i = 2; i <= n; i ++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};
//递推+滚动变量
class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1;
        while (n -- ) {
            int c = a + b;
            a = b, b = c;
        }
        return a;
    }
};



//x和y分别表示第0项和第1项，这里统一定义为1。
/*1、DFS
递归。
递归计算的节点个数是 O(2^n) 的级别的，存在大量重复计算。
时间复杂度是 O(2^n)，一秒内大约能算到第三四十项。
*/
const int MOD = 1000000007;
int f(int n)
{
    if (n <= 1) return 1;
    return (f(n - 1) + f(n - 2)) % MOD;
}
/*2、记忆化搜索
开一个大数组记录中间结果，如果一个状态被计算过，则直接查表，否则再递归计算。
总共有 n 个状态，计算每个状态的复杂度是 O(1)所以时间复杂度是 O(n)
一秒内算 n=107 毫无压力，但由于是递归计算，递归层数太多会爆栈，大约只能算到 n=105 级别。
*/
const int N = 100000, MOD = 1000000007;
int a[N];
int f2(int n)
{
    if (a[n]) return a[n];
    if (n <= 1) return 1;
    a[n] = f2(n - 1) + f2(n - 2);
    a[n] %= MOD;
    return a[n];
}
/*3、递推=动态规划
开一个大数组，记录每个数的值。用循环递推计算。
总共计算 n 个状态，所以时间复杂度是 O(n)
但需要开一个长度是 n 的数组，内存将成为瓶颈，当 n=108 时，需要的内存是 4∗108/1024×1024≈381MB
分子中乘4是因为C++中 int 类型占4字节。
*/
const int N = 100000000, MOD = 1000000007;
int f3(int n)
{
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= MOD;
    }
    return a[n];
}
/*4、递推+滚动变量。
仔细观察我们会发现，递推时我们只需要记录前两项的值即可，没有必要记录所有值，所以我们可以用滚动变量递推。
时间复杂度还是 O(n)，但空间复杂度变成了 O(1)
*/
const int MOD = 1000000007;
int f4(int n)
{
    int x, y, z;
    x = y = 1;
    for (int i = 2; i <= n; i ++ )
    {
        z = (x + y) % MOD;
        x = y;
        y = z;
    }
    return z;
}
/*5、矩阵运算 + 快速幂。
https://www.acwing.com/blog/content/25/
时间复杂度分析：快速幂的时间复杂度是 O(logn)，所以算法5的时间复杂度也是 O(logn)
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const int MOD = 1000000007;

void mul(int a[][2], int b[][2], int c[][2])
{
    int temp[][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
            for (int k = 0; k < 2; k ++ )
            {
                long long x = temp[i][j] + (long long)a[i][k] * b[k][j];
                temp[i][j] = x % MOD;
            }
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
            c[i][j] = temp[i][j];
}


int f_final(long long n)
{
    int x[2] = {1, 1};

    int res[][2] = {{1, 0}, {0, 1}};
    int t[][2] = {{1, 1}, {1, 0}};
    long long k = n - 1;
    while (k)
    {
        if (k&1) mul(res, t, res);
        mul(t, t, t);
        k >>= 1;
    }

    int c[2] = {0, 0};
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
        {
            long long r = c[i] + (long long)x[j] * res[j][i];
            c[i] = r % MOD;
        }

    return c[0];
}


int main()
{
    long long n ;

    cin >> n;
    cout << f_final(n) << endl;

    return 0;
}
