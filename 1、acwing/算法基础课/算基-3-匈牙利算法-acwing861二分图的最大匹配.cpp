/*
给定一个二分图，其中左半部包含 n1 个点（编号 1∼n1），右半部包含 n2 个点（编号 1∼n2），二分图共包含 m 条边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

二分图的匹配：给定一个二分图 G，在 G 的一个子图 M 中，MM 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。

二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。

输入格式
第一行包含三个整数 n1、 n2 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。

输出格式
输出一个整数，表示二分图的最大匹配数。

数据范围
1≤n1,n2≤500
1≤u≤n1
1≤v≤n2
1≤m≤105
*/
/*
匈牙利算法求二分图的最大匹配
也就是 返回两个集合之间的连线最大数量，相当于男女匹配，得到的最多一夫一妻制的对儿
1、匈牙利算法
	看第一个男生，这个男生看上的第一个姑娘单身，那就配对
	看第二个男生，这个男生A看上的唯一一个姑娘B已经配对了，
		那就判断这个姑娘B的男朋友C能不能换一个女朋友D，如果能换，皆大欢喜，直到某一个人没法换对象，第二个男生才罢休

2.1、匈牙利算法求二分图的最大匹配
	初始化邻接链表
		枚举左边集合，就需要存储左点指向右点
	立res 记录匹配线的数量
	for 遍历左图，枚举所有左点
		每次换一个左点找匹配的时候都清空右点的匹配情况
		if 当前左点t 能够找到右点匹配（find返回true）  匹配线++
	输出结果
2.2判断一个左点t能否一直通过排挤情敌找到唯一一个右点匹配
	find（）
		for 遍历当前点t的单链表，枚举当前点t的对应的出边出点
			记录出点b的编号
			if 出点b 在这一轮大循环中没有被选择过
				标记点b被选择过，但不一定匹配
				if  出点b没有相匹配的左点 || 出点b匹配的左点能够再找到新的匹配的右点
					记录当前点t与当前出点b 相匹配，存match
					return true
		没有匹配  return false

3.1、匈牙利算法求男女生间的最大姻缘
	初始化邻接链表
		枚举男人，就需要存储男人指向女人
	立res 记录1v1对象的数量
	for 遍历男人们，枚举所有男人
		每次换一个男人找对象的时候都清空女人们的匹配情况
		if 当前男人t 能够不拆人姻缘找到一个女人匹配（find返回true）  对象数++
	输出结果
3.2判断一个男人t能否一直通过【排挤情敌、不拆姻缘】找到唯一一个女人匹配
	find（）
		for 枚举当前男人t的喜欢的所有女人
			记录当前女人b的编号
			if 女人b 在这一轮大循环中没有被选择过
				标记女人b被选择过，但不一定是有对象
				if  女人b还没有对象 || 女人b的对象能够find一个新的对象
					记录当前男人t与当前女人b 相匹配，存match
					return true
		没有配对  return false
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;//二分图的数量左n1、右n2（n1个男人，n2个女人）
int h[N], e[M], ne[M], idx;
//每个链表头（里面存储的是当前单链的第一个节点）、每个节点的值、每个节点的指针、idx表示用到了哪个节点、------表示边的权重
//N是节点的索引，ne也是节点的索引，e是节点的内容（名字）
int match[N];//记录右边点 对应的 左边点  （记录女人的唯一男人，可以更改）
bool st[N];//记录右边点 当前循环是否被选择！=匹配（每一个男人找女人的循环中，每个女人只被选择一次）

//邻接表模板
//插入一条边（双向图需要插两次），将b放到a单链表的第一个位置，更新链表头的指向
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//判断一个左点t能否一直通过排挤情敌找到唯一一个右点匹配
bool find(int x)
{
	//for 遍历当前点t的单链表，枚举当前点t的对应的出边出点
    for (int i = h[x]; i != -1; i = ne[i])
    {
    	//记录出点b的编号
        int j = e[i];
        //if 出点b 在这一轮大循环中没有被选择过
        if (!st[j])
        {
        	//标记点b被选择过，但不一定匹配
            st[j] = true;
            //if 出点b没有相匹配的左点||出点b匹配的左点能够再找到新的匹配的右点
            if (match[j] == 0 || find(match[j]))
            {
            	//记录当前点t与当前出点b 相匹配，存match   
                match[j] = x;
                return true;
            }
        }
    }
    //没有匹配  return false
    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    //初始化邻接链表
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);//枚举左边集合，就需要存储左点指向右点
    }

    //立res 记录匹配线的数量
    int res = 0;
    //for 遍历左图，枚举所有左点
    for (int i = 1; i <= n1; i ++ )
    {
    	//每次换一个左点找匹配的时候都清空右点的匹配情况
        memset(st, false, sizeof st);
        //if 当前左点t 能够找到右点匹配（find返回true）  匹配线++
        if (find(i)) res ++ ;
    }
    //输出结果
    printf("%d\n", res);

    return 0;
}