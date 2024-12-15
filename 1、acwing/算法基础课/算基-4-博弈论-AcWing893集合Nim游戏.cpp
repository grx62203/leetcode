/*
给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。

现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 k，表示数字集合 S 中数字的个数。

第二行包含 k 个整数，其中第 i 个整数表示数字集合 S 中的第 i 个数 si。

第三行包含整数 n。

第四行包含 n 个整数，其中第 i 个整数表示第 i 堆石子的数量 hi。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n,k≤100,
1≤si,hi≤10000
*/
/*
0-1、sg非零状态可以说明到0，必胜
0-2、一般有很多图，玩家可以选择任何一个图进行操作，当所有的图都走不了（某刻sg=0），才必输，用异或来求所有图是否都sg为0
0-3、所有终点的sg=0，非终点的sg是通过遍历能到达状态的sg来求取的，sg 等于能到达 状态的集合对应的sg集合中的 未出现的最小非负整数
*/


#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], f[M];//可以操作的操作数集合、n堆石头的个数集合

//求有向无环图的sg值，返回初始状态的sg值
int sg(int x)
{
	//如果若干组合操作到达同一状态，省略遍历
    if (f[x] != -1) return f[x];

    //存取所有可以到达的局面
    unordered_set<int> S;
    for (int i = 0; i < m; i ++ )
    {
        int sum = s[i];
        //如果当前堆可以被选取的操作数操作，那么存入 操作后的新状态的sg值
        if (x >= sum) S.insert(sg(x - sum));
    }
    //寻找最小的非负整数
    //只有x - sum == 0 的时候，sg 才等于0
    for (int i = 0; ; i ++ )
        if (!S.count(i))
            return f[x] = i;
}


int main()
{
    cin >> m;
    for (int i = 0; i < m; i ++ ) cin >> s[i];
    cin >> n;

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}