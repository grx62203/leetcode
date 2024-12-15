/*
地上有一个 m 行和 n 列的方格，横纵坐标范围分别是 0∼m−1 和 0∼n−1。

一个机器人从坐标 (0,0) 的格子开始移动，每一次只能向左，右，上，下四个方向移动一格。

但是不能进入行坐标和列坐标的数位之和大于 k 的格子。

请问该机器人能够达到多少个格子？

注意:

0<=m<=50
0<=n<=50
0<=k<=100
*/  

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> vis(rows, vector<bool>(cols));
        return dfs(threshold, 0, 0, vis);
    }
    int dfs(int th, int i, int j, vector<vector<bool>> &vis){
        if(i < 0 || i >=vis.size() || j < 0 || j >= vis[i].size() || vis[i][j] ||(i/10+i%10+j/10+j%10)>th) return 0;
        vis[i][j]=true;
        return dfs(th,i+1, j, vis)+dfs(th,i-1, j, vis)+dfs(th,i, j-1, vis)+dfs(th,i, j+1, vis) + 1;
    }
};


//wwb
class Solution {
public:
    bool st[110][110];
    bool check(int x, int y, int threshold)
    {
        int res = 0;
        while(x)
        {
            res += x % 10;
            x /= 10;
        }

        while(y)
        {
            res += y % 10;
            y /= 10;
        }
        return res <= threshold;
    }
    int dfs(int x, int y, int threshold, int rows, int cols)
    {
        int res = 1;
        st[x][y] = true;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= rows || yy < 0 || yy >= cols)   continue;
            if (!check(xx, yy, threshold))                      continue;
            if (st[xx][yy])                                     continue;

            res += dfs(xx, yy, threshold, rows, cols);
        }
        return res;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        memset(st, 0, sizeof st);
        if (rows <= 0 || cols <= 0)  return 0;
        return dfs(0, 0, threshold, rows, cols);
    }
};