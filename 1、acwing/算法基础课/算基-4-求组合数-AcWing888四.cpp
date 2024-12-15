/*
输入 a,b，求 Cba 的值。

注意结果可能很大，需要使用高精度计算。

输入格式
共一行，包含两个整数 a 和 b。

输出格式
共一行，输出 Cba 的值。

数据范围
1≤b≤a≤5000
*/
/*
1、a！中求有质因子p的次数
a/p下取整+a/p2下取整++++++++++
2、
线性筛选质因数
获取a!中关于每个质因子p的次数
将每个质因数按次幂  一一相乘
逆向输出大数相乘结果
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


const int N = 5010;

int primes[N], cnt;//存储质数，且计数
bool st[N];        //筛掉的时候true
int sum[N];        //存储三个原始元素总的 每个质数i对应的次数



//线性筛质数模板
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

//获取a!中关于质因子p的次数
int get(int n, int p)
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

//高精度（大整数）相乘模板
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;       //if (i < A.size())
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}


int main()
{
    int a, b;
    cin >> a >> b;

    //1、线性筛选质因数
    get_primes(a);

    //2、获取a!中关于每个质因子p的次数
    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);
    }

    vector<int> res;
    res.push_back(1);
    //3、将每个质因数按次幂  一一相乘
    for (int i = 0; i < cnt; i ++ )          //i表示每个质因子p
        for (int j = 0; j < sum[i]; j ++ )   //循环j次，j没有用
            res = mul(res, primes[i]);
    //4、逆向输出大数相乘结果
    //同步计算后结果也是低位在前，高位在后，需要输出的时候就需要还原成高位在前、低位在后，就倒着输出
    for (int i = res.size() - 1; i >= 0; i -- ) printf("%d", res[i]);
    puts("");

    return 0;
}