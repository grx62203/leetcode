/*
给定 n 个正整数 ai，请你求出每个数的欧拉函数。
*/
#include <iostream>

using namespace std;

//欧拉函数模板
int phi(int x)
{
    int res = x;

    //分解质因数模板 改造
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)               //找到质因子 i
        {
            res = res / i * (i - 1);  // 数 x * （1 - 1/i）* **** 也就是  res / i  *  (i - 1) * ****
            //容斥原理推出来的欧拉函数公式
            //因为不能有小数,对滴，避免溢出。乘积可能会超出int范围。
            //好像写成res-(res/i)也可以
            while (x % i == 0) x /= i;//将质因子 i 的 指数  消耗掉，得到剩余部分
        }
    if (x > 1) res = res / x * (x - 1);//再考虑最大因子

    return res;
}


int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }

    return 0;
}