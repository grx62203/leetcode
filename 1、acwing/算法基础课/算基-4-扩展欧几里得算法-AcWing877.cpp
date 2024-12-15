/*
给定 n 对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai*xi+bi*yi=gcd(ai,bi)。
*/
/*
a和b组合的结果都是最大公约数的倍数
理解gcd之后系数y会发生改变，但需要’y -= a / b * x;’来更新吗？递归到最后一层然后往回走？
*/
#include <iostream>
#include <algorithm>

using namespace std;

//拓展欧几里得算法模板
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)//如果b = 0 ，一个方案
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);//也得翻转一下x、y
    y -= a / b * x;               //推理见md笔记，b的系数会变
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int x, y;
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    return 0;
}