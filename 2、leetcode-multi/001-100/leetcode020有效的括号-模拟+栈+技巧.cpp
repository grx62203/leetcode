/*
给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

输入：s = "()[]{}"
输出：true

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成
*/

class Solution {
       public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
//            如果是半边的括号就放进去等待匹配
//            放进对应的右半边括号是为了简化匹配,这样匹配的时候直接判断是不是相等就好了,节省时间
            if (c == '(') stack.push(')');
            if (c == '[') stack.push(']');
            if (c == '{') stack.push('}');
//            如果是半边的括号就放进去等待匹配
            
            if (c == ')' || c == ']' || c == '}') {
//               右括号放进去就开始匹配 一旦匹配失败就失败喽
//                stack.isEmpty()的时候加入右括号,肯定不能自己匹配(左边什么都没有),就失败了
                if (stack.isEmpty()||c != stack.pop()) return false;
            }
        }
        return stack.isEmpty();
    }
};
