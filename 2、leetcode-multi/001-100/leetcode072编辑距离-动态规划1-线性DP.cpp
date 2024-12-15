/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (!n || !m) return n + m;
        vector<vector<int>>f = vector<vector<int>>(n + 1, vector<int>(m + 1));
        f[0][0] = 0;//与0层有关的时候，只用到这一个状态
        for (int i = 1; i <= n; i ++ ) f[i][0] = i;
        for (int j = 1; j <= m; j ++ ) f[0][j] = j;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
            {
                f[i][j] = f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);//这一位相等，不操作 or 这意味不相等，替换
                f[i][j] = min(f[i][j], f[i - 1][j] + 1);//删除第i位
                f[i][j] = min(f[i][j], f[i][j - 1] + 1);//插入第j位
            }
        return f[n][m];
    }
};