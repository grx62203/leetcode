/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500
1≤m≤105
图中涉及边的边权的绝对值均不超过 10000
*/
/*
prim算法求最小生成树
1、稠密图
	邻接矩阵
	dijkstra、prim
2、prim算法中的dist数组含义与dijkstra中不同，但堆优化的prim一般不用
	prim中dist是结点到当前生成树点集的距离，而dijkstra算法中d表示该结点到起点的距离。
	因此prim算法中的更新操作为d[j]=min(d[j],g[t][j])。
	这里比较的仅是d[j]和g[t][j]而不是d[j]和d[t]+g[t][j]。g[t][j]为负不会导致判断结果失效。
3、prim算法求最小生成树
    初始化邻接矩阵
    dijkstra（）
        初始化距离数组dist[]为正无穷，开始时并未选中某点，第一个点随便
        for 遍历n次
            for 遍历每个点（n次）
                if  这个点未遍历 && (这个点是第一个未被遍历的||当前存储的距离dist 小于 前面新确定的距离dist)
                    更新 若干新确定距离 里面的最小值对应的 点，得到了当前遍历的点t
            if i不是第一个点 且 点集外的点的距离没有更新（不存在最小生成树）   return INF
            if i不是第一个点（第一个点dist=0）                              累计边权到res
            for 遍历每个点（n次）
                更新这个点b的距离dist为 点b的现在距离dist 与 当前标记点t出发到达这个点b的新距离w=g[t][b] 中的 较小值
                ~~~ dist[j] = min(dist[j], g[t][j])
            标记当前点被遍历，也就是加入了当前新点集
    return 最小生成树的边权之和res
    输出res或者INF
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;//点、边
int g[N][N];//稠密图用邻接矩阵来写
int dist[N];//当前点到 当前新点集 的距离
bool st[N];//记录当前点是否被加入 当前新点集


int prim()
{
	//初始化距离数组dist[]为正无穷，开始时并未选中某点，第一个点随便
    memset(dist, 0x3f, sizeof dist);
    int res = 0;//最小生成树的边权之和

    //for 遍历n次
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;//t 用来存储当前循环内到 当前新点集  距离最短的点，第一次循环是第一个点，距离为 0 
        //for 遍历每个点（n次）
        for (int j = 1; j <= n; j ++ )
        	//if  这个点未遍历 && (这个点是第一个未被遍历的||当前存储的距离dist 小于 前面新确定的距离dist)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            	//更新 若干新确定距离 里面的最小值对应的 点，得到了当前遍历的点t
                t = j;
        //if i不是第一个点 且 点集外的点的距离没有更新（不存在最小生成树）  return INF
        if (i && dist[t] == INF) return INF;//t肯定会更新，在第一个未被遍历的点那里
        //if i不是第一个点（第一个点dist=0）                            累计边权到res
        if (i)  res += dist[t];
        //for 遍历每个点（n次）
        for (int j = 1; j <= n; j ++ ) 
        	//更新这个点b的距离dist为 点b的现在距离dist 与 当前标记点t出发到达这个点b的新距离w=g[t][b] 中的 较小值
        	dist[j] = min(dist[j], g[t][j]);
        //标记当前点被遍历，也就是加入了当前新点集
        st[t] = true;
    }
    return res;
}


int main()
{
    scanf("%d%d", &n, &m);

    //初始化邻接矩阵
    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);//多条边，保留长度最短的那条边
    }

    int t = prim();
    if (t == INF) puts("impossible");//if dist[n]没有被更新，则不存在所求最小生成树  
    else printf("%d\n", t);

    return 0;
}