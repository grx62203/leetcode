/*
给你一个只包含 `'('` 和 `')'` 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

- `0 <= s.length <= 3 * 104`
- `s[i]` 为 `'('` 或 `')'`
*/

//看不懂
//看懂了2022.02.22
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);//表示包括当前i的   最长有效前缀串 
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') 
                	//当前有效括号 + （如果 当前有效括号对 前面还有2个以上？有效括号前一个的dp ：0）
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')//从i往前走了有效长度，然后前一个存在且为"("
                 	//当前有效括号+可走有效长度+（如果 当前有效括号对 前面还有2个以上？有效括号前一个的dp ：0）                	
                    dp[i] = 2 + dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};