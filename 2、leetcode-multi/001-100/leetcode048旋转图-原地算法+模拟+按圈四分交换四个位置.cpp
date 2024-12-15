/*
给定一个 *n* × *n* 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在**[ 原地](https://baike.baidu.com/item/原地算法)** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。
- `matrix.length == n`
- `matrix[i].length == n`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++)//好好理解，四个数旋转，最终旋转回来，但是  //要注意旋转次数判定以及位置选取（重点）
            for(int j=i;j<n-1-i;j++){
                int tmp=matrix[i][j];
                //四次循环，每次行列交换，行变为n-1-j
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
            }
    }
};


//c++17版本
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                tie(matrix[i][j], matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]) \
                    = make_tuple(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1], matrix[i][j]);
            }
        }
    }
};



/*
两次变换的方法已经有了，这里介绍一下如果仅遍历一次数组。
将这个二维矩阵看成若干圈，每一圈都是进行一次 90 度旋转。每次旋转都是若干次 4 个数的轮换。
所以我们从最外圈开始，首先更新 (0, 0), (0, n - 1), (n - 1, n - 1), (n - 1, 0) 这 4 个数，然后更新 (0, 1), (1, n - 1), (n - 1, n - 2), (n - 2, 0)，以此类推。
然后往里走一圈，更新 (1, 1), (1, n - 2), (n - 2, n - 2), (n - 2, 1) 等等。
每次的 4 个数下标轮换的规律也很好找。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int s = n; s > 0; s -= 2) {
            for (int i = 0; i < s - 1; i++) {
                int cx = (n - s) / 2, cy = cx + i, bak = matrix[cx][cy];
                for (int k = 0; k < 3; k++) {
                    int sx = n - 1 - cy, sy = cx;
                    matrix[cx][cy] = matrix[sx][sy];
                    cx = sx;
                    cy = sy;
                }
                matrix[cx][cy] = bak;
            }
        }
    }
};


