/*
给你一个只包含 `'('` 和 `')'` 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

- `0 <= s.length <= 3 * 104`
- `s[i]` 为 `'('` 或 `')'`
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')    left++;
            else                right++;
            
            if (left == right)      maxlength = max(maxlength, 2 * right);//每次越界的长度遍历
            else if (right > left)  left = right = 0;                     //越界了，此时右括号刚好大于左括号的数量
        }
        
        left = right = 0;
        
        for (int i = (int)s.length() - 1; i >= 0; i--) {                 //左右起，看到的越界位置不一样
            if (s[i] == '(')   left++;
            else               right++;
            if (left == right)     maxlength = max(maxlength, 2 * left);
            else if (left > right) left = right = 0;
        }
        return maxlength;
    }
};