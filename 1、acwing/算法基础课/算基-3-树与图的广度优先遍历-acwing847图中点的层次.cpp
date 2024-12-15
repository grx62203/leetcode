/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。

所有边的长度都是 1，点的编号为 1∼n

请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 nn 和 mm。

接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

数据范围
1≤n,m≤105
*/
/*
图中点的层次

所有边的权重都是 1，可以用宽搜（bfs）

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int d[N];
//d表示当前索引的点，距离第N个索引点的距离

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs()
{
    memset(d, -1, sizeof d);//每次dfs初始化d = -1

    queue<int> q;
    d[1] = 0;//定义起点到起点的距离,入队
    q.push(1);

    //队列先进先出，空结束
    while (q.size())
    {
        //取出队头，且弹出        
        int t = q.front();
        q.pop();

        //遍历当前点的所有出边
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];  //记录此个出边对应的节点
            if (d[j] == -1)//如果出边对应节点没有被遍历
            {
                d[j] = d[t] + 1;//当前出边对应点到初始点的距离等于 父亲的距离+1
                q.push(j);      //将出边对应节点加入队列
                //q[++tt] = j;  //这是从 下标1 开始
            }
        }
    }

    return d[n];//返回第n个索引的点 到 初始点的距离
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}