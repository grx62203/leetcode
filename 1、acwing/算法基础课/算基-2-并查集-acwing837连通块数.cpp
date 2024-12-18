/*
给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。

现在要进行 m 个操作，操作共有三种：

C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
Q1 a b，询问点 aa 和点 bb 是否在同一个连通块中，aa 和 bb 可能相等；
Q2 a，询问点 a 所在连通块中点的数量；
输入格式
第一行输入整数 n 和 m。

接下来 m 行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。

输出格式
对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。

对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量

每个结果占一行。

数据范围
1≤n,m≤105
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];//存储着N的父节点、存储这个集合的大小（一般N都是祖宗）
//返回x的祖宗节点+压缩路径
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        cnt[i] = 1;//表示这个树根代表的集合的大小一开始是 1
    }

    while (m -- )
    {
        string op;
        int a, b;
        cin >> op;
        //1、合并两个集合，先判别是不是一个集合，再  认祖宗 + 合数量到新祖宗
        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        //2、判别是不是一个集合就是判别 是不是一个祖宗
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        //3、查询 某点 所在的集合大小 就是查询祖宗的cnt
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }

    return 0;
}