/*
给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。

两个网格块属于同一 连通分量 需满足下述全部条件：

两个网格块颜色相同
在上、下、左、右任意一个方向上相邻
连通分量的边界 是指连通分量中满足下述条件之一的所有网格块：

在上、下、左、右任意一个方向上与不属于同一连通分量的网格块相邻
在网格的边界上（第一行/列或最后一行/列）
请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。
*/

class Solution {
public:
    vector<vector<int>> g;   //储存数组
    vector<vector<int>> st;  // 0未搜过  1：搜过  2：搜过且是边界
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//来自蛇形数组模型

    void dfs(int x, int y) {
        bool is_border = false;
        for (int i = 0; i < 4; i ++ ) {//枚举格子的上下左右四个方向
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == g[x][y]) {
            	//如果颜色一样，且没有遍历过，就标记搜过且dfs
                if (!st[a][b]) {
                    st[a][b] = 1;
                    dfs(a, b);
                }
            } else {//某个方向上 找不到颜色一样的邻居，那就是边界
                is_border = true;
            }
        }

        if (is_border) st[x][y] = 2;//边界更改状态
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        g = grid;
        n = g.size(), m = g[0].size();              //行数、列数
        st = vector<vector<int>>(n, vector<int>(m));//初始化st数组

        st[row][col] = 1;
        dfs(row, col);

        //将边界上色
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (st[i][j] == 2)
                    grid[i][j] = color;

        return grid;
    }
};