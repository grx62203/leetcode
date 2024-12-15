/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

问总共有多少条不同的路径？

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!i && !j) f[i][j] = 1;
                else {
                    if (i) f[i][j] += f[i - 1][j];
                    if (j) f[i][j] += f[i][j - 1];
                }

        return f[n - 1][m - 1];
    }
};


// 采用 滚动数组 的方式 优化空间, f(n) 初始化为 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1); // 初始化为 1

        for (int i = 1; i < m; i ++ ) // i, j 下标 从 1 开始
            for (int j = 1; j < n; j ++ )
                f[j] = f[j] + f[j - 1];//f[j]存放的是上一次的f[j],所以就可以优化
        return f[n - 1];
    }
};