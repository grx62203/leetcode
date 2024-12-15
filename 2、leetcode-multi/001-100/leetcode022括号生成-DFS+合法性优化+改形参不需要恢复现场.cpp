/*
数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

有效括号组合需满足：左括号必须以正确的顺序闭合。

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/


//任意前缀中，左括号大于右括号数量
//左右括号数量相等
//合法的两个条件

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) ans.push_back(seq);
        //结束条件
        else {
            if (lc < n) dfs(n, lc + 1, rc, seq + '(');
            //添加左括号条件
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ')');
            //添加右括号条件
        }
    }
};