/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。

请你判断这个图是否是二分图。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

输出格式
如果给定图是二分图，则输出 Yes，否则输出 No。

数据范围
1≤n,m≤105
*/
/*
染色法判定二分图
    将所有点分成两个集合，使得所有边只出现在集合之间，就是二分图
    二分图：一定不含有奇数环，可能包含长度为偶数的环， 不一定是连通图
1、没环一定是二分图，有奇数环一定不是二分图
2、染色法判定二分图
	初始化邻接链表
	立flag表示染色是否有矛盾发生
	for 遍历所有的节点的单链表
		if 当前点t没有染过色------------判断点t的dfs返回是否有错
			if t的dfs(t,1)返回有错     标记染色失败
	输出判断结果
3、dfs()
	记录当前点t的颜色
	for 遍历当前点t对应的单链表，也就是遍历所有出边的出点
		记录 出点b的编号
		if 出点b 并未染过颜色----------------------判断出点b的dfs另一个颜色返回是否有错
			if 出点b的dfs(b,3-c)返回有错           return false
		else if 出点b染过同样的颜色                return false   
	return true
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点、------表示边的权重
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int color[N];//记录当前点的染色情况，用两个颜色染 1、2

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//判断当前点开始能不能染色成功（部分点）
bool dfs(int u, int c)
{
	//记录当前点t的颜色
    color[u] = c;
    //for 遍历当前点t对应的单链表，也就是遍历所有出边的出点
    for (int i = h[u]; i != -1; i = ne[i])
    {
    	//记录 出点b的编号
        int j = e[i];
        //if 出点b 并未染过颜色----------------------判断出点b的dfs返回是否有错
        if (!color[j])
        {
        	//if 出点b的dfs(b,3-c)返回有错----------return false
            if (!dfs(j, 3 - c)) return false;
        }
        //else if 出点b染过同样的颜色 ---------------return false   
        else if (color[j] == c) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    //初始化邻接链表
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    //立flag表示染色是否有矛盾发生
    bool flag = true;
    //for 遍历所有的节点的单链表
    for (int i = 1; i <= n; i ++ )
    	//if 当前点t没有染过色  判断点t的dfs返回是否有错
        if (!color[i])
        {
        	//if t的dfs返回有错-----标记染色失败
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }

    //输出判断结果
    if (flag) puts("Yes");
    else puts("No");

    return 0;
}