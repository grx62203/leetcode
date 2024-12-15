/*
筛质数   10e7下快一倍
给定一个正整数 n，请你求出 1∼n 中质数的个数。
输入格式
共一行，包含整数 n。
输出格式
共一行，包含一个整数，表示 1∼n 中质数的个数。
*/
/*
1、n只会被 n的最小质因子 筛选掉
    对于一个合数 x， 假设pj是x的最小质因子，当i枚举到x/pj的时候，就会筛掉pj
2、pj*i第一次出现的时候，pj是pj*i的最小质因子，然后就break，不浪费时间
    i第一次可以整除某个质数的时候，break，此时找到了当前i的最小质因子，防止pj将 pj*i之后的数筛掉浪费时间，避免多筛
        如果满足条件， pj一定是i的最小质因子，pj也一定是pj*i的最小质因子
        如果不满足条件，pj一定小于i的所有质因子，pj也一定是pj*i的最小质因子   
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;//存储质数，且计数
bool st[N];        //筛掉的时候true


//线性筛质数模板
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;          //如果没有被筛掉，存储，累加计数
        for (int j = 0; primes[j] <= n / i; j ++ )//从小到大遍历每个质数
        {
            st[primes[j] * i] = true;
            //删掉质数与当前数的乘积，恰好是可以对每个合数都只删一次，也就是pj*i第一次出现的时候，pj是pj*i的最小质因子
            //对于一个合数 x， 假设pj是x的最小质因子，当i枚举到x/pj的时候，就会筛掉pj
            if (i % primes[j] == 0)  break;//遍历到了pj 第一次成为i的最小质因子 
                //i第一次可以整除某个质数的时候，break，此时找到了当前i的最小质因子，防止pj将 pj*i之后的数筛掉浪费时间，避免多筛
            	//如果满足条件， pj一定是i的最小质因子，pj也一定是pj*i的最小质因子
            	//如果不满足条件，pj一定小于i的所有质因子，pj也一定是pj*i的最小质因子
        }
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
