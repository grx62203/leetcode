/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×105
图中涉及边长均不小于 0，且不超过 10000
数据保证：如果最短路存在，则最短路的长度不超过 109
*/
/*
dijkatra求最短路-2---堆优化版本
非稠密图专用，边更多---用邻接表存储--重边不用特殊处理
1、数据更大堆优化
    手写堆--可以修改任意元素
    优先队列（默认大根堆）---不支持任何一个元素，冗余
2、dijkstra求最短路
    初始化邻接链表（有了权重就要多一个数组存储边的权重）
    堆优化dijkstra（）
        初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离 = 0
        将点1加入小根堆（用距离来建立的）
        while 小根堆不为空
            弹出堆中距离最小的点t，记录当前点t的距离、编号
            if 当前点t被标记遍历，则当前点t是冗余备份，continue
            标记当前点t被遍历
            for 遍历点t的所有出边点b，更新dist
                更新这个点b的距离dist为  点b的现在距离dist 与 当前标记点t的距离dist+点t到点b的距离w 中的 较小值
                ~~~ dist[b] = min(dist[b] ,dist[t] + w[i])
                点b入堆，可以作为入点去遍历出边
    return dist[n]
    if dist[n]没有被更新，则不存在所求最短路    
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;//堆里面的数据<到初始点的距离， 第几个点>

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点、------表示边的权重
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int dist[N];//当前点到初始点的距离，第1个点的dist 为 0
bool st[N]; //记录当前 点是否作为 边的入点遍历过，找到了当前点到初始点的最短距离，确定距离的点为真

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ , w[idx] = c;
}

int dijkstra()
{
    //初始化距离数组dist[]为正无穷、初始化点1的到初始点的距离 = 0
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //将点1加入小根堆（用距离来建立的）
    priority_queue<PII, vector<PII>, greater<PII>> heap;//实例一个小根堆
    heap.push({0, 1});//

    //while 小根堆不为空
    while (heap.size())
    {
        //弹出堆中距离最小的点t，记录当前点t的距离、编号
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;//当前点的编号、距离
        //if 当前点t被标记遍历，则当前点t是冗余备份，continue
        if (st[ver]) continue;
        //标记当前点t被遍历
        st[ver] = true;      

        //for 遍历点t的所有出边点b更新dist
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];//记录当前的节点编号（邻接链表的内容就是图中点的编号，边的权重另存）
            //更新这个点b的距离dist为  点b存储的距离dist 与 点t出发到达点b的新距离dist+w 中的 较小值，入堆
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];//更新存储的距离
                heap.push({dist[j], j});   //入堆
            }
        }
    }
        
    if (dist[n] == 0x3f3f3f3f) return -1;//if dist[n]没有被更新，则不存在所求最短路
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    //初始化邻接表
    memset(h, -1, sizeof h);//邻接表的初始化和邻接矩阵的不一样
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);//插入边以及权重
    }

    cout << dijkstra() << endl;

    return 0;
}