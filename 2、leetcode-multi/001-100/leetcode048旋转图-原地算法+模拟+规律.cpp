/*
给定一个 *n* × *n* 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在**[ 原地](https://baike.baidu.com/item/原地算法)** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。
- `matrix.length == n`
- `matrix[i].length == n`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`
*/

/*
顺时针 90： 主对角线翻转，然后从中间水平反转
逆时针 90： 主对角线翻转，然后从中间上下翻转
顺时针180和逆时针180 都是先主对角线翻转，然后副对角线翻转
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i ++ )//主对角线对称
            for (int j = 0; j < i; j ++ )                        //枚举左下角
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; i ++ )//上下对称
            for (int j = 0, k = n - 1; j < k; j ++, k -- )      //两边向中间走，枚举v
                swap(matrix[i][j], matrix[i][k]);
    }
};