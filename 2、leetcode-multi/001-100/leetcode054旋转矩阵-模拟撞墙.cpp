//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(!n) return res;
        int m = matrix[0].size();
        //行、                     列
        int da[] = {0, 1, 0, -1}, db[] = {1, 0, -1, 0};
        vector<vector<bool>> st(n, vector<bool>(m));

        for(int i = 0, x = 0, y = 0, d = 0; i < n * m; i++){
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            //行、              列
            int a = x + da[d], b = y + db[d];
            //验证是否撞墙（true的位置变为新墙）
            if(a < 0 || a >= n || b < 0 || b >= m ||st[a][b]){
                d = (d + 1) % 4;             //d改变就是变换前进方向
                a = x + da[d], b = y + db[d];//重新行、列得到新位置
            }
            x = a, y = b;                    //保存位置给下一次使用
        }
        return res;

    }
};