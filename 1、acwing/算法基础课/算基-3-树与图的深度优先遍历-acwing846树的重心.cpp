/*
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。

接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

输出格式
输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1≤n≤105
*/
/*
树的重心
	重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。
邻接表存储
	每个节点都有一条单链表，本来表头指向 -1，当插入一个节点的时候
DFS
    可以求子树的大小

求重心
    每个节点都求一下删掉之后其他连通块的最大值，包括上面整体、以儿子为根的树s
    在这些最大值里面找最小值，就是所求重心对应的最大连通块点数
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点
//M是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int ans = N;
bool st[N];

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u)
{
    st[u] = true;//表示被搜过了

    int size = 0, sum = 0;
    for (int i = h[u]; i != -1; i = ne[i])//遍历u的所有出边
    {
        int j = e[i];       //记录此个出边对应的节点
        if (st[j]) continue;//如果搜过了，跳过

        int s = dfs(j);     //dfs一次，求得 以儿子为跟的树的大小
        size = max(size, s);//size第一次更新   以儿子为根的树的大小 的max
        sum += s;           //sum是某节点的儿子孙子们共计多少（不包括这个子节点本身）
    }

    size = max(size, n - sum - 1);//size 更新为 最大儿子树对应答案与上面整体对应答案 的 max
    //n - sum - 1是删掉某子节点后，上面一整块的联通块点数
    //size 本来存的是某节点的 以儿子为根的树的max
    ans = min(ans, size);//ans 更新 所有节点中max 的min

    return sum + 1;//返回以 u为根 的树的大小，只是dfs中间传递用
}

int main()
{
    scanf("%d", &n);

    memset(h, -1, sizeof h);//链表的初始化

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);//无向边
    }

    dfs(1);

    printf("%d\n", ans);

    return 0;
}