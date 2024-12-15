/*
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。

A 吃 B，B 吃C，C 吃 A。

现有 N 个动物，以 1∼N 编号。

每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。

有人用两种说法对这 N 个动物所构成的食物链关系进行描述：

第一种说法是 1 X Y，表示 X 和 Y 是同类。

第二种说法是 2 X Y，表示 X 吃 Y。

此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。

当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

当前的话与前面的某些真的话冲突，就是假话；
当前的话中 X 或 Y 比 N 大，就是假话；
当前的话表示 X 吃 X，就是假话。
你的任务是根据给定的 N 和 K 句话，输出假话的总数。

输入格式
第一行是两个整数 N 和 K，以一个空格分隔。

以下 K 行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中 D 表示说法的种类。

若 D=1，则表示 X 和 Y 是同类。

若 D=2，则表示 X 吃 Y。

输出格式
只有一个整数，表示假话的数目。

数据范围
1≤N≤50000
0≤K≤100000
*/
/*
并查集-按秩合并-食物链
*/
#include<iostream>
#include<cstdio>

using namespace std;

int fa[150010], hight[150010];//n存的是自己,2n存的是猎物,3n存的是天敌  猎物的猎物是天敌

int find_root(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find_root(fa[x]);//路径压缩
}
//把秩高的 作为 秩低的 的祖宗，这个集合里面就是一个同类
void merge(int x, int y)
{
    int xx = find_root(x), yy = find_root(y);
    if (xx == yy)return;
    if (hight[xx] == hight[yy])//按秩合并
    {
        hight[xx]++;
        fa[yy] = xx;
    }
    else if (hight[xx] > hight[yy])
    {
        fa[yy] = xx;
    }
    else
    {
        fa[xx] = yy;
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 3 * n; i++)
    {
        fa[i] = i;
        hight[i] = 1;
    }
    int op, x, y;
    int ans = 0;
    while (k--)
    {
        scanf("%d%d%d", &op, &x, &y);
        //1、x或y大于当前食物链 此话为假
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (op == 1)
        {
            //2.1、如果x是y的天敌或猎物此话是谎言，都是检查祖宗是否是同类
            if (find_root(x + n) == find_root(y) || find_root(x + 2 * n) == find_root(y))
            {
                ans++;
                continue;
            }
            //2.2、这是真话
            else
            {
                //将祖宗们按 类别 两两合并
                merge(x, y);                //x和y是同类
                merge(x + n, y + n);        //x的猎物和y的猎物是同类
                merge(x + 2 * n, y + 2 * n);//x的天敌和y的天敌是同类
            }
        }
        else if (op == 2)
        {
            //3.1、同类吃同类 此话为假
            if (x == y)
            {
                ans++;
                continue;
            }
            //3.2、x是y的猎物或同类 此话为假
            if (find_root(x) == find_root(y) || find_root(x + 2 * n) == find_root(y))
            {
                ans++;
                continue;
            }
            //3.3、这是真话
            else
            {
                merge(x, y + 2 * n);    //x和y的天敌是同类
                merge(x + n, y);        //x的猎物和y是同类
                merge(x + 2 * n, y + n);//x的天敌和y是同类
            }
        }
    }
    printf("%d", ans);
    return 0;
}