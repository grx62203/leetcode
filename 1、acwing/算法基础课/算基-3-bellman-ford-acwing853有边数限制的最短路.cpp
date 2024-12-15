/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。

注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 kk 条边的最短距离。

如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500
1≤m≤10000
任意边长的绝对值不超过 10000
*/
/*
有边数限制的最短路
1、负权边的时候用
	但是，有负权回路的时候，一般求不出来最短路=====bellman-ford可以求负权回路，但一般不用，用其他算法
2、bellman-ford（致力于所有边满足三角不等式 dist[b] <= last[a] +w）
	for n次
		for 所有边 a，b，w
			dist[b] = min(dist[b] ,last[a] +w)   松弛操作
	备注：
	k次循环的时候，求出不超过k条边的最短路【也就是本道题所求，有限制的话，负权回路的时候也有最短路】
	n次循环的时候，还在更新的话，一定存在一条最短路径有n条边，也就是n+1个点，一定存在环，这个环一定是负环
3、求1到n的不超过k条边的最短路
	初始化新建边结构体的集合,不需要memset
	bellman_ford()
		初始化距离数组dist[] 为正无穷、初始化点1的到初始点的距离 = 0
		for 循环k次（求不超过k条边的最短路）
			备份dist数组，给last数组，所以last数组存储的是上一次循环的dist数组（防止遍历每条边的时候，用前一条边的数据，实际上应该用前一次循环的数据）
			for 遍历每条边、为m条（这里区别于dijkstra算法，dij都是遍历点为n个）
				取出这条边的结构体，出点b
				更新这个点b的距离dist为  点b的现在距离dist 与 上一次大循环时点a的距离dist+点a到点b的距离w 中的 较小值
                ~~~ dist[b] = min(dist[b] ,last[a] +w)
    return dist[n]
	if dist[n]没有被更新，则不存在所求最短路
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;//点数、边数

struct Edge
{
    int a, b, c;
}edges[M];

int n, m, k;
int dist[N];//记录当前点到初始点的距离
int last[N];//上一次循环的 dist数组的缓存

void bellman_ford()
{
    //初始化距离数组dist[] 为正无穷、初始化点1的到初始点的距离 = 0
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //for 循环k次（求不超过k条边的最短路）
    for (int i = 0; i < k; i ++ )）
    {
        //备份dist数组，给last数组，所以last数组存储的是上一次循环的dist数组（防止遍历每条边的时候，用前一条边的数据，实际上应该用前一次循环的数据）
        memcpy(last, dist, sizeof dist);
        //for 遍历每条边、为m条（这里区别于dijkstra算法，dij都是遍历点为n个）
        for (int j = 0; j < m; j ++ )
        {
            //取出这条边的结构体，出点b
            auto e = edges[j];
            //更新这个点b的距离dist为  点b的现在距离dist 与 上一次大循环时点a的距离dist+点a到点b的距离w 中的 较小值
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    //初始化新建边结构体的集合
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");//if dist[n]没有被更新，则不存在所求最短路
    else printf("%d\n", dist[n]);

    return 0;
}