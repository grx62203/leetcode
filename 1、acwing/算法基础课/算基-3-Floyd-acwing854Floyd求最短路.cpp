/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。

数据保证图中不存在负权回路。

输入格式
第一行包含三个整数 n,m,k

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。

输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200
1≤k≤n2
1≤m≤20000
图中涉及边长绝对值均不超过 10000
*/
/*
Floyd求最短路
1、Floyd可以求i到j的最短距离，多初始点多终点,k表示中间点的个数，为n是结果
    d[k][i][j] = d[k-1][i][j] + d[k-1][k][j]
2、Floyd求最短路
    初始化邻接矩阵，，同时也是距离矩阵dist
        如果有多条边，就保留最小边，去重边
    floyd()
        for 遍历n次，代表途径点个数
            for 遍历n次，代表始点
                for 遍历n次，代表终点
                    更新这个点j的距离dist为  点j的现在距离dist 与 点i的距离dist+点i到点j的距离w 中的 较小值
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    ---代表从点i 只经过 1-k这些中间点 到j 的最小距离
    while  询问数Q不为0 （Q--)
        return d[a][b]
        if dist[n]没有被更新，则不存在所求最短路 
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];//稠密图用邻接矩阵来写，距离同时也在这个矩阵更新

void floyd()
{
    //从点i 只经过 1-k这些中间点 到j 的最小距离
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &Q);
    //初始化邻接矩阵，同时也是距离矩阵dist
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);//如果有多条边，就保留最小边，去重边
    }

    floyd();
    
    //while  询问数Q不为0 （Q--)
    while (Q -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        //取得d[a][b],判断是否被更新
        int t = d[a][b];
        if (t > INF / 2) puts("impossible");
        else printf("%d\n", t);
    }

    return 0;
}