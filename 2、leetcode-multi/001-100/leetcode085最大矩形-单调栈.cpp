/*
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/
//52ms
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; i ++ ) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i -- ) {
            while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            res = max(res, h[i] * (right[i] - left[i] - 1));
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();//行数、列数

        //重写数组，每一行的数字表示当前位置开始向上连续1的长度
        vector<vector<int>> h(n, vector<int>(m));
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) {
                if (matrix[i][j] == '1') {
                    //叠加上一行的连续1的长度，看作当前行柱状图的高度
                    if (i) h[i][j] = 1 + h[i - 1][j];
                    else h[i][j] = 1;
                }
            }

        int res = 0;
        //计算每一行看到的的柱状图最大矩形，再求最大值，传入的是某一行的高度数组
        for (int i = 0; i < n; i ++ ) res = max(res, largestRectangleArea(h[i]));

        return res;
    }
};
