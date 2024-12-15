/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n≤500
1≤m≤105
图中涉及边长均不超过10000。
*/
/*
dijkatra求最短路-1
稠密图专用，边更多---用邻接矩阵存储--重边特殊处理
1、dijkstra求最短路
    初始化邻接矩阵
    dijkstra（）
        初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离dist[1] = 0
        for 遍历n-1次
            for 遍历每个点（n次）
                if  这个点未遍历 && (这个点是第一个未被遍历的||当前存储的距离dist 小于 前面新确定的距离dist)
                    更新 若干新确定距离 里面的最小值对应的 点，得到了当前遍历的点t
            for 遍历每个点（n次）
                更新这个点b的距离dist为 这个 点b的现在距离dist 与 当前标记点t的距离dist+当前标记点t出发到达这个点b的新距离w 中的 较小值
                ~~~ dist[j] = min(dist[j], dist[t] + g[t][j])
            标记当前点被遍历
    return dist[n]
    if dist[n]没有被更新，则不存在所求最短路    
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;  //点、边
int g[N][N];//稠密图用邻接矩阵来写
int dist[N];//当前点到初始点的距离，第1个点的dist 为 0
bool st[N]; //记录当前 点是否被主要遍历过，找到了当前点到初始点的最短距离，确定距离的点为 1=真

int dijkstra()
{
    //初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离 = 0
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //for 遍历 n - 1 次
    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;//t 用来存储当前循环内到 初始点 距离最短的点，第一次循环是第一个点，距离为 0 
        //for 遍历每个点（n次）
        for (int j = 1; j <= n; j ++ )
            //if  这个点未遍历 && (这个点是第一个未被遍历的||当前存储的距离dist 小于 前面新确定的距离dist)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))//求得的肯定是从已经标记过的点出发能到达的最小距离的点，如果到不了，那这个距离=03xf
                //更新 若干新确定距离 里面的最小值对应的 点，得到了当前遍历的点t
                t = j;                                  
        //for 遍历每个点（n次）
        for (int j = 1; j <= n; j ++ )
            //更新这个点b的距离dist为  点b的现在距离dist 与 当前标记点t的距离dist+点t到点b的距离w 中的 较小值
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        //标记当前点被遍历
        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;//if dist[n]没有被更新，则不存在所求最短路
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    //初始化邻接矩阵
    memset(g, 0x3f, sizeof g);//初始化为  正无穷0x3f3f3f，这是邻接矩阵的初始化，和邻接表的不一样(=-1)
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);//多条边，保留长度最短的那条边
    }

    printf("%d\n", dijkstra());

    return 0;
}