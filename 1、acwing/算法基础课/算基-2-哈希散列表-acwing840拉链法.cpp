/*
维护一个集合，支持如下几种操作：

I x，插入一个数 xx；
Q x，询问数 xx 是否在集合中出现过；
现在要进行 NN 次操作，对于每个询问操作输出对应的结果。

输入格式
第一行包含整数 NN，表示操作数量。

接下来 NN 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。

输出格式
对于每个询问指令 Q x，输出一个询问结果，如果 xx 在集合中出现过，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤N≤1051≤N≤105
−109≤x≤109
*/
/*
哈希散列表拉链法
*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;//e存储链表的值、ne存储链表的下一个，多条单链表在一起表示
//h包含一个个槽、存储的值或者链表的头节点
//每个槽对应一个哈希值 k

//插入到哈希值k对应的单链表的表头
void insert(int x)
{
    int k = (x % N + N) % N;//计算哈希值
    //头插法，每次更新单链表的第一个节点、每次更新 h 上的槽为单链表的新的第一个节点的索引
    e[idx] = x;
    ne[idx] = h[k];//把原来 k链表存储的链表头放到了 新的链表头的next里面
    h[k] = idx ++ ;
}
//在哈希值k对应的单链表里面找
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])//在k对应的槽内遍历单链表，从第一个节点的索引开始
        if (e[i] == x)   return true;

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);//1、插入一个值
        else                      //2、寻找一个值
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}