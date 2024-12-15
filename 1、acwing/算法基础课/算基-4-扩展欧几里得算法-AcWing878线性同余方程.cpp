/*
给定 n 组数据 ai,bi,mi，对于每组数求出一个 xi，使其满足 ai*xi≡bi(mod mi)，如果无解则输出 impossible。
*/
/*
等价于
存在y属于整数   a*x  - m*y = b
	也就是      a*x  + m*y = b
只要找到扩展欧几里得公式右边是最小公约数倍数的情况，所以如果b 是a与m的最小公约数的倍数的话，就有解答
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

//拓展欧几里得算法模板
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);

        int x, y;
        int d = exgcd(a, m, x, y);              //求得a、m的最小公约数d
        if (b % d) puts("impossible");          //如果b不是a、m最小公约数的倍数，无解
        else printf("%d\n", (LL)b / d * x % m); //这里的b是a、m的最小公约数，x扩大相应倍数，再mod m
    }

    return 0;
}