/*
筛质数    时间复杂度   n*lgn，优化为 大概n
给定一个正整数 n，请你求出 1∼n 中质数的个数。
输入格式
共一行，包含整数 n。
输出格式
共一行，包含一个整数，表示 1∼n 中质数的个数。
*/
/*
从前到后，删掉能找到的每一个数的倍数，剩下的就是质数
优化：只删掉质数的倍数
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;//存储质数，且计数
bool st[N];        //筛掉的时候true


//朴素筛质数模板
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;//代表当前数被删掉了，跳过
        primes[cnt ++ ] = i;//存储质数，且记录质数的个数
        for (int j = i + i; j <= n; j += i)//删掉质数的倍数就好了
            st[j] = true;
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}