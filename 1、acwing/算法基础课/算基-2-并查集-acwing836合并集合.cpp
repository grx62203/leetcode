/*
一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。

现在要进行 m 个操作，操作共有两种：

M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；
输入格式
第一行输入整数 n 和 m。

接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。

输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤n,m≤105
*/

/*
并查集-合并集合
合并集合、查询两个是否同一集合
1、树根的父节点就是本身
2、每个集合的编号就是树根的编号
3、合并两个集合就是 p[x]=y
*/
#include <iostream>

using namespace std;

const int N = 100010;

int p[N];//存储着N的父节点，树根的父节点就是自身，
//返回x的祖宗节点+压缩路径
int find(int x)
{
    //从x往上溯祖的过程将找到的每一个节点的父节点都 更新为 祖宗节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    //初始，每个元素都是一个集合，也就是都是树根
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') p[find(a)] = find(b);//合并两个集合
        else
        {
            //判别两个点是否在一个集合就是判别是不是一个祖宗
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}