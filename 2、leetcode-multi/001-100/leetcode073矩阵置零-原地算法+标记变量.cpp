/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/
/*
时间复杂度分析：矩阵中每个元素只遍历常数次数，所以时间复杂度是 (nm)
空间复杂度分析：只用了两个额外的变量记录第一行和第一列是否含有0，所以额外的空间复杂度是 (1)，满足原地算法的要求。
*/
//24ms
//一个标记变量
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        //标记第一列、标记所有位置（第一行有没有0被放在了[0,0],第一列有没有0放在了标记变量）
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        //倒序遍历所有行（所以遍历第一行的意思是第一行被[0,0]位置更新）
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0) {
                matrix[i][0] = 0;
            }
        }
    }
};

//16ms
//两个标记变量=yxc
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), m = matrix[0].size();//行、列
        int col0 = 1, row0 = 1;
        for (int i = 0; i < n; i ++ )
            if (!matrix[i][0]) col0 = 0;//第一列本来就存在0，则标志
        for (int i = 0; i < m; i ++ )
            if (!matrix[0][i]) row0 = 0;//第一行本来就存在0，则标志
        for (int i = 1; i < n; i ++ )
            for (int j = 1; j < m; j ++ )
                if (!matrix[i][j])//如果某一个位置存在0，将对应的的第几行第一个、第几列第一个都置为0，标志
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < n; i ++ )
            if (!matrix[i][0])//遍历除了第一个的第一列，标志是0，则所在行全部置零
                for (int j = 1; j < m; j ++ )
                    matrix[i][j] = 0;

        for (int i = 1; i < m; i ++ )
            if (!matrix[0][i])//遍历除了第一个的第一行，标志是0，则所在列全部置零
                for (int j = 1; j < n; j ++ )
                    matrix[j][i] = 0;

        if (!col0)//本来就有0，则第一列全部置零
            for (int i = 0; i < n; i ++ )
                matrix[i][0] = 0;

        if (!row0)//本来就有0，则第一行全部置零
            for (int i = 0; i < m; i ++ )
                matrix[0][i] = 0;
        //对于第一行的第一个，也就是第一列的第一个，没有处理
        //因为如果这个位置为0，就会包括在 本来就存在0的那两个标志里面
    }
};

//标记数组
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


