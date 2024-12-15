/*
给定一个 nn 个点 mm 条边的有向图，点的编号是 11 到 nn，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1−1。

若一个由图中所有点构成的序列 AA 满足：对于图中的每条边 (x,y)(x,y)，xx 在 AA 中都出现在 yy 之前，则称 AA 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 nn 和 mm。

接下来 mm 行，每行包含两个整数 xx 和 yy，表示存在一条从点 xx 到点 yy 的有向边 (x,y)(x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1−1。

数据范围
1≤n,m≤105
*/
/*
有向图的拓扑序列
    有环不行、每条有向边的前点一定在后点之前（拓扑序列里）
    有向无环图一定有拓扑序列，也被称为拓扑图
        所以这个题就是判断有没有环？
    入度为0的点可以作为起点、出度为0的点可以作为终点
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int d[N];//存储入度
int q[N];//存储拓扑序列

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort()
{
    //自建队列，并没有弹出队头，如果用queue的话，得重开数组记录答案    
    int hh = 0, tt = -1;


    //所有入度=0的点插入队列
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    //队列不空
    while (hh <= tt)
    {
        int t = q[hh ++ ];//取出队头元素

        //遍历当前点的所有出边
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];    //记录此个出边对应的节点
            //入度--，之后入度=0 的话，入队, 可以作为一个新的入点来遍历出边
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    return tt == n - 1;//判断所有元素是否入队了，则拓扑序列成功了
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

        d[b] ++ ;//记录每个点的入度
    }

    if (!topsort()) puts("-1");
    else
    {
        for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
        puts("");
    }

    return 0;
}