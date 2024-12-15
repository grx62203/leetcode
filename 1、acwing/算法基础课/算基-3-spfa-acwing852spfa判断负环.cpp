/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000
1≤m≤10000
图中涉及边长绝对值均不超过 10000
*/
/*
spfa求负环
1、和bellman算法一样，也是用抽屉原理求负环
2、spfa求负环
    初始化邻接链表（有了权重就要多一个数组存储边的权重）
    spfa（）
        for 遍历所有点，依次加入队列,标记存入队列
        while 队列不为空
            弹出队头t，记录当前点t编号，标记当前点不在队列
            for 遍历点t的所有出边点更新dist
                取出出边点b，更新这个点b的距离dist为  点b存储的距离dist 与 点t出发到达点b的新距离dist+w 中的 较小值
                ~~~ dist[b] = min(dist[b] ,dist[t] + w[i])
                    更新之后 更新点b到初始点最短路径的边数
                    ~~~ cnt[b] = cnt[t] + 1;
                    更新之后 if 点b到初始点的最短路径的边数 >= n---说明存在负环
                    更新之后 if 点b不在队列 ----------------------当前出边点b入队，标记入队----负环会造成出队后继续入队
    return dist[n]      
    if dist[n]没有被更新，则不存在所求最短路
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点、------表示边的权重
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int dist[N], cnt[N];//当前点到初始点的距离，第1个点的dist 为 0、当前点到初始点的最短路的边数
bool st[N];

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
    //for 遍历所有点，依次加入队列,标记存入队列
    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        st[i] = true;
        q.push(i);
    }

    //while 队列不为空
    while (q.size())
    {
        //弹出队头t，记录当前点t编号，标记当前点不在队列
        int t = q.front();
        q.pop();
        st[t] = false;

        //for 遍历点t的所有出边点更新dist
        for (int i = h[t]; i != -1; i = ne[i])
        {
            //取出出边点b
            int j = e[i];
            //更新点b的现在距离dist 与 当前标记点t的距离dist+当前标记点t出发到达这个点b的新距离w 中的 较小值
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                //更新点b到初始点最短路径的边数
                cnt[j] = cnt[t] + 1;
                //if 点b到初始点的最短路径的边数 >= n---说明存在负环
                if (cnt[j] >= n) return true;
                //if 点b不在队列 ----------------------当前出边点b入队，标记入队----负环会造成出队后继续入队
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    if (spfa()) puts("Yes");
    else puts("No");//if dist[n]没有被更新，则不存在所求最短路

    return 0;
}