/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。
*/
//4ms
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        if (!n) return 0;
        int m = o[0].size();

        vector<vector<int>> f(n, vector<int>(m));//默认都是0
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!o[i][j]) {//多出来的一个障碍判断
                    if (!i && !j) f[i][j] = 1;
                    else {
                        if (i) f[i][j] += f[i - 1][j];
                        if (j) f[i][j] += f[i][j - 1];
                    }
                }

        return f[n - 1][m - 1];
    }
};




// 采用 滚动数组 的方式 优化空间, f(n) 初始化为 1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);                       //累加从这里开始，只有这里的初始值是1或者0，然后默认第一列的每一个都是1或者0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {                  //为了下一行同一列的累加，做一个清空动作，不然第二行的可以到达，第三行的有障碍，第四行的就必须清空为0
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)  //如果当前行前一个没有障碍，且避开第一列的，就累加
                    f[j] += f[j - 1];
            }
        }
        return f.back();
    }
};