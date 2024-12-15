/*
现在，有一个 n 级台阶的楼梯，每级台阶上都有若干个石子，其中第 i 级台阶上有 ai 个石子(i≥1)。

两位玩家轮流操作，每次操作可以从任意一级台阶上拿若干个石子放到下一级台阶中（不能不拿）。

已经拿到地面上的石子不能再拿，最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，其中第 i 个整数表示第 i 级台阶上的石子数 ai。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n≤105,
1≤ai≤109
*/
/*
1、为啥偶数台阶的不需要管呢？
因为偶数级不接地，不会产生石子出局（就是石子到达地面）的情况，我们可以通过相应的操作抵消对手的操作。
对手将奇数级石子拿到偶数级上，我们跟进对手的操作，将偶数级多出的石子放到下一级的奇数级上，偶数级的状态变化就被抵消了；
对奇数操作是可以改变状态的，当石子处于第 1 级时， 往下拿就会被放到地面上，被放在地面上的石子就出局了，台阶上石子的总量就产生了变化，总体的状态就发生了变化。
2、也就是第一层会影响状态，奇数层可以影响第一层，偶数层可以被抵消状态变更
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int main()
{
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        if (i & 1) res ^= x;//只计算石子为奇数个的 楼梯 一一异或
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}
