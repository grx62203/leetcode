/*
给你一个只包含 `'('` 和 `')'` 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

- `0 <= s.length <= 3 * 104`
- `s[i]` 为 `'('` 或 `')'`
*/


/*
序列分为若干段
当右括号数量第一次 大于 左括号数量的时候，会出现一条分割线（当前右括号），任何合法的有效序列不会跨越这条线
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;

        int res = 0;
        for (int i = 0, start = -1; i < s.size(); i ++ ) {
            if (s[i] == '(')   stk.push(i);  //如果是 左， 入栈
            else {                           //如果是 右 ，匹配或者成为分界线
				//栈里面有就是肯定能匹配一个左括号，判断是否结束合法串，如果 ，没结束，更新res，如果结束，也更新res
                if (stk.size()) { 
                    stk.pop();
                    if (stk.size())   res = max(res, i - stk.top());
                    else              res = max(res, i - start);//此时的start也是一个假的变化的top
                } 
                //栈里面没有就代表到了分界线了，用多余的这个右括号的位置作分界线，也相当于每一个合法区间的前一个
                else   start = i; 
            }
        }
        return res;
    }
};


//如果右括号大于左括号，将多的右括号其入栈（等同于一直更新的分界线=合法区间的前一个），作为栈顶，但是一直不能弹出，意味着max从这里开始
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};