/*
在一个 m×n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。

你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格直到到达棋盘的右下角。

给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？

注意：

m,n>0
m×n≤1350
样例：
输入：
[
  [2,3,1],
  [1,7,1],
  [4,6,1]
]

输出：19

解释：沿着路径 2→3→7→6→1 可以得到拿到最大价值礼物。
*/

//dfs复杂度是指数级，超时
class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];

        return f[n][m];
    }
};


//
int getMaxValue(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int n= grid.size(),m = grid[0].size();
    int dp[n+1][m+1];
    dp[0][0] = grid[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i=1;i<m;i++){
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    //区别于y总的，这个将边界提前处理 f[i][0]、f[0][i]
    for (int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];

        }
    }
    return dp[n-1][m-1];
}

//leetcode
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector< vector<int> > dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};