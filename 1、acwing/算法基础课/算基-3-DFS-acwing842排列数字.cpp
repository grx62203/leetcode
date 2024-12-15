/*
给定一个整数 nn，将数字 1∼n1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 nn。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7
*/
/*
排列数字
1、枚举每个位置放那个数字
    以 数字的遍历for来进行数的分支
2、要么dfs的下一行回溯，要么dfs的参数进行修改当前状态，避免回溯

3、用state 来压缩存储哪些数字被用过
    !(state >> i & 1)
    if判别用---state的第i位如果为1，代表被用过， & 之后变成了1，！1 的结果就是假，跳过当前数字
    state + (1 << i)
    dfs参数用---进入对应的dfs的时候，将本次i代表的数字状态改变，只有从当前i进入的dfs就默认当前i被遍历了
                不影响其他i时候对应的状态表示，避免回溯
*/
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]);
        puts("");

        return;
    }

    for (int i = 0; i < n; i ++ )
        if (!(state >> i & 1))//二进制  1表示数字被用过
        {
            path[u] = i + 1;             //将位置u，填充好对应数字，数字从1-n
            dfs(u + 1, state + (1 << i));//二进制，当前i对应的深层dfs才状态表示改变、避免回溯
        }
}

int main()
{
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}