/*
n−n−皇后问题是指将 nn 个皇后放在 n×nn×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

1_597ec77c49-8-queens.png

现在给定整数 nn，请你输出所有的满足条件的棋子摆法。

输入格式
共一行，包含整数 nn。

输出格式
每个解决方案占 nn 行，每行输出一个长度为 nn 的字符串，用来表示完整的棋盘状态。

其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

注意：行末不能有多余空格。

输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围
1≤n≤9
*/
/*
n皇后问题
1、树的深度就是行数，遍历每一行放一个，以 当前行能放的位置为分支进行dfs
2、对角线和反对角线的索引要有一定的规则，这里用坐标系下直线与y轴相交的截距来表示索引、小于零的话同时加某个数n或者i
*/
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];//某一列、某条正对角线、某条反对角线 是否被填入一个数字
	
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++ ) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i ++ )
        if (!col[i] && !dg[u + i] && !udg[n - u + i])//当前列、对角线、反对角线 都没有放过，再往下走
        {
            g[u][i] = 'Q';                             //添加path
            col[i] = dg[u + i] = udg[n - u + i] = true;//标志判重
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;//恢复现场,为了同一个for起步一致
            g[u][i] = '.';                              //恢复现场,为了同一个for起步一致
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    dfs(0);

    return 0;
}