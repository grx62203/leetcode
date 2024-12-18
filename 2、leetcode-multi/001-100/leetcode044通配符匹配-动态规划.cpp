/*
给定一个字符串 (`s`) 和一个字符模式 (`p`) ，实现一个支持 `'?'` 和 `'*'` 的通配符匹配。

```
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
```

两个字符串**完全匹配**才算匹配成功。

**说明:**

- `s` 可能为空，且只包含从 `a-z` 的小写字母。
- `p` 可能为空，且只包含从 `a-z` 的小写字母，以及字符 `?` 和 `*`。

**示例 1:**

```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```
*/

//这道题与Q10的区别是，这道题的* 不需要代表[若干个前一个字符]，而是代表[若干个任意字符串]
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;//DP问题 下标从 1 开始
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));//初始化状态数组
        f[0][0] = true;

        for (int i = 0; i <= n; i ++ )//第一个字符串可以从 0 开始，f（0，j）可能是合法的
            for (int j = 1; j <= m; j ++ ) {//j从0开始没有意义
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];

                } else {
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
                }
            }

        return f[n][m];
    }
};