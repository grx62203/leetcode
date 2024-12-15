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
1、原始枚举方法-按格子枚举
    两种选择【放】【不放】
2、选择不放dfs，选择放需要判别，为什么都要进行？？？
    不放格子当前状态需要dfs，能不能放格子才是分支
*/
#include <iostream>

using namespace std;

const int N = 10;

int n;
bool row[N], col[N], dg[N * 2], udg[N * 2];
char g[N][N];

void dfs(int x, int y, int s)
{
    if (s > n) return;
    if (y == n) y = 0, x ++ ;//换行格子
    if (x == n)//最后一行
    {
        if (s == n)//只有到了最后一行才会枚举结束，有path
        {
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");
        }
        return;
    }
    //不放的话递归下一个格子
    g[x][y] = '.';
    dfs(x, y + 1, s);
    //放的话先判别
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';                                      //添加path
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;//标志判重
        dfs(x, y + 1, s + 1);                               //递归下一个格子，且s+1
        g[x][y] = '.';                                       //恢复现场
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;//恢复现场
    }
}

int main()
{
    cin >> n;

    dfs(0, 0, 0);

    return 0;
}