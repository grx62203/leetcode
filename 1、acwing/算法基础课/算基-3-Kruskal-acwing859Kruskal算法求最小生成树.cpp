/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤105
1≤m≤2∗105
图中涉及边的边权的绝对值均不超过 1000
*/
/*
kruskal算法求最小生成树
1、
稠密图
    邻接矩阵Dijkstra------------------------点少、边权不可以为负、---------------------------------------------
        ---一级for n-1次、二级for全部点-找t、二级for全部点-求min(d[b],d[t]+w)、二级标记遍历
    邻接矩阵Floyd---------------------------点少、边权可以为负、不能存在负权回路------------------求任意两点的最短路
        ---一级for全部途径点、二级for全部始点、三级for全部终点-求min(d[b],d[t]+w)
    自建结构体bellman-ford------------------点少、边权可以为负、可能存在负权回路-----------------求有边数限制的最短路
        ---一级for限制边-备份dist、二级for全部边-求min(d[b],d[t]+w)
    邻接矩阵Prim----------------------------点少、边权可以为负、
        ---一级for n次、二级for全部点-找t、二级判INF、二级累计边权、二级for全部点-求min(d[b],w)、二级标记遍历加入新点集
稀疏图
    邻接链表Dijkstra堆优化--------------------点多、边权不可以为负、
        ---一级点1入堆、一级while堆不空、二级取小根标记遍历、二级for小根的所有出边点-求min(d[b],d[t]+w)且入堆
    邻接链表spfa------------------------------点多、边权可以为负、不能存在负权回路------------------判断是否有负权回路
        ---一级点1入队、一级while队不空、二级取队头标记遍历、二级for队头的所有出边点-求min(d[b],d[t]+w)且入队
        ---一级点1入队、一级while队不空、二级取队头标记遍历、二级for队头的所有出边点-求min(d[b],d[t]+w)且累计边数判负环且入队
    自建结构体Kruskal-------------------------点多、边权可以为负、
        ---一级sort边权排序、一级for初始并查集、一级for全部边-判祖宗是否联通且累计边数且累计边权
2、kruskal算法求最小生成树
    初始化自建的重载了 < 的struct集合,不需要memset
    kruskal（）
		sort 按照边权从小到大排序
		for 初始化并查集，自己连自己
		记录最小生成树边权之和res 、记录当前最小生成树边数cnt
		for 遍历每一条边
			记录边的出点、入点、边权
			记录出点所在连通块的祖宗、入点所在连通块的祖宗
			if 出点祖宗 ！= 入点祖宗    将出点祖宗与入点祖宗联通+累计边权+累计边数
			~~~ p[a] = b; res += w; cnt ++ ;
		if 最小生成树边数 < n-1 （不存在最小生成树） return INF
		return 最小生成树的边权之和res
	输出res或者INF
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];//并查集数组

//重载 < 的边struct
struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

//查找x的 祖宗，也就是x所在的最大树的根节点
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
	//sort 按照边权从小到大排序
    sort(edges, edges + m);
    //for 初始化并查集，自己连自己
    for (int i = 1; i <= n; i ++ ) p[i] = i;    
    //记录最小生成树边权之和res 、记录当前最小生成树边数cnt
    int res = 0, cnt = 0;
	//for 遍历每一条边
    for (int i = 0; i < m; i ++ )
    {
    	//记录边的出点、入点、边权
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        //记录出点所在连通块的祖宗、入点所在连通块的祖宗
        a = find(a), b = find(b);
        //if 出点祖宗 ！= 入点祖宗    将出点祖宗与入点祖宗联通+累计边权+累计边数
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }
    //if 最小生成树边数 < n-1 （不存在最小生成树） return INF
    if (cnt < n - 1) return INF;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    //初始化自建的重载了 < 的struct集合
    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    int t = kruskal();

    if (t == INF) puts("impossible");//if dist[n]没有被更新，则不存在所求最短路
    else printf("%d\n", t);

    return 0;
}