/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。
*/
//4ms

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (s3.size() != n + m) return false;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        //遍历s1的长度
        for (int i = 0; i <= n; i ++ )
            //遍历s2的长度
            for (int j = 0; j <= m; j ++ )
                //边界-如果都为空，为true
                if (!i && !j) f[i][j] = true;
                else {
                    if (i && s1[i] == s3[i + j]) f[i][j] = f[i - 1][j];
                    //如果f[i][j]已经被s1匹配为真 ,f[i][j] 还是为真
                    //如果f[i][j]即将被s2匹配为真 ,f[i][j] 还是为真
                    if (j && s2[j] == s3[i + j]) f[i][j] = f[i][j] || f[i][j - 1];
                }

        return f[n][m];
    }
};




//一维优化，要么f[j]一直被覆盖，要么一直被使用
//f[j]也就是f[i-1][j]
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int> (s2.size() + 1, false);
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t)      return false;
        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0)         f[j] = f[j] & (s1[i - 1] == s3[p]);               //第二个f[j]是f[i-1][j]
                if (j > 0)         f[j] = f[j] | (f[j - 1] && s2[j - 1] == s3[p]);   //第二个f[j]是f[i][j]
            }
        }
        return f[m];
    }
};
