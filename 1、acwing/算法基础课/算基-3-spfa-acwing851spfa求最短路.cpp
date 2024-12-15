/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。

数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤105
图中涉及边长绝对值均不超过 10000
*/
/*
spfa求最短路
1、其实是bellman-ford做的优化，也可以处理负权边,但是容易被网格化的图卡
	bellman遍历所有边 的优化
	-----只有dist[a],变小，dist[b]才会变小
	-----while 队列不空（用队列来存储所有变小了的节点，再更新对应出边）
	---------for 取（弹出）队头点t，更新点t的所有出边----> dist[b] = dist[a] +w；if 当前出边点此时不在队列中，加入队列
2、类似于堆优化的dijkstra算法，也用邻接链表存储
3、spfa求最短路
    初始化邻接链表（有了权重就要多一个数组存储边的权重）
    spfa（）
        初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离 = 0
        将点1加入队列（先进先出）,标记存入队列
        while 队列不为空
            弹出队头t，记录当前点t编号，标记当前点不在队列
			for 遍历点t的所有出边点更新dist
				取出出边点b，更新这个点b的距离dist为 与 当前标记点t的距离dist+当前标记点t出发到达这个点b的新距离w 中的 较小值
                ~~~ dist[b] = min(dist[b] ,dist[t] + w[i])
				    更新之后 if 当前出边点b不在队列----当前出边点b入队，标记入队
	return dist[n]		
	if dist[n]没有被更新，则不存在所求最短路
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点、------表示边的权重
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int dist[N];//当前点到初始点的距离，第1个点的dist 为 0
bool st[N];//记录当前点是否在队列当中

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa()
{
    //初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离 = 0
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //将点1加入队列（先进先出）,标记存入队列
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())//
    {
        //弹出队头t，记录当前点t编号，标记当前点不在队列
        int t = q.front();
        q.pop();
        st[t] = false;
        
        //for 遍历点t的所有出边点更新dist
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            //更新点b的现在距离dist 与 当前标记点t的距离dist+当前标记点t出发到达这个点b的新距离w 中的 较小值
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                //if 当前出边点b不在队列 ----当前出边点b入队，标记入队
                if (!st[j])//
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    //初始化邻接链表（有了权重就要多一个数组存储边的权重）
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int t = spfa();

    if (t == 0x3f3f3f3f) puts("impossible");//如果dist[n]没有被更新，则不存在所求最短路
    else printf("%d\n", t);

    return 0;
}