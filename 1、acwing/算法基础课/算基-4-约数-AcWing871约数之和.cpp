/*
约数之和

给定 n 个正整数 ai，请你输出这些数的乘积的约数之和，答案对 109+7 取模。
输入格式
第一行包含整数 n。
接下来 n 行，每行包含一个整数 ai。
输出格式
输出一个整数，表示所给正整数的乘积的约数之和，答案需对 109+7 取模。
*/
/*
    求出质因子的底数p1、p2、p3、、、、指数a1、a2、a3、、、
    然后约数之和 = （p1^0+p1^1+、、、、)*()*()****(pk^0+pk^1+、、、、)
        求(pk^0+pk^1+、、、、)的公式如下
            1*pk+1
            (1*pk+1)*pk +1 = pk^2 + pk + 1
            (pk^2 + pk + 1)*pk + 1 = pk^3 + pk^2 +pk + 1
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;

    while (n -- )
    {
        int x;
        cin >> x;

        //分解质因数的模板，得到了每个质因子的底数与相应的指数
        for (int i = 2; i <= x / i; i ++ )
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }
        if (x > 1) primes[x] ++ ;

    }

    LL res = 1;
    //求约数之和
    for (auto p : primes)
    {
        LL a = p.first, b = p.second;
        LL t = 1;
        while (b -- ) t = (t * a + 1) % mod;//求(pk^0+pk^1+、、、、)
        res = res * t % mod;                //求各项之乘积
    }

    cout << res << endl;

    return 0;
}